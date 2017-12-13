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
AServerCore::AServerCore()
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
void AServerCore::run()
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










 ///=====================================================================================
///
/// запуск сканирования
/// 
/// 
///--------------------------------------------------------------------------------------
void AScanDevices :: scan()
{
	if (!mActive)
	{
		mActive = true;
		mInfos.clear();
		mTimer->start(Settings::timeScan);
	}


	QByteArray packet;
	QDataStream out(&packet, QIODevice::WriteOnly);
	out.setByteOrder(QDataStream::LittleEndian);
	out << (quint8)(0xCF);
	out << (quint8)(0xAF);


	//пробежимся по всем сетям
	const auto ifaces = QNetworkInterface::allInterfaces();
	for (auto item = ifaces.cbegin(); item != ifaces.cend(); ++item)
	{
		const auto addrs = item->addressEntries();
		for (auto itemAddrs = addrs.cbegin(); itemAddrs != addrs.cend(); ++itemAddrs)
		{
			const auto broadcast = itemAddrs->broadcast();
			if (!broadcast.isNull())
			{
				mSocket->writeDatagram(packet.data(), packet.size(), broadcast, Settings::portScan);
			}
		}
	}
}
///--------------------------------------------------------------------------------------





