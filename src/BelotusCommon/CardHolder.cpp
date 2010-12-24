/* Belotus
 *
 * CardHolder.cpp
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

#include "CardHolder.h"

CardHolder::CardHolder()
{
}

bool CardHolder::IsEmpty() const
{
    return this->cards.isEmpty();
}

bool CardHolder::HasSuit(CardSuit suit) const
{
    QList<Card *>::const_iterator iCard;

    for(iCard = this->cards.constBegin(); iCard != this->cards.constEnd(); iCard++)
    {
        if((*iCard)->GetSuit()->GetType() == suit)
        {
            return true;
        }
    }
    return false;
}


std::ostream& CardHolder::PrintOn(std::ostream& os) const
{
    return os << "CardHolder(" << this->cards.count() << " elements)";
}
