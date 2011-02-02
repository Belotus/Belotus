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
    qDebug() << "Protocol : Constructeur" ;
    this->out = new QDataStream(&this->data, QIODevice::WriteOnly);
    this->in = new QDataStream(this->socket);
    connect(this->socket, SIGNAL(readyRead()), this, SLOT(ReadyRead()));
    qDebug() << "Protocol : Fin constructeur" ;
}

Protocol::~Protocol()
{
    delete(this->in);
    delete(this->out);
    delete(this->socket);
}

void Protocol::MessageProcessed()
{
    qDebug() << "Protocol : MessageProcessed" ;
    this->isReady = true;
    this->messageLength = 0;
    this->lengthReceived = false;
    this->receive();
    qDebug() << "Protocol : Fin MessageProcessed" ;
}

Card* Protocol::getCard() const
{
    qDebug() << "Protocol : getCard" ;
    return this->card;
    qDebug() << "Protocol : Fin getCard" ;
}

QString Protocol::getQString() const
{
    qDebug() << "Protocol : getQString" ;
    return this->string;
    qDebug() << "Protocol : Fin getQString" ;
}

void Protocol::sendQueryPlay()
{
    qDebug() << "Protocol : sendQueryPlay" ;
    this->writeQuint32(this->QUERY_PLAY);
    this->send();
    qDebug() << "Protocol : Fin sendQueryPlay" ;
}

void Protocol::sendQueryAddCard(const Card* card)
{
    qDebug() << "Protocol : sendQueryAddCard" ;
    qDebug() << "Protocol : Fin sendQueryAddCard" ;
}

void Protocol::sendQueryInsult(const QString insult)
{
    qDebug() << "Protocol : sendQueryInsult" ;
    this->writeQuint32(this->QUERY_INSULT);
    this->writeQString(insult);
    this->send();
    qDebug() << "Protocol : Fin sendQueryInsult" ;
}

void Protocol::sendAnswerACK()
{
    qDebug() << "Protocol : sendAnswerACK" ;
    this->writeQuint32(this->ANSWER_ACK);
    this->send();
    qDebug() << "Protocol : Fin sendAnswerACK" ;
}

void Protocol::sendAnswerFAIL()
{
    qDebug() << "Protocol : sendAnswerFail" ;
    this->writeQuint32(this->ANSWER_FAIL);
    qDebug() << "Protocol : Fin sendAnswerFail" ;
}

void Protocol::sendAnswerPlay()
{
    qDebug() << "Protocol : sendAnswerPlay" ;
    this->writeQuint32(this->ANSWER_PLAY);
    qDebug() << "Protocol : Fin sendAnswerPlay" ;
}

/**********************************************************************
* Protected methods                                                   *
**********************************************************************/

QTextStream& Protocol::PrintOn(QTextStream& stream) const
{
    return stream << "Protocol : PrintOn";
}

/**********************************************************************
* Private slots                                                       *
**********************************************************************/

void Protocol::ReadyRead()
{
    qDebug() << "Protocol : ReadyRead" ;
    this->receive();
    qDebug() << "Protocol : Fin ReadyRead" ;
}

/**********************************************************************
* Private methods                                                     *
**********************************************************************/

void Protocol::receive()
{
    qDebug() << "Protocol : receive" ;
    if(this->isReady)
    {
        if(!this->lengthReceived)
        {
            this->messageLength = readQuint32();
            this->lengthReceived = true;
            qDebug() << "Protocol : receive : messagelength : " << this->messageLength ;
        }

        if(this->socket->bytesAvailable() >= this->messageLength)
        {
            this->type = readQuint32();
            switch(this->type)
            {
            case QUERY_ADD_CARD:
                qDebug() << "Protocol : MessageReady : QUERY_ADD_CARD" << endl;
                receiveAddCard();
                break;

            case QUERY_INSULT:
                qDebug() << "Protocol : MessageReady : QUERY_INSULT" << endl;
                receiveInsult();
                break;

            case QUERY_PLAY:
                qDebug() << "Protocol : MessageReady : QUERY_PLAY" << endl;
                break;

            case ANSWER_ACK:
                qDebug() << "Protocol : MessageReady : ANSWER_ACK" << endl;
                break;

            case ANSWER_FAIL:
                qDebug() << "Protocol : MessageReady : ANSWER_FAIL" << endl;
                break;

            case ANSWER_PLAY:
                qDebug() << "Protocol : MessageReady : ANSWER_PLAY" << endl;
                break;

            default:
                qDebug() << "Protocol : MessageReady : UNKNOWN (" << this->type << ")" << endl;
                break;
            }

            this->isReady = false;

            emit this->s_MessageReady(&this->type);
        }
    }
    qDebug() << "Protocol : Fin receive" ;
}

void Protocol::receiveAddCard()
{
    qDebug() << "Protocol : receiveAddCard" ;
    qDebug() << "Protocol : Fin receiveAddCard" ;
}

void Protocol::receiveInsult()
{
    qDebug() << "Protocol : receiveInsult" ;
    this->string = this->readQString();
    qDebug() << "Protocol : Fin receiveInsult" ;
}

void Protocol::send()
{
    QByteArray qsize;
    QDataStream *qstream;

    qDebug() << "Protocol : send" ;
    //this->writeQuint32(this->data.size());
    qstream = new QDataStream(&qsize, QIODevice::WriteOnly);

    *qstream << this->data.size();
    this->socket->write(qsize);

    this->socket->write(this->data);
    this->data.clear();
    qDebug() << "Protocol : Fin send" ;
}

void Protocol::writeQuint32(const quint32 value)
{
    qDebug() << "Protocol : writeQuint32 : " << value ;
    *(this->out) << value;
    qDebug() << "Protocol : Fin writeQuint32" ;
}

void Protocol::writeQString(const QString value)
{
    qDebug() << "Protocol : writeQString" ;
    *(this->out) << value;
    qDebug() << "Protocol : Fin writeQString" ;
}

quint32 Protocol::readQuint32()
{
    qDebug() << "Protocol : readQuint32" ;
    quint32 value;
    *(this->in) >> value;
    qDebug() << "Protocol : Fin readQuint32" ;
    return value;
}

QString Protocol::readQString()
{
    qDebug() << "Protocol : readQString" ;
    QString value;
    *(this->in) >> value;
    qDebug() << "Protocol : Fin readQString" ;
    return value;
}
