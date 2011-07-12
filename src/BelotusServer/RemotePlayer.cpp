/* Belotus
 *
 * RemotePlayer.cpp
 * Copyright (C) 2010 Schneider Julien <contact@julienschneider.fr>
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


RemotePlayer::RemotePlayer(QTcpSocket *socket, CardFactory *cardFactory)
    : Player(), protocol(new Protocol(socket, cardFactory))
{
    qDebug() << "RemotePlayer : Constructeur" ;
    connect(this->protocol, SIGNAL(s_MessageReady(quint32)), this, SLOT(MessageReady()));
}

RemotePlayer::~RemotePlayer()
{
    delete this->protocol;
}

void RemotePlayer::Play()
{
    qDebug() << "RemotePlayer : Play" ;
    this->protocol->writeQuint32(Protocol::QUERY_PLAY);
    this->protocol->send();
    qDebug() << "RemotePlayer : Fin Play" ;
}

void RemotePlayer::AddCard(Card* card)
{
    qDebug() << "RemotePlayer : AddCard" ;
    this->protocol->writeQuint32(Protocol::QUERY_ADD_CARD);
    this->protocol->writeCard(card);
    this->protocol->send();
    qDebug() << "RemotePlayer : Fin AddCard" ;
}

void RemotePlayer::Insult(QString insult)
{
    qDebug() << "RemotePlayer : Insult" ;
    this->protocol->writeQuint32(Protocol::QUERY_INSULT);
    this->protocol->writeQString(insult);
    this->protocol->send();
    qDebug() << "RemotePlayer : Fin Insult" ;
}

void RemotePlayer::AFGameBeginning()
{
    qDebug() << "RemotePlayer : Asking Player 1 for game beginning" ;
    this->protocol->writeQuint32(Protocol::QUERY_START_GAME);
    this->protocol->send();
    qDebug() << "RemotePlayer : Fin AFGameBeginning";
}

void RemotePlayer::MessageReady(quint32 type)
{
    switch(type)
    {
    /* Only handled messages */
    case Protocol::QUERY_INSULT:
        qDebug() << "Insult received : " << this->protocol->readQString();
        break;
    case Protocol::ANSWER_START_GAME:
        /* TODO: implementer une machine à etat simple
                 pour gerer les messages pouvant être recus. */
        break;

    default:
        break;
    }

    qDebug() << "RemotePlayer : ReadyRead";
}


QString RemotePlayer::ToString() const
{
    return "RemotePlayer";
}
