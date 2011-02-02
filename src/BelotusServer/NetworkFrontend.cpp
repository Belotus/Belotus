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
    qDebug() << "NetworkFrontend : Constructeur" ;
    connect(this, SIGNAL(newConnection()), this, SLOT(NewConnection()));
    this->listen(QHostAddress::Any, 4242);
}

void NetworkFrontend::NewConnection()
{
    qDebug() << "NetworkFrontend : NewConnection" ;
    qDebug() << "Connection arrivée !";
    QTcpSocket *tcpSocket;
    RemotePlayer *remotePlayer;

    tcpSocket = this->nextPendingConnection();

    if(!tcpSocket->isValid())
    {
        qDebug() << "Socket error" << endl;
        return;
    }

    remotePlayer = new RemotePlayer(NULL, tcpSocket);

    emit s_PlayerConnection(remotePlayer);
    qDebug() << "NetworkFrontend : Fin NewConnection" ;
}

QTextStream& NetworkFrontend::PrintOn(QTextStream& stream) const
{
    return stream << "NetworkFrontend : PrintOn";
}
