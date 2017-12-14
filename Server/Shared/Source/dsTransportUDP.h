#pragma once
#include <QUdpSocket>
#include <QByteArray>
//-----------------------------------------------------------------------------
#include "dsClientAddress.h"
//-----------------------------------------------------------------------------




namespace Server
{
	namespace Transport
	{
		//-------------------------------------------------------------------------





		 ///-----------------------------------------------------------------------
		///
		/// ������� ���������� ������
		/// 
		///
		///------------------------------------------------------------------------
		class ATransportUDP
			:
			public QObject
		{
			Q_OBJECT

		public:

			//constructor
			ATransportUDP();
			virtual ~ATransportUDP(); //destructor

			void bind(const int port); //������ �������� ��������� �� ���������� �����

			void sendBroadcast(const QByteArray &packet); //��������� ����
			void send(const QByteArray &packet, const AClientAddress &address); //�������� ����������� ����




			//����������� �����������
			ATransportUDP& operator = (const ATransportUDP&) = delete;
			ATransportUDP(const ATransportUDP&) = delete;


		signals:

			void signal_receiv(const QByteArray &packet, const AClientAddress &address);// ������ ������


		


		private:
			QUdpSocket	mSocket;



			void slot_readData(); //������ ������
		};




	}
}