// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "webpage.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

WebPage::WebPage(WebPageType classType, InboundPkt *in) :
    m_date(0),
    m_duration(0),
    m_embedHeight(0),
    m_embedWidth(0),
    m_flags(0),
    m_id(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

WebPage::WebPage(InboundPkt *in) :
    m_date(0),
    m_duration(0),
    m_embedHeight(0),
    m_embedWidth(0),
    m_flags(0),
    m_id(0),
    m_classType(typeWebPageEmpty)
{
    fetch(in);
}

WebPage::~WebPage() {
}

void WebPage::setAuthor(const QString &author) {
    m_author = author;
}

QString WebPage::author() const {
    return m_author;
}

void WebPage::setDate(qint32 date) {
    m_date = date;
}

qint32 WebPage::date() const {
    return m_date;
}

void WebPage::setDescription(const QString &description) {
    m_description = description;
}

QString WebPage::description() const {
    return m_description;
}

void WebPage::setDisplayUrl(const QString &displayUrl) {
    m_displayUrl = displayUrl;
}

QString WebPage::displayUrl() const {
    return m_displayUrl;
}

void WebPage::setDuration(qint32 duration) {
    m_duration = duration;
}

qint32 WebPage::duration() const {
    return m_duration;
}

void WebPage::setEmbedHeight(qint32 embedHeight) {
    m_embedHeight = embedHeight;
}

qint32 WebPage::embedHeight() const {
    return m_embedHeight;
}

void WebPage::setEmbedType(const QString &embedType) {
    m_embedType = embedType;
}

QString WebPage::embedType() const {
    return m_embedType;
}

void WebPage::setEmbedUrl(const QString &embedUrl) {
    m_embedUrl = embedUrl;
}

QString WebPage::embedUrl() const {
    return m_embedUrl;
}

void WebPage::setEmbedWidth(qint32 embedWidth) {
    m_embedWidth = embedWidth;
}

qint32 WebPage::embedWidth() const {
    return m_embedWidth;
}

void WebPage::setFlags(qint32 flags) {
    m_flags = flags;
}

qint32 WebPage::flags() const {
    return m_flags;
}

void WebPage::setId(qint64 id) {
    m_id = id;
}

qint64 WebPage::id() const {
    return m_id;
}

void WebPage::setPhoto(const Photo &photo) {
    m_photo = photo;
}

Photo WebPage::photo() const {
    return m_photo;
}

void WebPage::setSiteName(const QString &siteName) {
    m_siteName = siteName;
}

QString WebPage::siteName() const {
    return m_siteName;
}

void WebPage::setTitle(const QString &title) {
    m_title = title;
}

QString WebPage::title() const {
    return m_title;
}

void WebPage::setType(const QString &type) {
    m_type = type;
}

QString WebPage::type() const {
    return m_type;
}

void WebPage::setUrl(const QString &url) {
    m_url = url;
}

QString WebPage::url() const {
    return m_url;
}

bool WebPage::operator ==(const WebPage &b) {
    return m_author == b.m_author &&
           m_date == b.m_date &&
           m_description == b.m_description &&
           m_displayUrl == b.m_displayUrl &&
           m_duration == b.m_duration &&
           m_embedHeight == b.m_embedHeight &&
           m_embedType == b.m_embedType &&
           m_embedUrl == b.m_embedUrl &&
           m_embedWidth == b.m_embedWidth &&
           m_flags == b.m_flags &&
           m_id == b.m_id &&
           m_photo == b.m_photo &&
           m_siteName == b.m_siteName &&
           m_title == b.m_title &&
           m_type == b.m_type &&
           m_url == b.m_url;
}

void WebPage::setClassType(WebPage::WebPageType classType) {
    m_classType = classType;
}

WebPage::WebPageType WebPage::classType() const {
    return m_classType;
}

bool WebPage::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeWebPageEmpty: {
        m_id = in->fetchLong();
        m_classType = static_cast<WebPageType>(x);
        return true;
    }
        break;
    
    case typeWebPagePending: {
        m_id = in->fetchLong();
        m_date = in->fetchInt();
        m_classType = static_cast<WebPageType>(x);
        return true;
    }
        break;
    
    case typeWebPage: {
        m_flags = in->fetchInt();
        m_id = in->fetchLong();
        m_url = in->fetchQString();
        m_displayUrl = in->fetchQString();
        if(m_flags & 1<<0) {
            m_type = in->fetchQString();
        }
        if(m_flags & 1<<1) {
            m_siteName = in->fetchQString();
        }
        if(m_flags & 1<<2) {
            m_title = in->fetchQString();
        }
        if(m_flags & 1<<3) {
            m_description = in->fetchQString();
        }
        if(m_flags & 1<<4) {
            m_photo.fetch(in);
        }
        if(m_flags & 1<<5) {
            m_embedUrl = in->fetchQString();
        }
        if(m_flags & 1<<5) {
            m_embedType = in->fetchQString();
        }
        if(m_flags & 1<<6) {
            m_embedWidth = in->fetchInt();
        }
        if(m_flags & 1<<6) {
            m_embedHeight = in->fetchInt();
        }
        if(m_flags & 1<<7) {
            m_duration = in->fetchInt();
        }
        if(m_flags & 1<<8) {
            m_author = in->fetchQString();
        }
        m_classType = static_cast<WebPageType>(x);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool WebPage::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeWebPageEmpty: {
        out->appendLong(m_id);
        return true;
    }
        break;
    
    case typeWebPagePending: {
        out->appendLong(m_id);
        out->appendInt(m_date);
        return true;
    }
        break;
    
    case typeWebPage: {
        out->appendInt(m_flags);
        out->appendLong(m_id);
        out->appendQString(m_url);
        out->appendQString(m_displayUrl);
        out->appendQString(m_type);
        out->appendQString(m_siteName);
        out->appendQString(m_title);
        out->appendQString(m_description);
        m_photo.push(out);
        out->appendQString(m_embedUrl);
        out->appendQString(m_embedType);
        out->appendInt(m_embedWidth);
        out->appendInt(m_embedHeight);
        out->appendInt(m_duration);
        out->appendQString(m_author);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

