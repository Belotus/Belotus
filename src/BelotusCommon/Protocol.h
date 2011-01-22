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

class Protocol : public QObject
{
    Q_OBJECT

public:
    Protocol(QObject *parent, QTcpSocket *socket);

    void MessageProcessed();

signals:
    void s_MessageReady(quint32 *type);

private:
    void send();
    void write(quint32);
    void write(QString*);

public:
    Card* getCard();
    QString* getQString();

private:
    quint32     type;
    QTcpSocket *socket;
    QByteArray  data;
    Card* card;
    QString string;

private:
    static quint32 QUERY_PLAY;
    static quint32 QUERY_ADD_CARD;
    static quint32 QUERY_INSULT;

    static quint32 ANSWER_ACK;
    static quint32 ANSWER_FAIL;
    static quint32 ANSWER_PLAY;

public:
    void sendQueryPlay();
    void sendQueryAddCard(Card* card);
    void sendQueryInsult(QString insult);

    void sendAnswerACK();
    void sendAnswerFAIL();
    void sendAnswerPlay();

private:
    void receiveAddCard();
    void receiveInsult();
};

#endif // PROTOCOL_H
