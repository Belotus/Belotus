/* Belotus
 *
 * Dealer.cpp
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

#include "Dealer.h"
#include <algorithm>
#include <QTime>
#include <QtGlobal>

Dealer::Dealer()
    : CardHolder(), indexDeal(0)
{
    QTime time = QTime::currentTime ();
    qsrand(time.hour() + time.minute() + time.msec());

    //this->GenerateSuits();
    //this->GenerateValues();
    //this->GenerateCard();
    //this->Shuffle();
    //this->Cut();
}

Dealer::~Dealer()
{
    while(!this->cards.empty())
    {
        delete this->cards.first();
        this->cards.pop_front();
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
    indexDeal = 0;
}

bool Dealer::DealEnded() const
{
    return (this->indexDeal >= this->cards.count());
}

Card* Dealer::GetCard()
{
    Card* card = this->cards.at(this->indexDeal);
    indexDeal++;
    return card;
}

void Dealer::SetTrump(const CardSuit suit)
{
    CardFactory::SetTrump(suit);
}

/*
void Dealer::GenerateSuits()
{
    this->suits.append(new Suit(HEART));
    this->suits.append(new Suit(DIAMOND));
    this->suits.append(new Suit(CLUB));
    this->suits.append(new Suit(SPADE));
}

void Dealer::GenerateValues() {
    this->values.append(new Value(SEVEN));
    this->values.append(new Value(EIGHT));
    this->values.append(new Value(NINE));
    this->values.append(new Value(TEN));
    this->values.append(new Value(JACK));
    this->values.append(new Value(QUEEN));
    this->values.append(new Value(KING));
    this->values.append(new Value(ACE));
}
*/

/*
void Dealer::GenerateCard()
{
    // V1
    QList<Value*>::iterator valueIndex;
    QList<Suit*>::iterator suitIndex;

    for(suitIndex = this->suits.begin(); suitIndex != this->suits.end(); suitIndex++)
    {
        for(valueIndex = this->values.begin(); valueIndex != this->values.end(); valueIndex++)
        {
            this->cards.append(new Card(*suitIndex, *valueIndex));
        }
    }
    // V2
    CardValue *p_cv;
    CardSuit *p_cs;
    quint32 *v;
    quint32 *s;

    for (*v = SEVEN; *v <= ACE; (*v)++)
    {
        for (*s = HEART; *s <= SPADE; (*s)++)
        {
            p_cv = (CardValue*)v;
            p_cs = (CardSuit*)s;
            this->cards.append(new Card(*p_cs, *p_cv));
        }
    }
}
*/

void Dealer::Cut()
{
    unsigned int count = this->cards.count();
    int iteration = (qrand() % (count - 1)) + 1;
    while(iteration > 0)
    {
        Card* tmp = this->cards.takeLast();
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
