#ifndef TYPES_H
#define TYPES_H

typedef enum {
   SEVEN = 0x0000,
   EIGHT,
   NINE,
   TEN,
   JACK,
   QUEEN,
   KING,
   ACE} CardValue;

typedef enum {
   HEART = 0x1000,
   DIAMOND,
   CLUB,
   SPADE} CardSuit;

#endif // TYPES_H
