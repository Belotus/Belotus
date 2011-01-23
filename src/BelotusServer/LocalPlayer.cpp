/* Belotus
 *
 * LocalPlayer.c
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

#include "LocalPlayer.h"

LocalPlayer::LocalPlayer(QObject *parent)
    :Player(parent)
{
}

void LocalPlayer::AddCard(Card* card)
{
    cards.push_front(card);
}

void LocalPlayer::Insult(QString insult)
{
    // TODO
}

Card* LocalPlayer::Play()
{
    return cards.takeFirst();
}

QTextStream& LocalPlayer::PrintOn(QTextStream& stream) const
{
    return stream << "LocalPlayer";
}
