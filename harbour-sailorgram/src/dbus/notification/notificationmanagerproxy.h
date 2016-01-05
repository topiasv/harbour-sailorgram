/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp org.freedesktop.Notifications.xml -p notificationmanagerproxy -c NotificationManagerProxy -i notification.h
 *
 * qdbusxml2cpp is Copyright (C) 2015 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef NOTIFICATIONMANAGERPROXY_H_1451943705
#define NOTIFICATIONMANAGERPROXY_H_1451943705

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "notification.h"

/*
 * Proxy class for interface org.freedesktop.Notifications
 */
class NotificationManagerProxy: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.Notifications"; }

public:
    NotificationManagerProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~NotificationManagerProxy();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> CloseNotification(uint id)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(id);
        return asyncCallWithArgumentList(QLatin1String("CloseNotification"), argumentList);
    }

    inline QDBusPendingReply<QStringList> GetCapabilities()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetCapabilities"), argumentList);
    }

    inline QDBusPendingReply<QList < NotificationData > > GetNotifications(const QString &app_name)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(app_name);
        return asyncCallWithArgumentList(QLatin1String("GetNotifications"), argumentList);
    }

    inline QDBusPendingReply<QString, QString, QString, QString> GetServerInformation()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetServerInformation"), argumentList);
    }
    inline QDBusReply<QString> GetServerInformation(QString &name, QString &vendor, QString &version)
    {
        QList<QVariant> argumentList;
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QLatin1String("GetServerInformation"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 4) {
            name = qdbus_cast<QString>(reply.arguments().at(1));
            vendor = qdbus_cast<QString>(reply.arguments().at(2));
            version = qdbus_cast<QString>(reply.arguments().at(3));
        }
        return reply;
    }

    inline QDBusPendingReply<uint> Notify(const QString &app_name, uint replaces_id, const QString &app_icon, const QString &summary, const QString &body, const QStringList &actions, const QVariantHash &hints, int expire_timeout)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(app_name) << QVariant::fromValue(replaces_id) << QVariant::fromValue(app_icon) << QVariant::fromValue(summary) << QVariant::fromValue(body) << QVariant::fromValue(actions) << QVariant::fromValue(hints) << QVariant::fromValue(expire_timeout);
        return asyncCallWithArgumentList(QLatin1String("Notify"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void ActionInvoked(uint id, const QString &action_key);
    void NotificationClosed(uint id, uint reason);
};

namespace org {
  namespace freedesktop {
    typedef ::NotificationManagerProxy Notifications;
  }
}
#endif
