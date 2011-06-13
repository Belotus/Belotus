/* Belotus
 *
 * NetworkFrontend.h
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
#ifndef NetworkFrontend_H
#define NetworkFrontend_H

#include <QTcpServer>
#include "RemotePlayer.h"
#include "CardFactory.h"

class NetworkFrontend : public QTcpServer, public Base
{
    Q_OBJECT

public:
    NetworkFrontend(QObject *parent, CardFactory *cardFactory);
    virtual QString ToString() const;

private:
    CardFactory *cardFactory;

signals:
    void s_PlayerConnection(RemotePlayer *remotePlayer);

private slots:
    void NewConnection();
};

#endif // NetworkFrontend_H
