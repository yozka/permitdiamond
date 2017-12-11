﻿#pragma once
#include <Arduino.h>
#include "pdProtocol.h"
namespace Network
{
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// Пакет входящих и исходящих данных
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class APacket
	{
	public:
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// Constructor.
		///--------------------------------------------------------------------------------------
		APacket();
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// Destructor
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		virtual ~APacket();
		///--------------------------------------------------------------------------------------








		 ///=====================================================================================
		///
		/// пришли данные
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		///--------------------------------------------------------------------------------------





		//заблокируем копирование
		APacket& operator = (const APacket&) = delete;
		APacket(const APacket&) = delete;

	private:

	

		unsigned char* buffer;
	};

}
