/* Belotus
 *
 * Scheduler.h
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

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QSet>

#include "../BelotusCommon/Player.h"

class Scheduler : public QTcpServer
{/*
    Q_OBJECT

public:
    Scheduler(QObject *parent=0);

protected:
    void incomingConnection(int socketfd);
    int run();

private:
    QSet<QTcpSocket*> tcpClients;
    QMap<QTcpSocket*,IPlayer> players;*/

};

#endif // SCHEDULER_H
