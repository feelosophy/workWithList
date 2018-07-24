#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int next[15], previous[15], pointer;
char list[15];

void print();

void printing();

void printList();

int error(int);

int start();

void clear();

void isEmpty();

void toStart();

void toEnd();

void isStart();

void isEnd();

void goNext();

void goBack();

void showBeforePointer();

void showAfterPointer();

void delBeforePointer();

void delAfterPointer();

char takeBeforePointer();

char takeAfterPointer();

char checkInput();

void changeBeforePointer();

void changeAfterPointer();

void addBeforePointer();

void addAfterPointer();

int isInputCorrect();

int isInputCorrectFirst();

void menu();

int main(){
  system("chcp 65001");
  system("cls");
  menu();
  return 1;
}

void menu(){
  int func, pass = 0, metka;
  char c = EOF, taked;
  while (1){
    system("cls");
    print();
    if (pass){
      printing();
      if (pointer != 0)
        printList();
      printf("Рабочий указатель стоит на ячейке: %d\n\n", pointer+1);
      if (pointer == 0)
        printf("Список пуст\n\n");
      if (c != EOF)
        printf("\nВзятый элемент: %c\n\n", c);
    }

    printf("Ввод: ");
    func = isInputCorrect();
    if (func == -1){
      printf("\nНекорректный ввод!\n\n");
      getch();
      continue;
    }
    switch (func){
    case 1:
      {
        if (pass){
          printf("\nНедопустимая операция\n");
          getch();
          continue;
        }
        metka = start();
        if (metka == -1){
          printf("\nПароль неверен!\n");
          getch();
          continue;
        }
        pass++;
        clear();
        continue;
      }

    case 2:
      {
        if ((metka = error(pass)) == -1)
          continue;
        if (pointer == 0){
          printf("\nСписок пуст\n");
          getch();
          continue;
        }
        clear();
        getch();
        continue;
      }
    case 3:
      {
        if ((metka = error(pass)) == -1)
          continue;
        isEmpty();
        getch();
        continue;
      }
    case 4:
      {
        if ((metka = error(pass)) == -1)
          continue;
        toStart();
        getch();
        continue;
      }
    case 5:
      {
        if ((metka = error(pass)) == -1)
          continue;
        toEnd();
        getch();
        continue;
      }
    case 6:
      {
        if ((metka = error(pass)) == -1)
          continue;
        isStart();
        getch();
        continue;
      }
    case 7:
      {
        if ((metka = error(pass)) == -1)
          continue;
        isEnd();
        getch();
        continue;
      }
    case 8:
      {
        if ((metka = error(pass)) == -1)
          continue;
        goNext();
        getch();
        continue;
      }
    case 9:
      {
        if ((metka = error(pass)) == -1)
          continue;
        goBack();
        getch();
        continue;
      }
    case 10:
      {
        if ((metka = error(pass)) == -1)
          continue;
        showBeforePointer();
        getch();
        continue;
      }
    case 11:
      {
        if ((metka = error(pass)) == -1)
          continue;
        showAfterPointer();
        getch();
        continue;
      }
    case 12:
      {
        if ((metka = error(pass)) == -1)
          continue;
        delBeforePointer();
        getch();
        continue;
      }
    case 13:
      {
        if ((metka = error(pass)) == -1)
          continue;
        delAfterPointer();
        getch();
        continue;
      }
    case 14:
      {
        if ((metka = error(pass)) == -1)
          continue;
        taked = takeBeforePointer();
        if (taked != EOF)
          c = taked;
        getch();
        continue;
      }
    case 15:
      {
        if ((metka = error(pass)) == -1)
          continue;
        taked = takeAfterPointer();
        if (taked != EOF)
          c = taked;
        getch();
        continue;
      }
    case 16:
      {
        if ((metka = error(pass)) == -1)
          continue;
        changeBeforePointer();
        getch();
        continue;
      }
    case 17:
      {
        if ((metka = error(pass)) == -1)
          continue;
        changeAfterPointer();
        getch();
        continue;
      }
    case 18:
      {
        if ((metka = error(pass)) == -1)
          continue;
        addBeforePointer();
        getch();
        continue;
      }
    case 19:
      {
        if ((metka = error(pass)) == -1)
          continue;
        addAfterPointer();
        getch();
        continue;
      }
    default:;
    }
    break;
  }
}

