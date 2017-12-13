#pragma once
#include <QSharedPointer>
#include <QUdpSocket>
#include <QTimer>
//-----------------------------------------------------------------------------



namespace Server
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
		AServerCore();
		virtual ~AServerCore(); //destructor
		


		void run(); //������ �������


	private:

		QUdpSocket	*mUdp;
		QTimer		*mProcessing;

		void slot_readData(); //������ ������
		void slot_update(); //����� ����������
	};



	using PServerCore = QSharedPointer<AServerCore>;

}