#ifndef DBUSHANDLER_H
#define DBUSHANDLER_H

#include <QObject>
#include <QDBusMessage>
#include <QDBusAbstractAdaptor>

#define NOTIFICATIONS_SERVICE "org.freedesktop.Notifications"
#define NOTIFICATIONS_OBJECT "/org/freedesktop/Notifications"
#define DBUS_SERVICE "org.freedesktop.DBus"
#define DBUS_OBJECT "/org/freedesktop/DBus"
#define MATCH_STRING "interface='org.freedesktop.Notifications',member='Notify',type='method_call',eavesdrop='true'"

class DBusHandler : public QDBusAbstractAdaptor {

	Q_OBJECT
	Q_CLASSINFO("D-Bus Interface", NOTIFICATIONS_SERVICE)

public:
	DBusHandler(QObject *notificationManager = 0);	

public slots:
	Q_NOREPLY void Notify(const QDBusMessage &message);
	QString GetServerInformation(QString &vendor, QString &version, QString &spec_version);
};

#endif
