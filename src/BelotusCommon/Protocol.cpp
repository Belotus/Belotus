/* Belotus
 *
 * Protocol.cpp
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

#include "Protocol.h"


 /**********************************************************************
 * Public methods                                                      *
 **********************************************************************/

/**
 * Constructor with no parenting
 * @param socket A pointer to the socket to use
 */
Protocol::Protocol(QTcpSocket *socket, CardFactory *cardFactory)
{
    Protocol(NULL, socket, cardFactory);
}

/**
 * Constructor
 * @param parent The QObject parent, or NULL
 * @param socket A pointer to the socket to use
 */
Protocol::Protocol(QObject *parent, QTcpSocket *socket, CardFactory *cardFactory)
    : QObject(parent), Base(), isReady(true), messageLength(0),
    lengthReceived(false), socket(socket), cardFactory(cardFactory)
{
    qDebug() << "Protocol : Constructeur" ;
    this->buffer = new QByteArray();
    this->out = new QDataStream(this->buffer, QIODevice::WriteOnly);
    this->in = new QDataStream(this->socket);
    connect(this->socket, SIGNAL(readyRead()), this, SLOT(ReadyRead()));
    qDebug() << "Protocol : Fin constructeur" ;
}

/**
 * Destructor
 */
Protocol::~Protocol()
{
    delete(this->in);
    delete(this->out);
    delete(this->buffer);
    delete(this->socket);
}

/**
 * Indicate to the Protocol that the message has been processed, so a new message can be received and processed.
 */
void Protocol::MessageProcessed()
{
    qDebug() << "Protocol : MessageProcessed" ;
    this->isReady = true;
    this->messageLength = 0;
    this->lengthReceived = false;
    this->receive();
    qDebug() << "Protocol : Fin MessageProcessed" ;
}


/**
 * Helper method to write a quint32 to the buffer.
 */
void Protocol::writeQuint32(const quint32 value)
{
    qDebug() << "Protocol : writeQuint32 : " << value ;
    *(this->out) << (quint32) value;
    qDebug() << "Protocol : Fin writeQuint32" ;
}

/**
 * Helper method to write a QString to the buffer.
 */
void Protocol::writeQString(const QString value)
{
    qDebug() << "Protocol : writeQString" ;
    *(this->out) << value;
    qDebug() << "Protocol : Fin writeQString" ;
}

/**
 * Helper method to write a Card to the buffer.
 */
void Protocol::writeCard(const Card* card)
{
    qDebug() << "Protocol : writeCard" ;
    *(this->out) << card->GetValue();
    *(this->out) << card->GetSuit();
    qDebug() << "Protocol : Fin writeCard" ;
}

/**
 * Helper method to read a quint32 from the buffer.
 */
quint32 Protocol::readQuint32()
{
    qDebug() << "Protocol : readQuint32" ;
    quint32 value;
    *(this->in) >> value;
    qDebug() << "Protocol : Fin readQuint32" ;
    return value;
}

/**
 * Helper method to read a QString from the buffer.
 */
QString Protocol::readQString()
{
    qDebug() << "Protocol : readQString" ;
    QString value;
    *(this->in) >> value;
    qDebug() << "Protocol : Fin readQString" ;
    return value;
}

/**
 * Helper method to read a Card from the buffer.
 */
Card* Protocol::readCard()
{
    qDebug() << "Protocol : readCard" ;
    quint32 value = this->readQuint32();
    quint32 suit = this->readQuint32();
    Card* card = this->cardFactory->GetCard(value, suit);
    qDebug() << "Protocol : Fin readCard" ;
    return card;
}

/**
 * Send the size and the actual message from the buffer to the socket.
 */
void Protocol::send()
{
    QByteArray qsize;
    QDataStream *qstream;

    qstream = new QDataStream(&qsize, QIODevice::WriteOnly);

    qDebug() << "Protocol : send" ;

    *qstream << this->buffer->size();
    this->socket->write(qsize);

    this->socket->write(*this->buffer);
    this->buffer->clear();

    delete qstream;
    qDebug() << "Protocol : Fin send" ;
}

/**
 * The printing mechanisme, inherited from Base.
 */
QString Protocol::ToString() const
{
    return "Protocol : PrintOn";
}

/**********************************************************************
* Private slots                                                       *
**********************************************************************/

/**
 * Slot for the ReadyRead signal of the socket.
 */
void Protocol::ReadyRead()
{
    qDebug() << "Protocol : ReadyRead" ;
    this->receive();
    qDebug() << "Protocol : Fin ReadyRead" ;
}

/**********************************************************************
* Private methods                                                     *
**********************************************************************/

/**
 * Check if a message is completly received. If yes, the message is readed from the socket and decoded.
 */
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
            quint32 type = readQuint32();
            this->isReady = false;

            emit this->s_MessageReady(type);
        }
    }
    qDebug() << "Protocol : Fin receive" ;
}
