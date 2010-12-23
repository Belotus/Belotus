/* Belotus
 *
 * RemotePlayer.h
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

#ifndef REMOTEPLAYER_H
#define REMOTEPLAYER_H

#include <QTcpSocket>

#include "../BelotusCommon/Player.h"
#include "../BelotusCommon/Base.h"


class RemotePlayer : public Player
{
public:
    RemotePlayer();
    RemotePlayer(QTcpSocket *socket);
private:
    QTcpSocket *socket;

};

#endif // REMOTEPLAYER_H
