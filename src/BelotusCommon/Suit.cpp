/* Belotus
 *
 * Suit.cpp
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

#include "Suit.h"
#include <string>
#include <iostream>

Suit::Suit(SuitType type) :
        type(type)
{
}

SuitType Suit::getType() const {
    return this->type;
}

std::ostream& Suit::PrintOn(std::ostream& os) const {
    std::string typeString;
    switch(this->type) {
    case Heart:
        typeString = "Heart";
        break;
    case Diamond:
        typeString = "Diamond";
        break;
    case Club:
        typeString = "Club";
        break;
    case Spade:
        typeString = "Spade";
        break;
    default:
        typeString = "Error: This Suit doens't exist.";
        break;
    }

    return os << "Suit: " << typeString;
}
