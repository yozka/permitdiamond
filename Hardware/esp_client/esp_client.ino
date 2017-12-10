#include <Arduino.h>

#include "pdOptions.h"
#include "pdWorkerWiFi.h"
#include "pdNearFieldCommunication.h"
#include "pdTerminal.h"
#include "pdCommand_scan.h"
#include "pdCommand_connect.h"
#include "pdCommand_wifi.h"
#include "pdCommand_reconnect.h"
#include "pdCommand_reboot.h"
#include "pdCommand_reinitialize.h"
#include "pdCommand_name.h"




Options::AOptions				options;						//система настроек
Network::AWorkerWiFi			workerWiFi(&Serial, &options);	//помошник вайфая
NFC::ANearFieldCommunication	nfc;							//приемник метки

Terminal::ATerminal			terminal(&Serial);				//терминал
Terminal::ACMD_scan			cmd_scan;						//команда терминала список вафлей
Terminal::ACMD_connect		cmd_connect(&workerWiFi);		//подключение к вафле
Terminal::ACMD_wifi			cmd_wifi(&workerWiFi);			//статус текущей вафли
Terminal::ACMD_reconnect	cmd_reconnect(&workerWiFi);		//переподклчить вафлю
Terminal::ACMD_reboot		cmd_reboot;						//перезагрузить систему
Terminal::ACMD_reinitialize	cmd_reinitialize(&options);		//сбросить настройки
Terminal::ACMD_name			cmd_name(&options);				//имя устройства



void setup()
{
	terminal.addCommand(&cmd_name);
	terminal.addCommand(&cmd_wifi);
	terminal.addCommand(&cmd_scan);
	terminal.addCommand(&cmd_connect);
	terminal.addCommand(&cmd_reconnect);
	terminal.addCommand(&cmd_reinitialize);
	terminal.addCommand(&cmd_reboot);
	

	Serial.begin(9600);
    Serial.println();
	terminal.printHelp();


	workerWiFi.begin();
	nfc.begin();
}


void loop()
{
	terminal.update();
	nfc.update();
}
