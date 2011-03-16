/* Belotus
 *
 * CardFactory.cpp
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

#include "CardFactory.h"

CardFactory::CardFactory()
{
    this->suits.append(new Suit(HEART));
    this->suits.append(new Suit(DIAMOND));
    this->suits.append(new Suit(CLUB));
    this->suits.append(new Suit(SPADE));

    this->values.append(new Value(SEVEN));
    this->values.append(new Value(EIGHT));
    this->values.append(new Value(NINE));
    this->values.append(new Value(TEN));
    this->values.append(new Value(JACK));
    this->values.append(new Value(QUEEN));
    this->values.append(new Value(KING));
    this->values.append(new Value(ACE));

    QList<Value*>::iterator valueIndex;
    QList<Suit*>::iterator suitIndex;

    for(suitIndex = this->suits.begin(); suitIndex != this->suits.end(); suitIndex++)
    {
        for(valueIndex = this->values.begin(); valueIndex != this->values.end(); valueIndex++)
        {
            this->cards.append(new Card(*suitIndex, *valueIndex));
        }
    }
}

CardFactory::GetCard(CardValue value, CardSuit suit)
{
    return this->cards.value((quint32) (value & suit));
}

SetTrump(const CardSuit suit)
{
    // TODO
}

CardFactory::ToString()
{
    QString str = "CardFactory: ";
    QMapIterator<int, Card*> i(cards);
    while (i.hasNext())
    {
         i.next();
         str += "\t" + i.value()->ToString() + "\n";
     }

    return str;
}
