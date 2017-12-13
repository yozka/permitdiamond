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
	/// Система транспорта данных
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
		


		void run(); //запуск сервера


	private:

		QUdpSocket	*mUdp;
		QTimer		*mProcessing;

		void slot_readData(); //пришли данные
		void slot_update(); //время выполнения
	};



	using PServerCore = QSharedPointer<AServerCore>;

}