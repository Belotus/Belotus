/* Belotus
 *
 * Dealer.h
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
#ifndef DEALER_H
#define DEALER_H

#include "CardHolder.h"
#include "Deck.h"

class Dealer : public CardHolder
{
    Q_OBJECT

public:
    Dealer(QObject *parent);
    ~Dealer();
    void Reset(Deck* deck1, Deck* deck2);
    bool DealEnded() const;
    Card* GetCard();
    void SetTrump(const CardSuit suit);

protected:
    virtual QTextStream& PrintOn(QTextStream& stream) const;

private:
    void GenerateSuits();
    void GenerateValues();
    void GenerateCard();
    void Cut();
    void Shuffle();


    QList<Value*> values;
    QList<Suit*> suits;
    int indexDeal;
};

#endif // DEALER_H
