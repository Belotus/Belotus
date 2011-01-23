/* Belotus
 *
 * main.cpp
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

#include <QtCore/QCoreApplication>
#include "../BelotusCommon/Suit.h"
#include "../BelotusCommon/Value.h"
#include "../BelotusCommon/Card.h"
#include "Dealer.h"
#include "Scheduler.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* Test Card, Suit, Value */
    Suit *suit = new Suit(&a, HEART);
    Value *value = new Value(&a, SEVEN);
    Card *card = new Card(&a, suit, value);

    qDebug() << card << endl;

    delete suit;
    delete value;
    delete card;


    /* Test Dealer, Deck */
    Dealer *dealer = new Dealer(&a);
    Deck *deck1 = new Deck(&a);
    Deck *deck2 = new Deck(&a);

    qDebug() << dealer;

    while(!dealer->DealEnded())
    {
        deck1->AddCard(dealer->GetCard());
        deck2->AddCard(dealer->GetCard());
    }

    dealer->Reset(deck1, deck2);
    qDebug() << dealer;

    Scheduler scheduler;

    scheduler.Test();
    //return a.exec();
}
