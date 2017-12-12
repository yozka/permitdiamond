#pragma once
#include <Arduino.h>
#include "pdPacket.h"
namespace Network
{
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// �������� ��� �������� ���������
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AAction
	{
	public:
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// Constructor.
		///--------------------------------------------------------------------------------------
		AAction();
		///--------------------------------------------------------------------------------------





		///=====================================================================================
		///
		/// Destructor
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		virtual ~AAction();
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// ��� �������
		/// 
		///--------------------------------------------------------------------------------------
		virtual int typeAction() const = 0;
		///--------------------------------------------------------------------------------------








		 ///=====================================================================================
		///
		/// ������ ������
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		virtual void process(const APacket &receiv, APacket &send) = 0;
		///--------------------------------------------------------------------------------------





		//����������� �����������
		AAction& operator = (const AAction&) = delete;
		AAction(const AAction&) = delete;

	private:

	


	};

}
