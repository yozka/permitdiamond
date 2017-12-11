#include <Arduino.h>

#include "pdOptions.h"
#include "pdWorkerWiFi.h"
#include "pdDevice.h"
#include "pdClient.h"

#include "pdTerminal.h"
#include "pdCommand_scan.h"
#include "pdCommand_connect.h"
#include "pdCommand_wifi.h"
#include "pdCommand_reconnect.h"
#include "pdCommand_reboot.h"
#include "pdCommand_reinitialize.h"
#include "pdCommand_name.h"
#include "pdCommand_token.h"



Options::AOptions				options;						//система настроек
Network::AWorkerWiFi			workerWiFi(&Serial, &options);	//помошник вайфая
Network::AClient				client;							//клиент для сервера
Devices::ADevice				device;							//устройства


Terminal::ATerminal			terminal(&Serial);				//терминал
Terminal::ACMD_scan			cmd_scan;						//команда терминала список вафлей
Terminal::ACMD_connect		cmd_connect(&workerWiFi);		//подключение к вафле
Terminal::ACMD_wifi			cmd_wifi(&workerWiFi);			//статус текущей вафли
Terminal::ACMD_reconnect	cmd_reconnect(&workerWiFi);		//переподклчить вафлю
Terminal::ACMD_reboot		cmd_reboot;						//перезагрузить систему
Terminal::ACMD_reinitialize	cmd_reinitialize(&options);		//сбросить настройки
Terminal::ACMD_name			cmd_name(&options);				//имя устройства
Terminal::ACMD_token		cmd_token(&options, &client);	//токен доступа индентификация на сервере


void setup()
{
	//инциализация терминала
	terminal.addCommand(&cmd_name);
	terminal.addCommand(&cmd_token);
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
	device.begin();

	client.begin();
	client.setToken(options.token());
}


void loop()
{
	terminal.update();	//работа терминала
	device.update();	//работа устройств
	client.update();	//сетевые действия
	workerWiFi.update(); //работа вафли
}
