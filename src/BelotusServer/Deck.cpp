/* Belotus
 *
 * Deck.cpp
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

#include "Deck.h"

Deck::Deck()
    : CardHolder()
{
}

void Deck::AddCard(Card* card)
{
    cards.push_front(card);
}


Card* Deck::GetFrontCard()
{
    return cards.takeFirst();
}

Card* Deck::GetBackCard()
{
    return cards.takeLast();
}

int Deck::GetScore() const
{
    int score = 0;

    QList<Card *>::const_iterator iCard;

    iCard = this->cards.constBegin();
    while(iCard != this->cards.constEnd())
    {
        score += (*iCard)->GetPoints();
        iCard++;
    }

    return score;
}

QString Deck::ToString() const
{
    QString str = "Deck (";
    str += QString::number(this->cards.count());
    str += " cards , ";
    str += QString::number(this->GetScore());
    str += " points)";
    return str;
}
