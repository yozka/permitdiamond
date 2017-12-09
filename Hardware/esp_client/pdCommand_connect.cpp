﻿#include "pdCommand_connect.h"
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
ACMD_connect :: ACMD_connect(Networks::AWorkerWiFi *wifi)
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
ACMD_connect :: ~ACMD_connect()
{

}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// Выполнение команды
/// 
/// 
///--------------------------------------------------------------------------------------
void ACMD_connect:: execute(Stream *stream, const String &param)
{
	if (stream == nullptr)
	{
		return;
	}
	
	const auto values = Utils::split(param, " ");
	if (values.size() < 2)
	{
		stream->println(FPSTR("Неправельные параметры"));
		return;
	}

	const String name		= values[1];
	const String password	= (values.size() <= 2) ? values[2] : String();
	stream->print(FPSTR("Точка доступа: "));
	stream->println(name);
	mWiFi->connect(name, password);
}
///--------------------------------------------------------------------------------------


