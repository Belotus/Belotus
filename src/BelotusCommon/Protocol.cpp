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


 /**********************************************************************
 * Public methods                                                      *
 **********************************************************************/

Protocol::Protocol(QObject *parent, QTcpSocket *socket)
    : Base(parent), isReady(true), messageLength(0),
    lengthReceived(false), socket(socket)
{
    this->out = new QDataStream(&this->data, QIODevice::WriteOnly);
    this->in = new QDataStream(this->socket);
    connect(this->socket, SIGNAL(readyRead()), this, SLOT(ReadyRead()));
}

Protocol::~Protocol()
{
    delete(this->in);
    delete(this->out);
    delete(this->socket);
}

void Protocol::MessageProcessed()
{
    this->isReady = true;
    this->messageLength = 0;
    this->lengthReceived = false;
    this->receive();
}

Card* Protocol::getCard() const
{
    return this->card;
}

QString Protocol::getQString() const
{
    return this->string;
}

void Protocol::sendQueryPlay()
{
    this->writeQuint32(this->QUERY_PLAY);
    this->send();
}

void Protocol::sendQueryAddCard(const Card* card)
{

}

void Protocol::sendQueryInsult(const QString insult)
{
    this->writeQString(insult);
    this->send();
}

void Protocol::sendAnswerACK()
{
    this->writeQuint32(this->ANSWER_ACK);
    this->send();
}

void Protocol::sendAnswerFAIL()
{
    this->writeQuint32(this->ANSWER_FAIL);
}

void Protocol::sendAnswerPlay()
{
    this->writeQuint32(this->ANSWER_PLAY);
}

/**********************************************************************
* Protected methods                                                   *
**********************************************************************/

QTextStream& Protocol::PrintOn(QTextStream& stream) const
{
    return stream << "Protocol";
}

/**********************************************************************
* Private slots                                                       *
**********************************************************************/

void Protocol::ReadyRead()
{
    this->receive();
}

/**********************************************************************
* Private methods                                                     *
**********************************************************************/

void Protocol::receive()
{
    if(this->isReady)
    {
        if(!this->lengthReceived)
        {
            this->messageLength = readQuint32();
            this->lengthReceived = true;
        }

        if(this->socket->bytesAvailable() >= this->messageLength)
        {
            this->type = readQuint32();
            switch(this->type)
            {
            case QUERY_ADD_CARD:
                qDebug() << "MessageReady : QUERY_ADD_CARD" << endl;
                receiveAddCard();
                break;

            case QUERY_INSULT:
                qDebug() << "MessageReady : QUERY_INSULT" << endl;
                receiveInsult();
                break;

            case QUERY_PLAY:
                qDebug() << "MessageReady : QUERY_PLAY" << endl;
                break;

            case ANSWER_ACK:
                qDebug() << "MessageReady : ANSWER_ACK" << endl;
                break;

            case ANSWER_FAIL:
                qDebug() << "MessageReady : ANSWER_FAIL" << endl;
                break;

            case ANSWER_PLAY:
                qDebug() << "MessageReady : ANSWER_PLAY" << endl;
                break;

            default:
                qDebug() << "MessageReady : UNKNOWN (" << this->type << ")" << endl;
                break;
            }

            this->isReady = false;

            emit this->s_MessageReady(&this->type);
        }
    }
}

void Protocol::receiveAddCard()
{

}

void Protocol::receiveInsult()
{
    this->string = this->readQString();
}

void Protocol::send()
{
    this->writeQuint32(this->data.size());
    this->socket->write(this->data);
    this->data.clear();
}

void Protocol::writeQuint32(const quint32 value)
{
    *(this->out) << value;
}

void Protocol::writeQString(const QString value)
{
    *(this->out) << value;
}

quint32 Protocol::readQuint32()
{
    quint32 value;
    *(this->in) >> value;
    return value;
}

QString Protocol::readQString()
{
    QString value;
    *(this->in) >> value;
    return value;
}
