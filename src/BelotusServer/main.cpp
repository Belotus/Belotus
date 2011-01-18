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
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* Test Card, Suit, Value */
    /*
    Suit *suit = new Suit(HEART);
    Value *value = new Value(SEVEN);
    Card card = Card(suit, value);

    cout << card << endl;

    delete suit;
    delete value;
    */

    /* Test Dealer, Deck */
    /*
    Dealer dealer = Dealer();
    Deck deck1 = Deck();
    Deck deck2 = Deck();

    cout << dealer;

    while(!dealer.DealEnded())
    {
        deck1.AddCard(dealer.GetCard());
        deck2.AddCard(dealer.GetCard());
    }

    dealer.Reset(&deck1, &deck2);
    cout << dealer;
    */

    Scheduler scheduler = Scheduler();
    //return a.exec();
}
