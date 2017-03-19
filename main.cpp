#include <stdio.h>

const int Nmax = 11;

struct deck
{
   int elem[Nmax], end, begin;
};
deck Q;

bool isFull()                       // Проверка на заполненость
{
   return Q.begin == (Q.end + 1) % Nmax;
}

bool isEmpty()                      // Проверка на пустоту
{
   return Q.begin == Q.end;
}

void del()                    // Очистка дека
{
   Q.begin = 0;
   Q.end = 0;
   printf("Дек очищен\n");
}

int popFront()                 // Взятие элемента из начала дека
{
   int date;
   if(isEmpty())               
      printf("Дек пуст\n");
   else
   {
      date = Q.elem[Q.begin];
      Q.begin = (Q.begin + 1) % Nmax;
      printf("Взятый элемент: %d\n", date);
   }
   return date;
}

int popBack()                // Взятие элемента из конца дека
{
   if(isEmpty())               
      printf("Дек пуст\n");
   else
   {
      Q.end = (Q.end - 1 + Nmax) % Nmax;
      printf("Взятый элемент: %d\n", Q.elem[Q.end]);
   }
   return Q.elem[Q.end];
}

void pushFront()                   // Добавление элемента в начало дека 
{
   int n, data;   
   if(isFull())            
      printf("Дек полон\n");
   else
   {   
      printf("Сколько элементов хотите ввести?\n");
      scanf("%d", &n);
      printf("Введите число(а): ");
      for(int i = 0; !isFull() && i < n; i++)
      {
         scanf("%d", &data);
         Q.begin = (Q.begin - 1 + Nmax) % Nmax;
         Q.elem[Q.begin] = data;
      }
   }
}

void pushBack()                          // Добавление элемента в конец дека
{
   int n, data;   
   if(isFull())            
      printf("Дек полон\n");
   else
   {   
      printf("Сколько элементов хотите ввести?\n");
      scanf("%d", &n);
      printf("Введите число(а): ");
      for(int i = 0; !isFull() && i < n; i++)
      {
         scanf("%d", &data);
         Q.elem[Q.end] = data;
         Q.end = (Q.end + 1) % Nmax;
      }
   }
}

int main()
{   
   int n;
   char c;
   bool exitFlag = false;           // Флаг на выход
   del();
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
            case 1 : del(); break;
            case 2 : isEmpty() == true ? printf("Дек пуст\n") : printf("Дек не пуст\n"); break;
            case 3 : pushFront(); break;
            case 4 : pushBack(); break;
            case 5 : popFront(); break;
            case 6 : popBack(); break;
            case 7 : exitFlag = true; break;
            default : printf("ОШИБКА : неверный номер команды\n");
                      repFlag = true;
         }
      } while(!repFlag && !exitFlag);
   } while(!exitFlag);
}