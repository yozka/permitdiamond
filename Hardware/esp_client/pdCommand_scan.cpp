﻿#include "pdCommand_scan.h"

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
ACMD_scan::ACMD_scan()
{

}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
ACMD_scan::~ACMD_scan()
{

}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// Выполнение команды
/// 
/// 
///--------------------------------------------------------------------------------------
void ACMD_scan:: execute(Stream *stream, const String &param)
{
	if (stream == nullptr)
	{
		return;
	}
	stream->print(FPSTR("Поиск доступных Wi-Fi точек"));
	WiFi.scanNetworks(true);
	while (WiFi.scanComplete() < 0)
	{
		delay(500);
		stream->print(FPSTR("."));
	}
	stream->println();
	const int count = WiFi.scanComplete();
	if (count <= 0)
	{
		stream->println(FPSTR("Сетевые точки не обнаружены"));
		return;
	}
	stream->println(FPSTR("------------------------------------------------------"));
	for (int i = 0; i < count; i++)
	{
		stream->print(WiFi.BSSIDstr(i));
		stream->print(" \t ");
		stream->println(WiFi.SSID(i));
	}
	stream->println(FPSTR("------------------------------------------------------"));
}
///--------------------------------------------------------------------------------------



