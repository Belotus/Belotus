/* Belotus
 *
 * Suit.h
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
#ifndef SUIT_H
#define SUIT_H

#include "Base.h"
#include "Types.h"

class Suit : public Base
{
public:
    Suit(CardSuit suit);
    Suit(CardSuit suit, bool isTrump);
    CardSuit GetSuit() const;
    static CardSuit GetTrump();
    static void SetTrump(const CardSuit suit);
    bool IsTrump() const;
    virtual QString ToString() const;

private:
    CardSuit suit;
    static CardSuit trumpSuit;
};

#endif // SUIT_H
