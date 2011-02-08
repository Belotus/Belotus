/* Belotus
 *
 * RemotePlayer.cpp
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

#include <QTcpSocket>

#include "RemotePlayer.h"


RemotePlayer::RemotePlayer(QTcpSocket *socket)
    : Player(), protocol(new Protocol(socket))
{
    qDebug() << "RemotePlayer : Constructeur" ;
    /*
    qDebug() << "Constructeur remote player" << endl;
    qDebug() << "Sending ACK to remote player" << endl;
    this->protocol->sendAnswerACK();
    */
}

RemotePlayer::~RemotePlayer()
{
    delete this->protocol;
}

Card* RemotePlayer::Play()
{
    qDebug() << "RemotePlayer : Play" ;
    qDebug() << "RemotePlayer : Fin Play" ;
    return 0;
}

void RemotePlayer::AddCard(Card* card)
{
    qDebug() << "RemotePlayer : AddCard" ;
    qDebug() << "RemotePlayer : Fin AddCard" ;
}

void RemotePlayer::Insult(QString insult)
{
    qDebug() << "RemotePlayer : Insult" ;
    qDebug() << "RemotePlayer : Fin Insult" ;
}

QString RemotePlayer::ToString() const
{
    return "RemotePlayer";
}
