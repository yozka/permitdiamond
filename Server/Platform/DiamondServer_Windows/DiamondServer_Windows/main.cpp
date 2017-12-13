#include <QtWidgets/QApplication>


#include "..\..\..\Shared\Source\dsDiamondServer_Windows.h"
#include "..\..\..\Shared\Source\dsServerCore.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	auto server = Server::PServerCore::create();
	server->run(); //запустили работу сервера

	
	
	ADiamondServer_Windows w(server);
	w.show();
	return a.exec();
}
