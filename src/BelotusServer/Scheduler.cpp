/* Belotus
 *
 * Scheduler.cpp
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

#include "Scheduler.h"

Scheduler::Scheduler(QObject *parent=0)
{
    //connect(const QObject *sender, SIGNAL(unSignal(int*)), this, SLOT(unSlot(int*)));
    connect(this, SIGNAL(s_Card()), this, SLOT(Card()));
    connect(this, SIGNAL(s_GameBeginning()), this, SLOT(GameBeginning()));
    connect(this, SIGNAL(s_NewGame()), this, SLOT(NewGame()));
    connect(this, SIGNAL(s_Pass()), this, SLOT(Pass()));
    connect(this, SIGNAL(s_PlayBeginning()), this, SLOT(PlayBeginning()));
    connect(this, SIGNAL(s_PlayerConnection()), this, SLOT(PlayerConnection()));
    connect(this, SIGNAL(s_PlayerDeconnection()), this, SLOT(PlayerDeconnection()));
    connect(this, SIGNAL(s_QuitGame()), this, SLOT(PlayerDeconnection()));
    connect(this, SIGNAL(s_Take()), this, SLOT(Take()));

    // TODO : Replace the sender (this) by the appropriate sender
}

/*
void Scheduler::unSlot(int *unParametre)
{
    // Traitement unSignal
}
*/

void Scheduler::PlayerConnection()
{
    // TODO
}

void Scheduler::GameBeginning()
{
    // TODO
}

void Scheduler::PlayBeginning()
{
    // TODO
}

void Scheduler::Pass()
{
    // TODO
}

void Scheduler::Take()
{
    // TODO
}

void Scheduler::Card()
{
    // TODO
}

void Scheduler::QuitGame()
{
    // TODO
}

void Scheduler::NewGame()
{
    // TODO
}

void Scheduler::PlayerDeconnection()
{
    // TODO
}

