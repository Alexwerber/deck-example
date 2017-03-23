#include "DECK.h"
#include "stdio.h"

namespase deck
{
bool isFull(deck &Q)
{
   return Q.length == Nmax;
}

bool isEmpty(deck &Q)
{
   return Q.length == 0;
}

void del(deck &Q)
{
   Q.begin = 0;
   Q.length = 0;
   printf("Дек очищен\n");
}

int popFront(deck &Q)                 // Взятие элемента из начала дека
{
   int datum = 0;
   if(isEmpty(Q))               
      printf("Дек пуст\n");
   else
   {
      datum = Q.elem[Q.begin];
      Q.begin = (Q.begin + 1) % Nmax;
      Q.length -= 1;
      printf("Взятый элемент: %d\n", datum);
   }
   return datum;
}

int popBack(deck &Q)                // Взятие элемента из конца дека
{
   int datum = 0;
   if(isEmpty(Q))               
      printf("Дек пуст\n");
   else
   {
      datum = Q.elem[(Q.begin + Q.length - 1) % Nmax];   
      Q.length -= 1;
      printf("Взятый элемент: %d\n", datum);
   }
   return datum;
}

void pushFront(deck &Q)                   // Добавление элемента в начало дека 
{
   int n, datum;   
   if(isFull(Q))            
      printf("Дек полон\n");
   else
   {   
      printf("Сколько элементов хотите ввести?\n");
      scanf("%d", &n);
      printf("Введите число(а): ");
      for(int i = 0; !isFull(Q) && i < n; i++)
      {
         scanf("%d", &datum);
         Q.begin = (Q.begin - 1 + Nmax) % Nmax;
         Q.elem[Q.begin] = datum;
         Q.length += 1;
      }
   }
}

void pushBack(deck &Q)                          // Добавление элемента в конец дека
{
   int n, datum;   
   if(isFull(Q))            
      printf("Дек полон\n");
   else
   {   
      printf("Сколько элементов хотите ввести?\n");
      scanf("%d", &n);
      printf("Введите число(а): ");
      for(int i = 0; !isFull(Q) && i < n; i++)
      {
         scanf("%d", &datum);
         Q.elem[(Q.begin + Q.length) % Nmax] = datum;
         Q.length += 1;
      }
   }
}
}