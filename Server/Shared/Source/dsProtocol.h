#pragma once
#include <QObject>
#include <QVector>
//-----------------------------------------------------------------------------
#include "dsClientAddress.h"
#include "dsCommand.h"
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



			void append(const PCommand &command); //���������� �������


			//����������� �����������
			AProtocol& operator = (const AProtocol&) = delete;
			AProtocol(const AProtocol&) = delete;
		
		public slots:


			void slot_receiv(const QByteArray &packet, const AClientAddress &address);// ������ ������



		private:

			QVector<PCommand> mCommands;


		};




	}
}