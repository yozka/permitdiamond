﻿#include "pdClient.h"
#include "pdSettings.h"

///--------------------------------------------------------------------------------------
using namespace Network;
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
AClient :: AClient()
{

}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
AClient :: ~AClient()
{

}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// добавление действия к протоколу сетевому
/// 
/// 
///--------------------------------------------------------------------------------------
void AClient :: addAction(AAction *action)
{
	mActions.push_back(action);
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// установка токена
/// 
/// 
///--------------------------------------------------------------------------------------
void AClient :: setToken(const String &token)
{
	mSTP.setToken(token);
}
///--------------------------------------------------------------------------------------




 ///=====================================================================================
///
/// получить текущий токен
/// 
/// 
///--------------------------------------------------------------------------------------
String AClient :: token()const
{
	return mSTP.token();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Инциализация сокетов
/// 
/// 
///--------------------------------------------------------------------------------------
void AClient :: begin()
{
	mUdp.begin(Settings::clientPort);
}
///--------------------------------------------------------------------------------------




 ///=====================================================================================
///
/// обработка действий
/// 
/// 
///--------------------------------------------------------------------------------------
void AClient :: update()
{
	const int packetSize = mUdp.parsePacket();
	if (packetSize <= 0)
	{
		//данные не пришли
		return;
	}
	Serial.print("Пакет пришел: ");
	Serial.println(packetSize);


	//создадис входящий пакет
	mPacketReceiv.create(packetSize);
	mUdp.read(mPacketReceiv.data(), mPacketReceiv.size());
	
	if (!mPacketReceiv.isValid())
	{
		//пакет битый в хламину
		Serial.println("Битый пакет");
		return;
	}

	//проверка достоверность данных
	if (!mSTP.securityCheck(mPacketReceiv))
	{
		//данные не корректные, отошлем серверу чтобы он перехерачил данные
		Serial.println("Секюрность пакета нарушенна");
		return;
	}


	//поиск команды для обработки запроса
	const auto typeAction = mPacketReceiv.typeAction();
	AAction *pAction = nullptr;
	for (auto &action : mActions)
	{
		if (action->typeAction() == typeAction)
		{
			pAction == action;
			break;
		}
	}
	if (pAction == nullptr)
	{
		//команда не найденна
		Serial.println("Команда не найдена");
		return;
	}

	mPacketSend.clear();
	pAction->process(mPacketReceiv, mPacketSend);

	const auto size = mPacketSend.size();
	if (size <= 0)
	{
		//ответ ненужно отправлять
		Serial.println("Ответ отсутствует");
		return;
	}
	
	//подпишем пакет перед отправкой
	mSTP.sign(mPacketReceiv, mPacketSend); 

	//отошлем ответ
	mUdp.beginPacket(mUdp.remoteIP(), mUdp.remotePort());
	mUdp.write(mPacketSend.data(), size);
	mUdp.endPacket();
}
///--------------------------------------------------------------------------------------

