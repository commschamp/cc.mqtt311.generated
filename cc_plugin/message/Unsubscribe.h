#pragma once

#include <memory>
#include <QtCore/QVariantList>
#include "cc_plugin/Message.h"

namespace mqtt311
{

namespace cc_plugin
{

namespace message
{

class UnsubscribeImpl;
class Unsubscribe : public mqtt311::cc_plugin::Message
{
public:
    Unsubscribe();
    Unsubscribe(const Unsubscribe&) = delete;
    Unsubscribe(Unsubscribe&&) = delete;
    virtual ~Unsubscribe();
    Unsubscribe& operator=(const Unsubscribe& other);
    Unsubscribe& operator=(Unsubscribe&&);

protected:
    virtual const char* nameImpl() const override;
    virtual const QVariantList& fieldsPropertiesImpl() const override;
    virtual void dispatchImpl(comms_champion::MessageHandler& handler) override;
    virtual void resetImpl() override;
    virtual bool assignImpl(const comms_champion::Message& other) override;
    virtual MsgIdParamType getIdImpl() const override;
    virtual comms::ErrorStatus readImpl(ReadIterator& iter, std::size_t len) override;
    virtual comms::ErrorStatus writeImpl(WriteIterator& iter, std::size_t len) const override;
    virtual bool validImpl() const override;
    virtual std::size_t lengthImpl() const override;
    virtual bool refreshImpl() override;

private:
    std::unique_ptr<UnsubscribeImpl> m_pImpl;
};

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311



