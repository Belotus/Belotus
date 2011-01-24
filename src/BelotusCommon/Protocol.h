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

#include "../BelotusCommon/Card.h"

class Protocol : public Base
{
    Q_OBJECT

public:
    Protocol(QObject *parent, QTcpSocket *socket);

    void    MessageProcessed();
    Card*   getCard();
    QString getQString();

    void sendQueryPlay();
    void sendQueryAddCard(Card* card);
    void sendQueryInsult(QString insult);

    void sendAnswerACK();
    void sendAnswerFAIL();
    void sendAnswerPlay();

protected:
    virtual QTextStream& PrintOn(QTextStream& stream) const;

signals:
    void s_MessageReady(quint32 *type);

private slots:
    void ReadyRead();

private:
    bool        isReady;
    quint32     messageLength;
    quint32     type;
    QTcpSocket *socket;
    QByteArray  data;
    Card       *card;
    QString     string;

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
    void    writeQuint32(quint32 value);
    void    writeQString(QString value);
    quint32 readQuint32();
    QString readQString();
};

#endif // PROTOCOL_H
