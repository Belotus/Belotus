/* Belotus
 *
 * Suit.cpp
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

#include "Suit.h"

Suit::Suit(CardSuit suit)
    : Base(), suit(suit)
{
}

Suit::Suit(CardSuit suit, bool isTrump)
    :Base(), suit(suit), trump(isTrump)
{
}

CardSuit Suit::GetType() const
{
    return this->suit;
}

void Suit::SetTrump(bool isTrump)
{
    this->trump = isTrump;
}

bool Suit::IsTrump() const
{
    return this->trump;
}

QString Suit::ToString() const
{
    QString str;
    switch(this->suit) {
    case HEART:
        str = "Suit: Heart";
        break;
    case DIAMOND:
        str = "Suit: Diamond";
        break;
    case CLUB:
        str = "Suit: Club";
        break;
    case SPADE:
        str = "Suit: Spade";
        break;
    default:
        return "Error: This Suit doens't exist.";
        break;
    }
    if(this->IsTrump())
    {
        str += " (trump)";
    }
    return str;
}
