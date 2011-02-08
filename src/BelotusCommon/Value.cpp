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

Value::Value(CardValue value)
    :Base(), value(value)
{
}

CardValue Value::GetValue() const
{
    return this->value;
}

QString Value::ToString() const
{
    switch(this->value) {
    case SEVEN:
    case EIGHT:
    case NINE:
    case TEN:
        return "Value: " + QString::number(this->value);
    case JACK:
        return "Value: Jack";
    case QUEEN:
        return "Value: Queen";
    case KING:
        return "Value: King";
    case ACE:
        return "Value: Ace";
    default:
        return "Error: This Value doens't exist.";
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
