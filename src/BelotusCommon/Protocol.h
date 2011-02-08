/* Belotus
 *
 * Protocol.h
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
#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QObject>
#include <QTcpSocket>

#include "Card.h"

class Protocol : public QObject, public Base
{
    Q_OBJECT

public:
    Protocol(QTcpSocket *socket);
    Protocol(QObject *parent, QTcpSocket *socket);
    virtual ~Protocol();

    void    MessageProcessed();
    Card*   getCard() const;
    QString getQString() const;

    void sendQueryPlay();
    void sendQueryAddCard(const Card* card);
    void sendQueryInsult(const QString insult);

    void sendAnswerACK();
    void sendAnswerFAIL();
    void sendAnswerPlay();

    virtual QString ToString() const;

signals:
    void s_MessageReady(quint32 *type);

private slots:
    void ReadyRead();

private:
    bool          isReady;
    quint32       messageLength;
    bool          lengthReceived;
    quint32       type;
    QTcpSocket   *socket;
    QByteArray    buffer;
    QDataStream  *in;
    QDataStream  *out;
    Card         *card;
    QString       string;

    static const quint32 QUERY_PLAY = 0x00001;
    static const quint32 QUERY_ADD_CARD = 0x00002;
    static const quint32 QUERY_INSULT = 0x00003;

    static const quint32 ANSWER_ACK = 0x10001;
    static const quint32 ANSWER_FAIL = 0x10002;
    static const quint32 ANSWER_PLAY = 0x10003;

    void    receive();
    void    receiveAddCard();
    void    receiveInsult();
    void    send();
    void    writeQuint32(const quint32 value);
    void    writeQString(const QString value);
    quint32 readQuint32();
    QString readQString();
};

#endif // PROTOCOL_H
