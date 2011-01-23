/* Belotus
 *
 * Base.cpp
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

#include "Base.h"

quint32 Base::ref = 0;

Base::Base(QObject *parent)
    : QObject(parent)
{
    ref++;
}

Base::~Base()
{
    ref--;
}

QString Base::ToString() const
{
    QString s;
    QTextStream stream(&s);
    PrintOn(stream);
    return s;
}

QDebug operator<<(QDebug dbg, const Base *object)
{
    return dbg << object->ToString();
}

/*
QDebug operator<<(QDebug dbg, const Base &object)
{
    return dbg << object.ToString();
}
*/
