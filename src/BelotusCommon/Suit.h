/* Belotus
 *
 * Suit.h
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
#ifndef SUIT_H
#define SUIT_H

#include "../BelotusCommon/Base.h"

typedef enum {
    HEART = 0,
    DIAMOND,
    CLUB,
    SPADE} CardSuit;

class Suit : public Base
{
    Q_OBJECT

public:
    Suit(QObject *parent, CardSuit type);
    Suit(QObject *parent, CardSuit type, bool isTrump);
    CardSuit GetType() const;
    void SetTrump(bool isTrump);
    bool IsTrump() const;

protected:
    virtual QTextStream& PrintOn(QTextStream& stream) const;

private:
    CardSuit suit;
    bool trump;
};

#endif // SUIT_H
