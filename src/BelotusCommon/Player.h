/* Belotus
 *
 * Player.h
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
#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "CardHolder.h"

class Player : public QObject, public CardHolder
{
    Q_OBJECT

public:
    Player();
    virtual void Play()=0;  // =0 pour dire qu'on implémente pas ça dans Player.cpp (standard pour les méthodes virtuelles)
    virtual void AddCard(Card* card)=0;
    virtual void Insult(QString insult)=0;
    virtual void AFGameBeginning()=0;
    virtual QString ToString() const = 0;

};

#endif // PLAYER_H
