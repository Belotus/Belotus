/* Belotus
 *
 * Dealer.cpp
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

#include "Dealer.h"
#include "Types.h"
#include <algorithm>
#include <QTime>
#include <QtGlobal>

Dealer::Dealer(CardFactory *cardFactory)
    : CardHolder()
{
    CardValue v;
    CardSuit s;

    for(s=HEART; s<=SPADE; s+=0x1000)
    {
        for(v=SEVEN; v<=ACE; v++)
        {
            cards.append(cardFactory->GetCard(v, s));
        }
    }
}

void Dealer::Reset(Deck* deck1, Deck* deck2)
{
    this->cards.clear();

    while(!deck1->IsEmpty())
    {
        this->cards.push_back(deck1->GetBackCard());
    }

    while(!deck2->IsEmpty())
    {
        this->cards.push_back(deck2->GetBackCard());
    }

    this->Cut();
}

bool Dealer::DealEnded() const
{
    return !(this->cards.empty());
}

Card* Dealer::GetCard()
{
    Card* card = this->cards.first();
    cards.removeFirst();
    return card;
}

void Dealer::Cut()
{
    unsigned int count = this->cards.count();
    int iteration = (qrand() % (count - 1)) + 1;
    while(iteration > 0)
    {
        Card* tmp = this->cards.last();
        this->cards.removeLast();
        this->cards.push_front(tmp);
        iteration--;
    }
}

void Dealer::Shuffle()
{
    std::random_shuffle( this->cards.begin(), this->cards.end() );
}

QString Dealer::ToString() const
{
    QList<Card*>::const_iterator cardIndex;
    QString str = "Dealer: ";
    str += QString::number(this->cards.count());
    str += " cards\n";

    for(cardIndex = this->cards.constBegin(); cardIndex != this->cards.constEnd(); cardIndex++)
    {
        str +=  "\t" + (*cardIndex)->ToString() + "\n";
    }

    return str;
}
