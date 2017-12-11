﻿#pragma once
#include <Arduino.h>
#include "pdCommand.h"
#include "pdOptions.h"
#include "pdClient.h"
namespace Terminal
{
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// Команда для терминала
	/// установить токен для связи со сервером
	///
	/// 
	///--------------------------------------------------------------------------------------
	class ACMD_token
		:
		public	ACommand
	{
	public:
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// Constructor.
		///--------------------------------------------------------------------------------------
		ACMD_token(Options::AOptions *options, Network::AClient *client);
		///--------------------------------------------------------------------------------------





		///=====================================================================================
		///
		/// Destructor
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		virtual ~ACMD_token();
		///--------------------------------------------------------------------------------------





		///=====================================================================================
		///
		/// имя команды
		/// 
		///--------------------------------------------------------------------------------------
		String name() const override  { return F("token"); };
		///--------------------------------------------------------------------------------------






		 ///=====================================================================================
		///
		/// 
		/// описание команды
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		String description() const override { return F("Индентификация сервера"); };
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


		Options::AOptions *mOptions;
		Network::AClient *mClient;

	};

}
