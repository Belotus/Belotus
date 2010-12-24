/* Belotus
 *
 * Value.cpp
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

#include "Value.h"
#include <string>
#include <iostream>

Value::Value(CardValue value) :
        value(value)
{
}

CardValue Value::GetValue() const
{
    return this->value;
}

std::ostream& Value::PrintOn(std::ostream& os) const
{
    switch(this->value) {
    case SEVEN:
    case EIGHT:
    case NINE:
    case TEN:
        return os << "Value: " << this->value;
        break;
    case JACK:
        return os << "Value: Jack";
        break;
    case QUEEN:
        return os << "Value: Queen";
        break;
    case KING:
        return os << "Value: King";
        break;
    case ACE:
        return os << "Value: Ace";
        break;
    default:
        return os << "Error: This Value doens't exist.";
        break;
    }
}

bool Value::operator<(Value& value)
{
    return (this->value < value.value);
}

bool Value::operator>(Value& value)
{
    return (this->value > value.value);
}
