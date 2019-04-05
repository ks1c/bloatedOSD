#include <QDebug>
#include <QtDBus>
#include "dbushandler.hpp"

DBusHandler::DBusHandler(QObject *notificationManager) : QDBusAbstractAdaptor(notificationManager) {
	
	if (!QDBusConnection::sessionBus().isConnected()) {
		qDebug() << "Cannot connect to the D-Bus session bus\n";
	}

	if (!QDBusConnection::sessionBus().registerService(NOTIFICATIONS_SERVICE)) {
		qDebug() << "Failed to register service.\n";
	}
	
	if (!QDBusConnection::sessionBus().registerObject(NOTIFICATIONS_OBJECT, notificationManager)) {
		qDebug() << "Failed to register object.\n";
	}

	QDBusInterface *interface = new QDBusInterface(
			DBUS_SERVICE,
			DBUS_OBJECT,
			DBUS_SERVICE,
			QDBusConnection::sessionBus(),
			this
	);
	
	interface->call("AddMatch", MATCH_STRING);
}

void DBusHandler::Notify(const QDBusMessage &message) {
	qDebug() << message.arguments().at(3);
}

QString DBusHandler::GetServerInformation(QString &vendor, QString &version, QString &spec_version) {
	return "";
}
	
