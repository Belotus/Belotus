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
 * Access method to the last Card object received.
 * @return: A pointer to the last received Card object, or null if any.
 */
Card* Protocol::getCard() const
{
    qDebug() << "Protocol : getCard" ;
    return this->card;
    qDebug() << "Protocol : Fin getCard" ;
}

/**
 * Access method to the last QString object received.
 * @return: The last received QString object, or null if any.
 */
QString Protocol::getQString() const
{
    qDebug() << "Protocol : getQString" ;
    return this->string;
    qDebug() << "Protocol : Fin getQString" ;
}

/**
 * Build and send the QueryPlay message.
 */
void Protocol::sendQueryPlay()
{
    qDebug() << "Protocol : sendQueryPlay" ;
    this->writeQuint32(this->QUERY_PLAY);
    this->send();
    qDebug() << "Protocol : Fin sendQueryPlay" ;
}

/**
 * Build and send the QueryAddCard message.
 */
void Protocol::sendQueryAddCard(const Card* card)
{
    qDebug() << "Protocol : sendQueryAddCard" ;
    this->writeQuint32(this->QUERY_ADD_CARD);
    this->writeQuint32(card->GetSuit());
    this->writeQuint32(card->GetValue());
    this->send();
    qDebug() << "Protocol : Fin sendQueryAddCard" ;
}

/**
 * Build and send the QueryInsult message.
 */
void Protocol::sendQueryInsult(const QString insult)
{
    qDebug() << "Protocol : sendQueryInsult" ;
    this->writeQuint32(this->QUERY_INSULT);
    this->writeQString(insult);
    this->send();
    qDebug() << "Protocol : Fin sendQueryInsult" ;
}

/**
 * Build and send the AnswerACK message.
 */
void Protocol::sendAnswerACK()
{
    qDebug() << "Protocol : sendAnswerACK" ;
    this->writeQuint32(this->ANSWER_ACK);
    this->send();
    qDebug() << "Protocol : Fin sendAnswerACK" ;
}

/**
 * Build and send the AnswerFAIL message.
 */
void Protocol::sendAnswerFAIL()
{
    qDebug() << "Protocol : sendAnswerFail" ;
    this->writeQuint32(this->ANSWER_FAIL);
    qDebug() << "Protocol : Fin sendAnswerFail" ;
}

/**
 * Build and send the AnswerPlay message.
 */
void Protocol::sendAnswerPlay()
{
    qDebug() << "Protocol : sendAnswerPlay" ;
    this->writeQuint32(this->ANSWER_PLAY);
    qDebug() << "Protocol : Fin sendAnswerPlay" ;
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

/**
 * Decoding method for the AddCard message.
 */
void Protocol::receiveAddCard()
{
    qDebug() << "Protocol : receiveAddCard" ;
    quint32 value = this->readQuint32();
    quint32 suit = this->readQuint32();
    this->card = this->cardFactory->GetCard(value, suit);
    qDebug() << "Card: " << this->card << "\n";
    qDebug() << "Protocol : Fin receiveAddCard" ;
}

/**
 * Decoding method for the Insult message.
 */
void Protocol::receiveInsult()
{
    qDebug() << "Protocol : receiveInsult" ;
    this->string = this->readQString();
    qDebug() << "Insult: " << this->string << "\n";
    qDebug() << "Protocol : Fin receiveInsult" ;
}

/**
 * Send the size and the actual message from the buffer to the socket.
 */
void Protocol::send()
{
    QByteArray qsize;
    QDataStream *qstream;

    qDebug() << "Protocol : send" ;
    qstream = new QDataStream(&qsize, QIODevice::WriteOnly);

    *qstream << this->buffer->size();
    this->socket->write(qsize);

    this->socket->write(*this->buffer);
    this->buffer->clear();

    delete(qstream);
    qDebug() << "Protocol : Fin send" ;
}

/**
 * Helper method to write a quint32 to the buffer.
 */
void Protocol::writeQuint32(const quint32 value)
{
    qDebug() << "Protocol : writeQuint32 : " << value ;
    *(this->out) << value;
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
 * Helper method to read a quint32 to the buffer.
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
 * Helper method to read a QString to the buffer.
 */
QString Protocol::readQString()
{
    qDebug() << "Protocol : readQString" ;
    QString value;
    *(this->in) >> value;
    qDebug() << "Protocol : Fin readQString" ;
    return value;
}
