/* Belotus
 *
 * RemotePlayer.h
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

#ifndef REMOTEPLAYER_H
#define REMOTEPLAYER_H

#include <QTcpSocket>
#include "Protocol.h"
#include "CardFactory.h"

#include "Player.h"


class RemotePlayer : public Player
{
    Q_OBJECT

public:
    RemotePlayer(QTcpSocket *socket, CardFactory *cardFactory);
    virtual ~RemotePlayer();
    virtual QString ToString() const;

private slots:
    void Play();
    void AddCard(Card* card);
    void Insult(QString insult);
    void AFGameBeginning();

    void MessageReady(quint32 type);

signals:
    void s_GameBeginning();
    void s_Card(Card* card);

private:
    Protocol *protocol;
};

#endif // REMOTEPLAYER_H
