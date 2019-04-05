#include <QCoreApplication>
#include <QDebug>
#include "dbushandler.hpp"
#include "notificationmanager.hpp"

int main(int argc, char *argv[]) {
	
	QCoreApplication app(argc, argv);
	qDebug() << "Service started.\n";
	
	NotificationManager notificationManager;	
	DBusHandler dBusHandler(&notificationManager);

	return app.exec();
}

