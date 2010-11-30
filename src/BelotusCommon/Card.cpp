/* Belotus
 *
 * Card.cpp
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

#include "Card.h"

using namespace std;

Card::Card(Suit &suit, Value &value) :
    suit(suit), value(value)
{
}

Suit& Card::getSuit() const
{
    return this->suit;
}

Value& Card::getValue() const
{
    return this->value;
}

std::ostream& Card::PrintOn(std::ostream& os) const
{
    return os << "Card(" << this->suit << " , " << this->value << ")";
}

/**
 * operator<:
 * This function compare the power of two Card.
 * Beware, this function doesnt check if the Card is valid in the game
 * Also, this assume that all card are different
 */
bool Card::operator<(Card& card)
{
    if(this->suit.isTrump())
    {
        if(card.suit.isTrump())
        {
            if(this->value.getType() == JACKS) return false;
            if(card.value.getType() == JACKS) return true;
            if(this->value.getType() == NINE) return false;
            if(card.value.getType() == NINE) return true;
            return (this->value < card.value);
        }
        else
        {
            return true;
        }
    }
    else
    {
        if(card.suit.isTrump())
        {
            return false;
        }
        else
        {
            return (this->value < card.value);
        }
    }
}

/**
 * operator>:
 * This function compare the power of two Card.
 * Beware, this function doesnt check if the Card is valid in the game
 * Also, this assume that all card are different
 */
bool Card::operator>(Card& card)
{
    return !(this->operator <(card));
}