void print(){
  printf("1.Начать работу со списком\n");
  printf("2.Сделать список пустым\n");
  printf("3.Проверка: пуст или не пуст список\n");
  printf("4.Установить раб. указатель в начало списка\n");
  printf("5.Установить раб. указатель в конец списка\n");
  printf("6.Рабочий указатель в начале списка?\n");
  printf("7.Рабочий указатель в конце списка?\n");
  printf("8.Передвинуть раб. указатель списка вперед\n");
  printf("9.Передвинуть раб. указатель списка назад\n");
  printf("10.Показать значение элемента списка перед указателем\n");
  printf("11.Показать значение элемента списка за указателем\n");
  printf("12.Удалить элемент до указателя\n");
  printf("13.Удалить элемент за указателем\n");
  printf("14.Взять элемент до указателя\n");
  printf("15.Взять элемент за указателем\n");
  printf("16.Изменить значение элемента до указателя\n");
  printf("17.Изменить значение элемента за указателем\n");
  printf("18.Добавить элемент до указателя\n");
  printf("19.Добавить элемент за указателем\n");
  printf("20.Закончить работу со списком\n\n\n");

}

void printing(){
  printf("                               1   2   3   4   5   6   7   8   9   10  11  12  13  14  15\n\n");

  printf("Данные                         %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c \n\n", list[0], list[1], list[2], list[3], list[4], list[5], list[6], list[7], list[8], list[9], list[10], list[11], list[12], list[13], list[14]);

  printf("Прямая последовательность:    %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d \n\n", next[0] + 1, next[1] + 1, next[2] + 1, next[3] + 1, next[4] + 1, next[5] + 1, next[6] + 1, next[7] + 1, next[8] + 1, next[9] + 1, next[10] + 1, next[11] + 1, next[12] + 1, next[13] + 1, next[14] + 1);

  printf("Обратная последовательность   %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d  %2d \n\n", previous[0] + 1, previous[1] + 1, previous[2] + 1, previous[3] + 1, previous[4] + 1, previous[5] + 1, previous[6] + 1, previous[7] + 1, previous[8] + 1, previous[9] + 1, previous[10] + 1, previous[11] + 1, previous[12] + 1, previous[13] + 1, previous[14] + 1);

  printf("\n\n");
}

void printList(){
  int poi;
  printf("Прямой ход: ");
  poi = next[0];
  while (poi != 0){
    printf("%c", list[poi]);
    poi = next[poi];
  }

  printf("\n\nОбратный ход: ");
  poi = previous[0];
  while (poi != 0){
    printf("%c", list[poi]);
    poi = previous[poi];
  }
  printf("\n\n");
}

int error(int pass){
  if (!pass){
    printf("\nВы не начали работу со списком\n");
    getch();
    return -1;
  }
  return 1;
}

int start(){
  char mass[15], c;
  int i = 0, res;
  printf("\nВведите пароль: ");
  while ((c = getchar()) != '\n'){ * (mass + i) = c;
    i++;
  } * (mass + i) = '\0';
  res = strcmp(mass, "password");
  if (res)
    return -1;
  return 1;
}

void clear(){
  int i = 0;
  next[i] = 0;
  previous[i] = 0;
  list[i] = ' ';
  for (i = 1; i < 14; i++){
    list[i] = ' ';
    next[i] = i + 1;
    previous[i] = i + 1;
  }
  list[i] = ' ';
  next[i] = 1;
  previous[i] = 1;
  pointer = next[0];
  printf("\nТеперь список пуст!\n");
}

void isEmpty(){
  if (next[0] != 0)
    printf("\nСписок не является пустым\n");
  else
    printf("\nСписок пуст\n");
}

void toStart(){
  int res = pointer;
  pointer = next[0];
  if (pointer == 0)
    printf("\nНедопустимая операция, список пуст\n");
  else {
    if (res == pointer){
      printf("\nУказатель уже в начале\n");
    } else
      printf("\nУказатель установлен на начало\n");
  }
}

void toEnd(){
  int res = pointer;
  pointer = previous[0];
  if (pointer == 0)
    printf("\nНедопустимая операция, список пуст\n");
  else {
    if (res == pointer){
      printf("\nУказатель уже в конце\n");
    } else
      printf("\nУказатель установлен на конец\n");
  }
}

void isStart(){
  if (pointer == next[0]){
    if (pointer == 0)
      printf("\nНедопустимая операция, список пуст\n");
    else
      printf("\nРабочий указатель в начале списка\n");
  } else
    printf("\nРабочий указатель НЕ в начале списка\n");
}

