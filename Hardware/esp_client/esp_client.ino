#include <Arduino.h>


#include "pdWorkerWiFi.h"
#include "pdTerminal.h"
#include "pdCommand_scan.h"
#include "pdCommand_connect.h"



Networks::AWorkerWiFi	workerWiFi(&Serial);			//помошник вайфая

Terminal::ATerminal		terminal(&Serial);				//терминал
Terminal::ACMD_scan		cmd_scan;						//команда терминала список вафлей
Terminal::ACMD_connect	cmd_connect(&workerWiFi);		//подключение к вафле




void setup()
{
	terminal.addCommand(&cmd_scan);
	terminal.addCommand(&cmd_connect);
	
	Serial.begin(9600);
    Serial.println();

	workerWiFi.begin();
}


void loop()
{
	terminal.update();

}
