/* Belotus
 *
 * Base.h
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
#ifndef BASE_H_
#define BASE_H_

#include <QString>
#include <QDebug>
#include <QTextStream>

class Base{
public:
    Base();
    virtual ~Base();

    static quint32 GetRef();

    virtual QString ToString() const = 0;
private:
    static quint32 ref;
};

QDebug operator<<(QDebug dbg, const Base &object);

#endif /* BASE_H_ */
