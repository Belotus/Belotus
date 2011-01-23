/* Belotus
 *
 * Protocol.cpp
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

#include "Protocol.h"

quint32 Protocol::QUERY_PLAY = 0x00001;
quint32 Protocol::QUERY_ADD_CARD = 0x00002;
quint32 Protocol::QUERY_INSULT = 0x00003;

quint32 Protocol::ANSWER_ACK = 0x10001;
quint32 Protocol::ANSWER_FAIL = 0x10002;
quint32 Protocol::ANSWER_PLAY = 0x10003;

Protocol::Protocol(QObject *parent, QTcpSocket *socket)
    : Base(parent), socket(socket)
{
}

void Protocol::MessageProcessed()
{

}

void Protocol::send()
{

}

void Protocol::write(quint32)
{

}

void Protocol::write(QString*)
{

}

Card* Protocol::getCard()
{
    return this->card;
}

QString* Protocol::getQString()
{
    return &(this->string);
}

void Protocol::sendQueryPlay()
{

}

void Protocol::sendQueryAddCard(Card* card)
{

}

void Protocol::sendQueryInsult(QString insult)
{

}

void Protocol::sendAnswerACK()
{

}

void Protocol::sendAnswerFAIL()
{

}

void Protocol::sendAnswerPlay()
{

}

void Protocol::receiveAddCard()
{

}

void Protocol::receiveInsult()
{

}

QTextStream& Protocol::PrintOn(QTextStream& stream) const
{
    return stream << "Protocol";
}
