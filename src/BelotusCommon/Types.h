/* Belotus
 *
 * Types.h
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
#ifndef TYPES_H
#define TYPES_H

#include <qglobal.h>

typedef quint32 CardValue;
typedef quint32 CardSuit;

#define SEVEN 0x0000
#define EIGHT 0x0001
#define NINE 0x0002
#define TEN 0x0003
#define JACK 0x0004
#define QUEEN 0x0005
#define KING 0x0006
#define ACE 0x0007

#define HEART 0x1000
#define DIAMOND 0x2000
#define CLUB 0x3000
#define SPADE 0x4000

#endif // TYPES_H
