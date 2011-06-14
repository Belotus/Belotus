/* Belotus
 *
 * Scheduler.h
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

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QSet>

#include "RemotePlayer.h"
#include "NetworkFrontend.h"
#include "Player.h"

class Scheduler : public QObject, public Base
{
    Q_OBJECT

public:
    Scheduler(QObject *parent);
    virtual ~Scheduler();
    virtual QString ToString() const;
    void Test();

signals:
    //void unSignal(int *unParametre);
    //void s_PlayerConnection(); in NetworkFrontend.h
    void s_AllPlayersConnected();
    void s_GameBeginning();
    void s_PlayBeginning();
    void s_Pass();
    void s_Take();
    void s_Card();
    void s_QuitGame();
    void s_NewGame();
    void s_PlayerDeconnection();


public slots:
    //void unSlot(int *unParametre);
    void PlayerConnection(RemotePlayer *remotePlayer);
    void AllPlayersConnected();
    void GameBeginning();
    void PlayBeginning();
    void Pass();
    void Take();
    void Card();
    void QuitGame();
    void NewGame();
    void PlayerDeconnection();


protected:
    void incomingConnection(int socketfd);

private:
    QVector<Player*> players;
    NetworkFrontend *networkFrontend;
    CardFactory *cardFactory;

    enum State {WFPlayersConnection,
                WFGameBeginning,
                WFPlayBeginning,
                WFTrumpChoice,
                WFCard,
                WFPlayer1Decision,
                End
                };

    State schedulerState;

};

#endif // SCHEDULER_H
