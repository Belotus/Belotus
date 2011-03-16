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
//#include "Suit.h"
//#include "Value.h"
#include "Card.h"
#include "Dealer.h"
#include "Scheduler.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "bonjour" << endl;

    /* Test Card, Suit, Value */
    //Suit suit(HEART);
    //Value value(SEVEN);
    //Card card(&suit, &value);
    Card card(HEART, SEVEN);

    //qDebug() << suit << endl << value << endl;
    qDebug() << card << endl;

    /* Test Dealer, Deck */
    Dealer dealer;
    Deck deck1;
    Deck deck2;

    qDebug() << dealer;

    while(!dealer.DealEnded())
    {
        deck1.AddCard(dealer.GetCard());
        deck2.AddCard(dealer.GetCard());
    }

    dealer.Reset(&deck1, &deck2);
    qDebug() << dealer;

    Scheduler scheduler(&a);

    //scheduler.Test();

    return a.exec();
}
