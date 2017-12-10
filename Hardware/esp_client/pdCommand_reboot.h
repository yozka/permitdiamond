﻿#pragma once
#include <Arduino.h>
#include "pdCommand.h"
namespace Terminal
{
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// Команда для терминала
	/// 
	/// перезагрузка устройства
	/// 
	///--------------------------------------------------------------------------------------
	class ACMD_reboot
		:
		public	ACommand
	{
	public:
		///--------------------------------------------------------------------------------------





		///=====================================================================================
		///
		/// Constructor.
		///--------------------------------------------------------------------------------------
		ACMD_reboot();
		///--------------------------------------------------------------------------------------





		///=====================================================================================
		///
		/// Destructor
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		virtual ~ACMD_reboot();
		///--------------------------------------------------------------------------------------





		///=====================================================================================
		///
		/// имя команды
		/// 
		///--------------------------------------------------------------------------------------
		String name() const override  { return F("reboot"); };
		///--------------------------------------------------------------------------------------






		///=====================================================================================
		///
		/// 
		/// описание команды
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		String description() const override { return F("Перезагрузить устройство"); };
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




	};

}
