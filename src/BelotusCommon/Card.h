/* Belotus
 *
 * Card.h
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
#ifndef CARD_H
#define CARD_H

#include "Base.h"
#include "Suit.h"
#include "Value.h"
//#include "CardFactory.h"


class Card : public Base
{
public:
    Card(Suit suit, Value value);
    CardSuit GetSuit() const;
    CardValue GetValue() const;
    int GetPoints() const;
    bool IsTrump() const;
    static void SetTrump();
    bool operator<(Card* card);
    bool operator>(Card* card);
    virtual QString ToString() const;

private:
    CardSuit suit;
    CardValue value;
};

#endif // CARD_H
