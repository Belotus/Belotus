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
#include <QtEndian>

/***********************************************************************
*  !!!! TODO : rewrite read* and write* functions with the        !!!! *
*  !!!!        QDataStream class                                  !!!! *
***********************************************************************/


 /**********************************************************************
 * Public methods                                                      *
 **********************************************************************/

Protocol::Protocol(QObject *parent, QTcpSocket *socket)
    : Base(parent), isReady(true), socket(socket)
{
    connect(this->socket, SIGNAL(readyRead()), this, SLOT(ReadyRead()));
}

void Protocol::MessageProcessed()
{
    this->isReady = true;
    this->messageLength = 0;
    this->receive();
}

Card* Protocol::getCard()
{
    return this->card;
}

QString Protocol::getQString()
{
    return this->string;
}

void Protocol::sendQueryPlay()
{
    this->writeQuint32(this->QUERY_PLAY);
    this->send();
}

void Protocol::sendQueryAddCard(Card* card)
{

}

void Protocol::sendQueryInsult(QString insult)
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
        if(this->messageLength != 0)
        {
            this->messageLength = readQuint32();
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

void Protocol::writeQuint32(quint32 value)
{
    this->data.append(qToBigEndian(value));
}

void Protocol::writeQString(QString value)
{
    this->data.append(value.size());
    this->data.append(value.toUtf8());
}

quint32 Protocol::readQuint32()
{
    // TODO
}

QString Protocol::readQString()
{
    char *data = new char[this->messageLength];
    int n = 0;

    n = this->socket->read(data, (quint64) this->messageLength);

    return QString(data);
}
