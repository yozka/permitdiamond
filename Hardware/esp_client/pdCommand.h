﻿#pragma once
#include <Arduino.h>
namespace Terminal
{
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// Команда для терминала
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class ACommand
	{
	public:
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// Constructor.
		///--------------------------------------------------------------------------------------
		ACommand();
		///--------------------------------------------------------------------------------------





		///=====================================================================================
		///
		/// Destructor
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		virtual ~ACommand();
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// имя команды
		/// 
		///--------------------------------------------------------------------------------------
		virtual String name() const = 0;
		///--------------------------------------------------------------------------------------






		 ///=====================================================================================
		///
		/// 
		/// описание команды
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		virtual String description() const = 0;
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// выполнение команды
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		virtual void execute(Stream *stream, const String &param) = 0;
		///--------------------------------------------------------------------------------------





		//заблокируем копирование
		ACommand& operator = (const ACommand&) = delete;
		ACommand(const ACommand&) = delete;

	private:

	


	};

}