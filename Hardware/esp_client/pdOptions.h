#pragma once
#include <Arduino.h>
namespace Options
{
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// ���������� ��������
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AOptions
	{
	public:
		///--------------------------------------------------------------------------------------





		///=====================================================================================
		///
		/// Constructor.
		///--------------------------------------------------------------------------------------
		AOptions();
		///--------------------------------------------------------------------------------------





		///=====================================================================================
		///
		/// Destructor
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		virtual ~AOptions();
		///--------------------------------------------------------------------------------------





		///=====================================================================================
		///
		/// 
		/// ��������� ���������
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		//void begin();
		///--------------------------------------------------------------------------------------






		///=====================================================================================
		///
		/// ����������� � ����� �������
		/// 
		///--------------------------------------------------------------------------------------
		//void connect(const String &ssid, const String &password);
		///--------------------------------------------------------------------------------------





		///=====================================================================================
		///
		/// �������������� � ����� �������
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		//void reconnect();
		///--------------------------------------------------------------------------------------





		//����������� �����������
		AOptions& operator = (const AOptions&) = delete;
		AOptions(const AOptions&) = delete;

	private:


		




	};

}
