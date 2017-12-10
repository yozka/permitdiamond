﻿#pragma once
#include <Arduino.h>
#include "pdCommand.h"
#include "pdWorkerWiFi.h"
namespace Terminal
{
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// Команда для терминала
	/// 
	/// перезагрузить соеденение
	/// 
	///--------------------------------------------------------------------------------------
	class ACMD_reconnect
		:
		public	ACommand
	{
	public:
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// Constructor.
		///--------------------------------------------------------------------------------------
		ACMD_reconnect(Network::AWorkerWiFi *wifi);
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// Destructor
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		virtual ~ACMD_reconnect();
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// имя команды
		/// 
		///--------------------------------------------------------------------------------------
		String name() const override  { return F("wifi-reconnect"); };
		///--------------------------------------------------------------------------------------






		 ///=====================================================================================
		///
		/// 
		/// описание команды
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		String description() const override { return F("Переподключение к Wi-Fi"); };
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// выполнение команды
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		void execute(Stream *stream, const String &param) override;
		///--------------------------------------------------------------------------------------







	private:

		Network::AWorkerWiFi *mWiFi;


	};

}
