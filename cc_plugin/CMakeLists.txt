set (ALL_MESSAGES_LIB "all_messages")

######################################################################

function (cc_plugin_all_messages)
    set (name "${ALL_MESSAGES_LIB}")
    set (src
        field/BinData.cpp
        field/Length.cpp
        field/MsgId.cpp
        field/PacketId.cpp
        field/ProtocolName.cpp
        field/Qos.cpp
        field/String.cpp
        field/Topic.cpp
        Message.cpp
        message/Connack.cpp
        message/Connect.cpp
        message/Disconnect.cpp
        message/Pingreq.cpp
        message/Pingresp.cpp
        message/Puback.cpp
        message/Pubcomp.cpp
        message/Publish.cpp
        message/Pubrec.cpp
        message/Pubrel.cpp
        message/Suback.cpp
        message/Subscribe.cpp
        message/Unsuback.cpp
        message/Unsubscribe.cpp
        frame/FrameTransportMessage.cpp
    )

    add_library (${name} STATIC ${src})
    target_link_libraries (${name} PUBLIC mqtt311 cc::comms cc::comms_champion Qt5::Widgets Qt5::Core)
    target_include_directories (${name} PUBLIC ${PROJECT_SOURCE_DIR})
    if (CC_COMMS_CHAMPION_FOUND)
        if (CC_PLUGIN_DIR)
            file (RELATIVE_PATH rel_plugin_install_path "${CC_ROOT_DIR}" "${CC_PLUGIN_DIR}")
            set (PLUGIN_INSTALL_DIR "${rel_plugin_install_path}")
        endif()
    endif ()

    if (TARGET ${CC_EXTERNAL_TGT})
        add_dependencies(${name} ${CC_EXTERNAL_TGT})
    endif ()
endfunction()

######################################################################

function (cc_plugin protocol has_config_widget)
    set (name "cc_plugin_${protocol}")

    set (meta_file "${CMAKE_CURRENT_SOURCE_DIR}/${protocol}.json")
    set (stamp_file "${CMAKE_CURRENT_BINARY_DIR}/${protocol}_refresh_stamp.txt")

    if ((NOT EXISTS ${stamp_file}) OR (${meta_file} IS_NEWER_THAN ${stamp_file}))
        execute_process(
            COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_SOURCE_DIR}/plugin/${protocol}Plugin.h)

        execute_process(
            COMMAND ${CMAKE_COMMAND} -E touch ${stamp_file})
    endif ()

    set (src
        plugin/${protocol}Protocol.cpp
        plugin/${protocol}Plugin.cpp
    )

    set (hdr
        plugin/${protocol}Plugin.h
    )

    if (has_config_widget)
        list (APPEND src plugin/${protocol}ConfigWidget.cpp)
        list (APPEND hdr plugin/${protocol}ConfigWidget.h)
    endif ()

    qt5_wrap_cpp(moc ${hdr})

    set(extra_link_opts)
    if (CMAKE_COMPILER_IS_GNUCC)
        set(extra_link_opts "-Wl,--no-undefined")
    endif ()

    add_library (${name} MODULE ${src} ${moc})
    target_link_libraries (${name} ${ALL_MESSAGES_LIB} cc::comms_champion Qt5::Widgets Qt5::Core ${extra_link_opts})
    target_compile_options(${name} PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/bigobj>
        $<$<CXX_COMPILER_ID:GNU>:-ftemplate-depth=2048>
        $<$<CXX_COMPILER_ID:Clang>:-ftemplate-depth=2048>
    )

    install (
        TARGETS ${name}
        DESTINATION ${PLUGIN_INSTALL_DIR})

    install (
        FILES plugin/${protocol}.cfg
        DESTINATION ${CONFIG_INSTALL_DIR})

endfunction()

######################################################################

if (NOT Qt5Core_FOUND)
    message (WARNING "Can NOT compile protocol plugin due to missing QT5 Core library")
    return ()
endif ()

if (NOT Qt5Widgets_FOUND)
    message (WARNING "Can NOT compile protocol plugin due to missing QT5 Widgets library")
    return ()
endif ()

if (TARGET cc::comms_champion)
    get_target_property(cc_inc cc::comms_champion INTERFACE_INCLUDE_DIRECTORIES)

    if (NOT cc_inc)
        message (FATAL_ERROR "No include directories are specified for cc::comms_champion")
    endif ()

    # Global include is required for "moc"
    include_directories (${cc_inc})
endif ()

cc_plugin_all_messages()

cc_plugin ("Mqtt311" FALSE)

if (TARGET ${CC_EXTERNAL_TGT})
    install (
        FILES plugin/Mqtt311.cfg
        DESTINATION ${CONFIG_INSTALL_DIR}
        RENAME "default.cfg")
endif()


