﻿#pragma once
#include <Arduino.h>
#include "pdCommand.h"
#include "pdOptions.h"
namespace Terminal
{
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// Команда для терминала
	/// 
	/// имя устройства
	/// 
	///--------------------------------------------------------------------------------------
	class ACMD_name
		:
		public	ACommand
	{
	public:
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// Constructor.
		///--------------------------------------------------------------------------------------
		ACMD_name(Options::AOptions *options);
		///--------------------------------------------------------------------------------------





		///=====================================================================================
		///
		/// Destructor
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		virtual ~ACMD_name();
		///--------------------------------------------------------------------------------------





		///=====================================================================================
		///
		/// имя команды
		/// 
		///--------------------------------------------------------------------------------------
		String name() const override  { return F("name"); };
		///--------------------------------------------------------------------------------------






		 ///=====================================================================================
		///
		/// 
		/// описание команды
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		String description() const override { return F("Имя устройства"); };
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

	};

}