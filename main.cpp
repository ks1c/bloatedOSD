#include <QCoreApplication>
#include <QDebug>
#include "dbushandler.hpp"

int main(int argc, char *argv[]) {
	
	QCoreApplication app(argc, argv);
	qDebug() << "helloWorld";

	DBusHandler dBusHandler;

	return 0;
	//return app.exec();
}

