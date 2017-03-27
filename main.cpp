#include <stdio.h>
#include "deck.h"

int main()
{   
   deck Q;
   int n;
   char c;
   bool exitFlag = false;           // Флаг на выход
   do
   {
      printf("<1> - создать пустой дек (очистить дек)\n");
      printf("<2> - проверить, является ли дек пустым\n");
      printf("<3> - добавить элемент(ы) в начало дека\n");
      printf("<4> - добавить элемент(ы) в конец дека\n");
      printf("<5> - взять элемент из начала дека\n");
      printf("<6> - взять элемент из конца дека\n");
      printf("<7> - выход\n");
      bool repFlag = false;                                         // Флаг на повторение программы
      do
      {
         printf("Введите номер команды (от 1 до 7): ");
         if(!scanf("%d", &n))                                     // Проверка введенного значения
         {
            scanf("%c", &c);
            printf("Ошибка ввода \n");
         }
         switch(n)
         {
            case 1 : deck::del(Q); break;
            case 2 : isEmpty(Q) == true ? printf("Дек пуст\n") : printf("Дек не пуст\n"); break;
            case 3 : pushFront(Q); break;
            case 4 : pushBack(Q); break;
            case 5 : popFront(Q); break;
            case 6 : popBack(Q); break;
            case 7 : exitFlag = true; break;
            default : printf("ОШИБКА : неверный номер команды\n");
                      repFlag = true;
         }
      } while(!repFlag && !exitFlag);
   } while(!exitFlag);
}