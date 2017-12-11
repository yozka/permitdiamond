﻿#include "pdCommand_token.h"
#include "pdString.h"


///--------------------------------------------------------------------------------------
using namespace Terminal;
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
ACMD_token :: ACMD_token(Options::AOptions *options, Network::AClient *client)
	:
		mOptions(options),
		mClient(client)
{

}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
ACMD_token :: ~ACMD_token()
{

}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// Выполнение команды
/// 
/// 
///--------------------------------------------------------------------------------------
void ACMD_token:: execute(Stream *stream, const String &param)
{
	if (mOptions == nullptr || stream == nullptr || mClient == nullptr)
	{
		return;
	}
	

	const auto values = Utils::split(param, " ");
	if (values.size() < 2)
	{
		//stream->println(FPSTR("Неправельные параметры"));
		stream->print(FPSTR("Серверный токен доступа: "));
		stream->println(mClient->token());
		return;
	}

	const String sourceToken = values[1];
	stream->print(FPSTR("Установлен серверный токен доступа: "));
	mClient->setToken(sourceToken);

	const String token = mClient->token();
	mOptions->setToken(token);
	stream->println(token);
}
///--------------------------------------------------------------------------------------



