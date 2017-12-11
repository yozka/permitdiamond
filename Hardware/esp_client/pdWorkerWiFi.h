﻿#pragma once
#include <Arduino.h>
#include "pdOptions.h"
namespace Network
{
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// Система, которая делает соеденения с вайфай точкой и все настройки
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AWorkerWiFi
	{
	public:
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// Constructor.
		///--------------------------------------------------------------------------------------
		AWorkerWiFi(Stream *stream, Options::AOptions *options);
		///--------------------------------------------------------------------------------------





		///=====================================================================================
		///
		/// Destructor
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		virtual ~AWorkerWiFi();
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// 
		/// начальная настройка
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		void begin();
		///--------------------------------------------------------------------------------------


		void update();	//обновление состояния



		 ///=====================================================================================
		///
		/// подключение к точке доступа
		/// 
		///--------------------------------------------------------------------------------------
		void connect(const String &ssid, const String &password);
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// пересоеденение к точке доступа
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		void reconnect();
		///--------------------------------------------------------------------------------------





		//заблокируем копирование
		AWorkerWiFi& operator = (const AWorkerWiFi&) = delete;
		AWorkerWiFi(const AWorkerWiFi&) = delete;

	private:

	
		Stream *mStream;
		Options::AOptions *mOptions;

		

	};

}
