#pragma once

struct Date;

// Ищет максимальную дату в файле, владение возвращаемым указателем передаётся пользователю
struct Date* searchMaximumDate(const char* fileName);

// Распечатывает дату
void printDate(struct Date* date);

// Возвращает часть даты (день, месяц или год)
int getDate(struct Date* date, int partNumber);