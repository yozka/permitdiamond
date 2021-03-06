﻿#pragma once
#include <vector>
#include <Arduino.h>
#include <WiFiUdp.h>
#include "pdPacket.h"
#include "pdSecurityTokenPolicy.h"
#include "pdAction.h"
namespace Network
{
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// Система подключения к серверу
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AClient
	{
	public:
		///--------------------------------------------------------------------------------------




		 ///=====================================================================================
		///
		/// Constructor
		///--------------------------------------------------------------------------------------
		AClient();
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// Destructor
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		virtual ~AClient();
		///--------------------------------------------------------------------------------------


		void addAction(AAction *action); //добавление действия к протоколу сетевому

		void begin();	//инциализация считывателя меток
		void update();	//обновление состояния считывания меток

		void setToken(const String &token); //установка токена
		String token()const; //получить текущий токен

		//заблокируем копирование
		AClient& operator = (const AClient&) = delete;
		AClient(const AClient&) = delete;

	private:

		std::vector<AAction*> mActions; //действия над сетевым интерфейсом


		WiFiUDP				mUdp; //удп протокол связи
		APacket				mPacketReceiv; //пакет для приема сообщений
		APacket				mPacketSend; //пакет для отправки сообщений

		
		STP::ASecurityTokenPolicy mSTP; //система защиты протокола и целостность данных


	};

}
