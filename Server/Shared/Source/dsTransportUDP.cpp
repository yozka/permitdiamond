#include "dsTransportUDP.h"
#include <QNetworkInterface>
///------------------------------------------------------------------------





///------------------------------------------------------------------------
using namespace Server;
using namespace Server::Transport;
///------------------------------------------------------------------------






 ///-----------------------------------------------------------------------
///
/// Constructor
///
///
///------------------------------------------------------------------------
ATransportUDP :: ATransportUDP()
	:
	mSocket(this)
{
	connect(&mSocket, &QUdpSocket::readyRead, this, &ATransportUDP::slot_readData);
}
///------------------------------------------------------------------------






 ///-----------------------------------------------------------------------
///
/// Destructor
///
///
///------------------------------------------------------------------------
ATransportUDP :: ~ATransportUDP()
{
	
}
///------------------------------------------------------------------------






 ///-----------------------------------------------------------------------
///
/// ������ �������� ��������� �� ���������� �����
///
///
///------------------------------------------------------------------------
void ATransportUDP :: bind(const int port)
{
	mSocket.bind(QHostAddress::Any, port);
}
///------------------------------------------------------------------------









 ///-----------------------------------------------------------------------
///
/// ������ ������ �� ��������
///
///
///------------------------------------------------------------------------
void ATransportUDP :: slot_readData()
{
	while (mSocket.hasPendingDatagrams())
	{
		const int packetSize = mSocket.pendingDatagramSize();
		QByteArray datagram(packetSize, 0);
		QHostAddress sender;
		quint16 senderPort;

		mSocket.readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

		const AClientAddress address(sender, senderPort);
		emit signal_receiv(datagram, address);
	}
}
///--------------------------------------------------------------------------------------










 ///=====================================================================================
///
/// ��������� ����
/// 
/// 
///--------------------------------------------------------------------------------------
void ATransportUDP :: sendBroadcast(const QByteArray &packet)
{
	const auto port = mSocket.localPort();

	//���������� �� ���� �����
	const auto ifaces = QNetworkInterface::allInterfaces();
	for (auto item = ifaces.cbegin(); item != ifaces.cend(); ++item)
	{
		const auto addrs = item->addressEntries();
		for (auto itemAddrs = addrs.cbegin(); itemAddrs != addrs.cend(); ++itemAddrs)
		{
			const auto broadcast = itemAddrs->broadcast();
			if (!broadcast.isNull())
			{
				mSocket.writeDatagram(packet.data(), packet.size(), broadcast, port);
			}
		}
	}
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// �������� ����������� ����
/// 
/// 
///--------------------------------------------------------------------------------------
void ATransportUDP :: send(const QByteArray &packet, const AClientAddress &address)
{
	mSocket.writeDatagram(packet, address.host(), address.port());
}