#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

const int Nmax = 10;

struct deck
{
   int elem[Nmax], begin, length;
};

bool isFull(deck &Q); // Проверка на заполненность

bool isEmpty(deck &Q);  // Проверка на пустоту

void del(deck &Q); // Очистка дека

int popFront(deck &Q);

int popBack(deck &Q);

void pushFront(deck &Q);

void pushBack(deck &Q);

#endif