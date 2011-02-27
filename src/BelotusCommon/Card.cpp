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

Card::Card(CardSuit suit, CardValue value)
    :Base()
{
    this->suit = suit;
    this->value = value;
}

CardSuit Card::GetSuit() const
{
    return this->suit;
}

CardValue Card::GetValue() const
{
    return this->value;
}

int Card::GetPoints() const
{
    switch(this->value)
    {
    case SEVEN :
    case EIGHT :
        return 0;
    case NINE :
        if(this->IsTrump())
        {
            return 14;
        }
        else
        {
            return 0;
        }
    case TEN :
        return 10;
    case JACK :
        if(this->IsTrump())
        {
            return 20;
        }
        else
        {
            return 2;
        }
     case QUEEN :
        return 3;
     case KING :
        return 4;
     case ACE :
        return 11;
     default :
        return 0;
    }
}

QString Card::ToString() const
{
    QString str = "Card(";
    str += this->suit->ToString();
    str += " , ";
    str += this->value->ToString();
    str += ", ";
    str += QString::number(this->GetPoints());
    str += " points)";
    return str;
}

/**
 * operator<:
 * This function compare the power of two Card.
 * Beware, this function doesnt check if the Card is valid in the game
 * Also, this assume that all card are different
 */
bool Card::operator<(Card* card)
{
    if(this->IsTrump())
    {
        if(card->IsTrump())
        {
            if(this->GetValue() == JACK) return false;
            if(card->GetValue() == JACK) return true;
            if(this->GetValue() == NINE) return false;
            if(card->GetValue() == NINE) return true;
            return (this->value < card->value);
        }
        else
        {
            return true;
        }
    }
    else
    {
        if(card->suit->IsTrump())
        {
            return false;
        }
        else
        {
            return (this->value < card->value);
        }
    }
}

/**
 * operator>:
 * This function compare the power of two Card.
 * Beware, this function doesnt check if the Card is valid in the game
 * Also, this assume that all card are different
 */
bool Card::operator>(Card* card)
{
    return !(this->operator <(card));
}
