/* Belotus
 *
 * Protocol.h
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
#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QObject>
#include <QTcpSocket>
#include "CardFactory.h"

#include "Card.h"

class Protocol : public QObject, public Base
{
    Q_OBJECT

public:
    Protocol(QTcpSocket *socket, CardFactory *cardFactory);
    Protocol(QObject *parent, QTcpSocket *socket, CardFactory *cardFactory);
    virtual ~Protocol();

    void    writeQuint32(const quint32 value);
    void    writeQString(const QString value);
    void    writeCard(const Card* card);
    quint32 readQuint32();
    QString readQString();
    Card*   readCard();
    void    send();
    void    MessageProcessed();
    virtual QString ToString() const;

    static const quint32 QUERY_PLAY = 0x00001;//
    static const quint32 QUERY_ADD_CARD = 0x00002;//
    static const quint32 QUERY_INSULT = 0x00003;//
    static const quint32 QUERY_START_GAME = 0x00004;//
    static const quint32 QUERY_REMOVE_CARD = 0x00005;

    static const quint32 ANSWER_ACK = 0x10001;
    static const quint32 ANSWER_FAIL = 0x10002;
    static const quint32 ANSWER_CARD_PLAYED = 0x10003;//
    static const quint32 ANSWER_START_GAME = 0x10004;//
    static const quint32 ANSWER_CHOICE = 0x10005;//
    static const quint32 ANSWER_REMOVE_CARD = 0x10006;

signals:
    void s_MessageReady(quint32 type);

private slots:
    void ReadyRead();

private:
    bool          isReady;
    quint32       messageLength;
    bool          lengthReceived;
    QTcpSocket   *socket;
    QByteArray   *buffer;
    QDataStream  *in;
    QDataStream  *out;
    CardFactory  *cardFactory;

    void    Receive();
    void    Init(QTcpSocket *socket, CardFactory *cardFactory);
};

#endif // PROTOCOL_H
