#include "dsDiamondServer_Windows.h"

ADiamondServer_Windows::ADiamondServer_Windows(const Server::PServerCore &server)
	:
	QMainWindow(nullptr),
	mServer (server)
{
	ui.setupUi(this);
}