void isEnd(){
  if (pointer == previous[0]){
    if (pointer == 0)
      printf("\nНедопустимая операция, список пуст\n");
    else
      printf("\nРабочий указатель в конце списка\n");
  } else
    printf("\nРабочий указатель НЕ в конце списка\n");
}

void goNext(){
  int res;
  if (pointer == 0)
    printf("\nНедопустимая операция, список пуст\n");
  else {
    res = next[pointer];
    if (res == 0)
      printf("\nНедопустимая операция, рабочий указатель находится в конце\n");
    else {
      pointer = res;
      printf("\nРабочий указатель передвинут\n");
    }
  }
}

void goBack(){
  int res;
  if (pointer == 0)
    printf("\nНедопустимая операция, список пуст\n");
  else {
    res = previous[pointer];
    if (res == 0)
      printf("\nНедопустимая операция, указатель в начале\n");
    else {
      pointer = res;
      printf("\nРабочий указатель передвинут\n");
    }
  }
}

void showBeforePointer(){
  int res;
  if (pointer == 0)
    printf("\nНедопустимая операция, список пуст\n");
  else {
    res = previous[pointer];
    if (res == 0)
      printf("\nНедопустимая операция, рабочий указатель в начале\n");
    else {
      printf("\nЭлемент находящийся перед указателем: %c", list[res]);
    }
  }
}

void showAfterPointer(){
  int res;
  if (pointer == 0)
    printf("\nНедопустимая операция, список пуст\n");
  else {
    res = next[pointer];
    if (res == 0)
      printf("\nНедопустимая операция -- рабочий указатель в конце\n");
    else {
      printf("\nЭлемент за указателем: %c", list[res]);
    }
  }
}

void delBeforePointer(){
  int res;
  int i;
  if (pointer == 0)
    printf("\nНедопустимая операция, список пуст\n");
  else {
    res = previous[pointer];
    if (res == 0)
      printf("\nНедопустимая операция -- рабочий указатель в начале\n");
    else {
      for (i = 0; i < 15; i++){
        if (next[i] == res){
          next[i] = pointer;
          break;
        }
      }
      for (i = 0; i < 15; i++){
        if (next[i] == 1){
          next[i] = res;
          next[res] = 1;
          break;
        }
      }
      list[res] = ' ';
      previous[pointer] = previous[res];
      for (i = 0; i < 15; i++){
        if (previous[i] == 1){
          previous[i] = res;
          previous[res] = 1;
          break;
        }
      }
      printf("\n\nЭлемент удален\n");
    }
  }
}

void delAfterPointer(){
  int res;
  int i;
  if (pointer == 0)
    printf("\nНедопустимая операция, список пуст\n");
  else {
    res = next[pointer];
    if (res == 0)
      printf("\nНедопустимая операция, рабочий указатель в конце\n");
    else {
      for (i = 0; i < 15; i++){
        if (previous[i] == res){
          previous[i] = pointer;
          break;
        }
      }
      for (i = 0; i < 15; i++){
        if (previous[i] == 1){
          previous[i] = res;
          previous[res] = 1;
          break;
        }
      }
      list[res] = ' ';
      next[pointer] = next[res];
      for (i = 0; i < 15; i++){
        if (next[i] == 1){
          next[i] = res;
          next[res] = 1;
          break;
        }
      }
      printf("\n\nЭлемент удален\n");
    }
  }
}

char takeBeforePointer(){
  int res;
  char c;
  if (pointer == 0)
    printf("\nНедопустимая операция, список пуст\n");
  else {
    res = previous[pointer];
    if (res == 0)
      printf("\nНедопустимая операция -- рабочий указатель в начале\n");
    else {
      printf("\nЭлемент до указателя: %c взят", list[res]);
      c = list[res];
      list[res] = ' ';
      delBeforePointer();
      return c;
    }
  }
  return EOF;
}

char takeAfterPointer(){
  int res;
  char c;
  if (pointer == 0)
    printf("\nНедопустимя операция, список пуст\n");
  else {
    res = next[pointer];
    if (res == 0)
      printf("\nНедопустимая операция -- рабочий указатель в конце\n");
    else {
      printf("\nЭлемент за указателем: %c взят", list[res]);
      c = list[res];
      list[res] = ' ';
      delAfterPointer();
      return c;
    }
  }
  return EOF;
}

