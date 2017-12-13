#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_dsDiamondServer_Windows.h"
#include "dsServerCore.h"


class ADiamondServer_Windows 
	: 
		public QMainWindow
{
	Q_OBJECT

public:
	ADiamondServer_Windows(const Server::PServerCore &server);

private:
	Ui::DiamondServer_WindowsClass ui;


	Server::PServerCore mServer;

};
