#include "pdCommand_wifi.h"
#include "pdString.h"

#include <ESP8266WiFi.h>

///--------------------------------------------------------------------------------------
using namespace Terminal;
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
ACMD_wifi :: ACMD_wifi(Network::AWorkerWiFi *wifi)
	:
	mWiFi(wifi)
{

}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
ACMD_wifi :: ~ACMD_wifi()
{

}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// Выполнение команды
/// 
/// 
///--------------------------------------------------------------------------------------
void ACMD_wifi:: execute(Stream *stream, const String &param)
{
	if (stream == nullptr)
	{
		return;
	}
	
	stream->println(FPSTR("Действующие подключения к точке WiFi"));
	stream->print(FPSTR("      Имя сети: "));	stream->println(WiFi.SSID());
	stream->print(FPSTR("     Состояние: "));
	switch (WiFi.status())
	{
		case WL_IDLE_STATUS		:stream->println(FPSTR("ожидание")); break;
		case WL_NO_SSID_AVAIL	:stream->println(FPSTR("точка доступа не найденна")); break;
		case WL_SCAN_COMPLETED	:stream->println(FPSTR("сканирование сети")); break;
		case WL_CONNECTED		:stream->println(FPSTR("ПОДКЛЮЧЕН")); break;
		case WL_CONNECT_FAILED	:stream->println(FPSTR("ошибка соеденения")); break;
		case WL_CONNECTION_LOST	:stream->println(FPSTR("потеря связи")); break;
		case WL_DISCONNECTED	:stream->println(FPSTR("отключен")); break;
	default:
		stream->println(FPSTR("неизвестно")); break;
	}
	
	stream->print(FPSTR("      Адрес IP: "));	stream->println(WiFi.localIP().toString());
	stream->print(FPSTR(" Маска подсети: "));	stream->println(WiFi.subnetMask().toString());
	stream->print(FPSTR(" Адрес сервера: "));	stream->println(WiFi.gatewayIP().toString());
	stream->print(FPSTR("     Мак адрес: "));	stream->println(WiFi.macAddress());

	stream->println(FPSTR("Системная диагностика:"));
	WiFi.printDiag(*stream);
}
///--------------------------------------------------------------------------------------