char checkInput(){
  char c, cx;
  int mark = 0;
  c = getchar();
  if (c < 97 || c > 122)
    mark = -1;
  if ((cx = getchar()) != '\n'){
    while ((cx = getchar()) != '\n');
    printf("\n\nВводить можно только латинские строчные буквы!\n");
    return EOF;
  }
  if (mark == -1){
    printf("\n\nВводить можно только латинские строчные буквы!\n");
    return EOF;
  }
  return c;
}

void changeBeforePointer(){
  int res;
  char c;
  if (pointer == 0)
    printf("\nНедопустимая операция, список пуст\n");
  else {
    res = previous[pointer];
    if (res == 0)
      printf("\nНедопустимая операция -- рабочий указатель в начале\n");
    else {
      printf("\nЭлемент до указателя: %c\n\nПоменять на: ", list[res]);
      c = checkInput();
      if (c != EOF){
        list[res] = c;
        printf("\nЗначение элемента изменено\n");
      }
    }
  }
}

void changeAfterPointer(){
  int res;
  char c;
  if (pointer == 0)
    printf("\nНедопустимая операция, список пуст\n");
  else {
    res = next[pointer];
    if (res == 0)
      printf("\nНедопустимая операция -- рабочий указатель в конце\n");
    else {
      printf("\nЭлемент за указателем: %c\n\nПоменять на: ", list[res]);
      c = checkInput();
      if (c != EOF){
        list[res] = c;
        printf("\nЗначение элемента изменено\n");
      }
    }
  }
}

void addBeforePointer(){
  int res, i = 0;
  char c;
  if (pointer == 0){
    res = previous[1];
    printf("\n\nСписок пуст, поэтому добавляемы элемент будет первым: \n");
    c = checkInput();
    if (c != EOF){
      list[res] = c;
      previous[1] = previous[res];
      previous[res] = 0;
      previous[0] = res;
      next[1] = next[res];
      next[res] = 0;
      next[0] = res;
      printf("\n\nЭлемент добавлен\n");
      pointer = res;
    }
  } else {
    if (next[1] == 1){
      printf("\nПереполнение!!!!!\n");
    } else {
      res = previous[1];
      printf("\n\nВведите элемент: ");
      c = checkInput();
      if (c != EOF){
        list[res] = c;
        previous[1] = previous[res];
        previous[res] = previous[pointer];
        previous[pointer] = res;

        next[1] = next[res];
        for (i = 0; i < 15; i++)
          if (next[i] == pointer){
            next[i] = res;
            break;
          }
        next[res] = pointer;
        printf("\nЭлемент добавлен\n");
      }
    }
  }
}

void addAfterPointer(){
  int res;
  int i = 0;
  char c;
  if (pointer == 0){
    res = previous[1];
    printf("\n\nСписок пуст, поэтому добавляемый элемент будет первым: ");
    c = checkInput();
    if (c != EOF){
      list[res] = c;
      previous[1] = previous[res];
      previous[res] = 0;
      previous[0] = res;
      next[1] = next[res];
      next[res] = 0;
      next[0] = res;
      printf("\n\nЭлемент добавлен\n");
      pointer = res;
    }
  } else {
    if (next[1] == 1){
      printf("\nПереполнение!!!!!\n");
    } else {
      res = next[1];
      printf("\n\nВведите элемент: ");
      c = checkInput();
      if (c != EOF){
        list[res] = c;
        next[1] = next[res];
        next[res] = next[pointer];
        next[pointer] = res;

        previous[1] = previous[res];
        for (i = 0; i < 15; i++)
          if (previous[i] == pointer){
            previous[i] = res;
            break;
          }
        previous[res] = pointer;
        printf("\nЭлемент добавлен\n");
      }
    }
  }
}

int isInputCorrect(){
  char string[100], c;
  int i = 0, length, num, mark;
  c = getchar();
  if (c < 49 || c > 57)
    mark = -1; * (string + i) = c;
  i++;
  while ((c = getchar()) != '\n'){
    if (c < 48 || c > 57)
      mark = -1; * (string + i) = c;
    i++;
  } * (string + i) = '\0';
  if (mark == -1)
    return -1;
  length = strlen(string);
  if (length > 2)
    return -1;
  num = atoi(string);
  if (num > 20)
    return -1;

  return num;
}
