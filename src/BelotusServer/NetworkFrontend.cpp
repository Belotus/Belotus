/* Belotus
 *
 * NetworkFrontend.cpp
 * Copyright (C) 2010 Schneider Julien
 * Copyright (C) 2010 Michael Muré <batolettre@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "NetworkFrontend.h"

NetworkFrontend::NetworkFrontend(QObject *parent)
     : QTcpServer(parent)
{
}

void NetworkFrontend::incomingConnection(int socketDescriptor)
{
    QTcpSocket *tcpSocket;
    RemotePlayer *remotePlayer;

    tcpSocket = new QTcpSocket();

    if (!tcpSocket->setSocketDescriptor(socketDescriptor))
    {
        //emit error(tcpSocket.error());
        cout << "Socket error" << endl;
        return;
    }

    remotePlayer = new RemotePlayer(tcpSocket);

    emit s_PlayerConnection(remotePlayer);
}
