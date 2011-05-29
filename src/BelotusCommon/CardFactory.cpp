/* Belotus
 *
 * CardFactory.cpp
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

#include "CardFactory.h"

CardFactory::CardFactory()
    : Base()
{
    CardValue v;
    CardSuit s;

    for(v=SEVEN; v<=ACE; v++)
    {
        for(s=HEART; s<=SPADE; s+=0x1000)
        {
            this->cards.insert(v+s,new Card(s,v));
        }
    }
}

CardFactory::~CardFactory()
{
    QMap<quint32, Card*>::iterator i;
    for(i=cards.begin(); i!=cards.end(); ++i)
    {
        delete i.value();
    }
}

Card* CardFactory::GetCard(CardValue value, CardSuit suit)
{
    Q_ASSERT(!cards.isEmpty());
    Q_ASSERT(SEVEN <= value);
    Q_ASSERT(value <= ACE);
    Q_ASSERT(HEART <= suit);
    Q_ASSERT(suit <= SPADE);
    return this->cards.value(value + suit);
}

QString CardFactory::ToString() const
{
    QString str = "CardFactory: \n";
    QMapIterator<quint32, Card*> i(cards);
    while (i.hasNext())
    {
         i.next();
         str += "\t" + i.value()->ToString() + "\n";
     }

    return str;
}
