#pragma once
#include <QObject>
//-----------------------------------------------------------------------------
#include "dsClientAddress.h"
//-----------------------------------------------------------------------------



namespace Server
{
	namespace Protocol
	{
		//-------------------------------------------------------------------------





		 ///-----------------------------------------------------------------------
		///
		/// �������� ������� ����� �������� � ��������
		/// 
		///
		///------------------------------------------------------------------------
		class AProtocol
			:
			public QObject
		{
			Q_OBJECT

		public:

			
			AProtocol();			//constructor
			virtual ~AProtocol();	//destructor



			//����������� �����������
			AProtocol& operator = (const AProtocol&) = delete;
			AProtocol(const AProtocol&) = delete;
		
		public slots:


			void slot_receiv(const QByteArray &packet, const AClientAddress &address);// ������ ������



		private:


		};




	}
}