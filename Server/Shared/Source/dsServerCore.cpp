#include "dsServerCore.h"
#include "dsSettings.h"
///------------------------------------------------------------------------





///------------------------------------------------------------------------
using namespace Server;
///------------------------------------------------------------------------






 ///-----------------------------------------------------------------------
///
/// Constructor
///
///
///------------------------------------------------------------------------
AServerCore :: AServerCore()
	:
	mUdp(nullptr),
	mProcessing(nullptr)


{
	mUdp = new QUdpSocket();
	connect(mUdp, &QUdpSocket::readyRead, this, &AServerCore::slot_readData);


	mProcessing = new QTimer();
	connect(mProcessing, &QTimer::timeout, this, &AServerCore::slot_update);
}
///------------------------------------------------------------------------






 ///-----------------------------------------------------------------------
///
/// Destructor
///
///
///------------------------------------------------------------------------
AServerCore :: ~AServerCore()
{
	delete mUdp;
	delete mProcessing;
}
///------------------------------------------------------------------------






 ///-----------------------------------------------------------------------
///
/// запуск сервера
///
///
///------------------------------------------------------------------------
void AServerCore :: run()
{
	mUdp->bind(QHostAddress::LocalHost, Settings::serverPort);
	mProcessing->start(Settings::serverTimeUpdate);
}
///------------------------------------------------------------------------





 ///-----------------------------------------------------------------------
///
/// обработка сервера
/// процессорное время
///
///------------------------------------------------------------------------
void AServerCore::slot_update()
{

}
///------------------------------------------------------------------------







 ///-----------------------------------------------------------------------
///
/// пришли данные из клиентов
///
///
///------------------------------------------------------------------------
void AServerCore::slot_readData()
{
	while (mUdp->hasPendingDatagrams())
	{
		const int packetSize = mUdp->pendingDatagramSize();
		QByteArray datagram(packetSize, 0);
		QHostAddress sender;
		quint16 senderPort;

		mUdp->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
	

		//
		//QDataStream stream(&datagram, QIODevice::ReadOnly);
		//stream.setByteOrder(QDataStream::LittleEndian);

		
	}



}




