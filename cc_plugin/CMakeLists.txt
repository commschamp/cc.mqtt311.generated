set (ALL_MESSAGES_LIB "all_messages")

######################################################################

function (cc_plugin_all_messages)
    set (name "${ALL_MESSAGES_LIB}")
    set (src
        field/BinData.cpp
        field/Length.cpp
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
    target_link_libraries (${name} ${CC_PLUGIN_LIBRARIES})
    qt5_use_modules(${name} Core)
    if (OPT_FULL_SOLUTION)
        add_dependencies(${name} ${CC_EXTERNAL_TGT})
    endif ()
endfunction()

######################################################################

function (cc_plugin protocol)
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

    qt5_wrap_cpp(moc ${hdr})

    set(extra_link_opts)
    if (CMAKE_COMPILER_IS_GNUCC)
        set(extra_link_opts "-Wl,--no-undefined")
    endif ()

    add_library (${name} MODULE ${src} ${moc})
    target_link_libraries (${name} ${ALL_MESSAGES_LIB} ${CC_PLUGIN_LIBRARIES} ${extra_link_opts})
    if (CMAKE_COMPILER_IS_GNUCC)
        target_compile_options(${name} PRIVATE "-ftemplate-backtrace-limit=0")
    endif ()

    qt5_use_modules (${name} Core)
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

if (CMAKE_COMPILER_IS_GNUCC)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftemplate-backtrace-limit=0")
endif ()

cc_plugin_all_messages()

cc_plugin ("Mqtt311")

if (OPT_FULL_SOLUTION)
    install (
        FILES plugin/Mqtt311.cfg
        DESTINATION ${CONFIG_INSTALL_DIR}
        RENAME "default.cfg")
endif()


