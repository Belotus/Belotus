/* Belotus
 *
 * Value.h
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
#ifndef VALUE_H
#define VALUE_H

#include "Base.h"

typedef enum {
    SEVEN = 7,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE} CardValue;

class Value : public Base
{
    Q_OBJECT

public:
    Value(QObject *parent, CardValue value);
    CardValue GetValue() const;
    bool operator<(Value& value);
    bool operator>(Value& value);

protected:
    QTextStream& PrintOn(QTextStream& stream) const;

private:
    CardValue value;
};

#endif // VALUE_H
