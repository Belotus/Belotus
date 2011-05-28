/* Belotus
 *
 * Scheduler.cpp
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

#include "Scheduler.h"
#include "time.h"

Scheduler::Scheduler(QObject *parent)
    : QObject(parent), Base()
{
    this->networkFrontend = new NetworkFrontend(this);

    //connect(const QObject *sender, SIGNAL(unSignal(int*)), this, SLOT(unSlot(int*)));
    connect(this, SIGNAL(s_Card()), this, SLOT(Card()));
    connect(this, SIGNAL(s_GameBeginning()), this, SLOT(GameBeginning()));
    connect(this, SIGNAL(s_NewGame()), this, SLOT(NewGame()));
    connect(this, SIGNAL(s_Pass()), this, SLOT(Pass()));
    connect(this, SIGNAL(s_PlayBeginning()), this, SLOT(PlayBeginning()));
    connect(this->networkFrontend, SIGNAL(s_PlayerConnection(RemotePlayer *)), this, SLOT(PlayerConnection(RemotePlayer *)));
    connect(this, SIGNAL(s_PlayerDeconnection()), this, SLOT(PlayerDeconnection()));
    connect(this, SIGNAL(s_QuitGame()), this, SLOT(PlayerDeconnection()));
    connect(this, SIGNAL(s_Take()), this, SLOT(Take()));

    // TODO : Replace the sender (this) by the appropriate sender
}

void Scheduler::PlayerConnection(RemotePlayer *remotePlayer)
{
    // TODO
    qDebug() << "Scheduler : PlayerConnection ( " << time(0) << " )" << endl ;
    qDebug() << remotePlayer << endl;

    players.append(remotePlayer);
}

void Scheduler::GameBeginning()
{
    // TODO
    qDebug() << "Scheduler : GameBeginning ( " << time(0) << " )" << endl ;
}

void Scheduler::PlayBeginning()
{
    // TODO
    qDebug() << "Scheduler : PlayBeginning ( " << time(0) << " )" << endl ;
}

void Scheduler::Pass()
{
    // TODO
    qDebug() << "Scheduler : Pass ( " << time(0) << " )" << endl ;
}

void Scheduler::Take()
{
    // TODO
    qDebug() << "Scheduler : Take ( " << time(0) << " )" << endl ;
}

void Scheduler::Card()
{
    // TODO
    qDebug() << "Scheduler : Card ( " << time(0) << " )" << endl ;
}

void Scheduler::QuitGame()
{
    // TODO
    qDebug() << "Scheduler : QuitGame ( " << time(0) << " )" << endl ;
}

void Scheduler::NewGame()
{
    // TODO
    qDebug() << "Scheduler : NewGame ( " << time(0) << " )" << endl ;
}

void Scheduler::PlayerDeconnection()
{
    // TODO
    qDebug() << "Scheduler : PlayerDeconnection ( " << time(0) << " )" << endl ;
}

void Scheduler::incomingConnection(int socketfd)
{
    // TODO
    qDebug() << "Scheduler : incomingConnection ( " << time(0) << " )" << endl ;
}

void Scheduler::Test()
{
    /*
    emit s_PlayerConnection();
    emit s_GameBeginning();
    emit s_PlayBeginning();
    emit s_Pass();
    emit s_Take();
    emit s_Card();
    emit s_QuitGame();
    emit s_NewGame();
    emit s_PlayerDeconnection();
    */
}

QString Scheduler::ToString() const
{
    return "Scheduler";
}
