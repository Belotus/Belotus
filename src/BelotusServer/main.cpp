/* Belotus
 *
 * main.cpp
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

#include <QtCore/QCoreApplication>
#include "Card.h"
#include "Dealer.h"
#include "Scheduler.h"
#include "CardFactory.h"
#include "ConfigServer.h"

using namespace std;

void readArgs(int argc, char *argv[]);
void msgHandler( QtMsgType t, const char * message );
void test();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInstallMsgHandler(msgHandler);

    ConfigServer::debug_level = 4;
    ConfigServer::network_port = 4242;

    readArgs(argc, argv);


    CardFactory cardFactory;
    Dealer dealer(&cardFactory);
    Deck deck1;
    Deck deck2;

    Scheduler scheduler(&a);

    //test();
    //scheduler.Test();

    return a.exec();
}

void readArgs(int argc, char *argv[])
{
    int c;
    while((c = getopt(argc, argv, "vp:")) != -1)
    {
        switch(c)
        {
        case 'v':
            ConfigServer::debug_level = 4;
            break;
        case 'p':
            ConfigServer::network_port = (quint32) atoi(optarg);
            break;
        }
    }
}

void msgHandler( QtMsgType t, const char * message )
{
    bool print = FALSE;
    switch(t)
    {
    case QtDebugMsg:
        if(ConfigServer::debug_level >= 4)
            print = TRUE;
        break;
    case QtWarningMsg:
        if(ConfigServer::debug_level >= 3)
            print = TRUE;
        break;
    case QtCriticalMsg:
        if(ConfigServer::debug_level >= 2)
            print = TRUE;
        break;
    case QtFatalMsg:
        if(ConfigServer::debug_level >= 1)
            print = TRUE;
        break;
    }

    if ( print && message && *message )
        fprintf( stderr, "%s\n", message );
}

void test()
{
    CardFactory cardFactory;
    Dealer dealer(&cardFactory);
    Deck deck1;
    Deck deck2;

    qDebug() << cardFactory;
    qDebug() << dealer;

    while(!dealer.DealEnded())
    {
        deck1.AddCard(dealer.GetCard());
        deck2.AddCard(dealer.GetCard());
    }

    qDebug() << deck1;
    qDebug() << deck2;

    dealer.Reset(&deck1, &deck2);
    qDebug() << dealer;
}
