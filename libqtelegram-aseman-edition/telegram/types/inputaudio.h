// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#ifndef LQTG_TYPE_INPUTAUDIO
#define LQTG_TYPE_INPUTAUDIO

#include "telegramtypeobject.h"
#include <QtGlobal>

class LIBQTELEGRAMSHARED_EXPORT InputAudio : public TelegramTypeObject
{
public:
    enum InputAudioType {
        typeInputAudioEmpty = 0xd95adc84,
        typeInputAudio = 0x77d440ff
    };

    InputAudio(InputAudioType classType = typeInputAudioEmpty, InboundPkt *in = 0);
    InputAudio(InboundPkt *in);
    virtual ~InputAudio();

    void setAccessHash(qint64 accessHash);
    qint64 accessHash() const;

    void setId(qint64 id);
    qint64 id() const;

    void setClassType(InputAudioType classType);
    InputAudioType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const InputAudio &b);

private:
    qint64 m_accessHash;
    qint64 m_id;
    InputAudioType m_classType;
};

#endif // LQTG_TYPE_INPUTAUDIO
