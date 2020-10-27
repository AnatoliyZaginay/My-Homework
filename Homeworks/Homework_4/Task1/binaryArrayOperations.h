#pragma once

#define ARRAY_SIZE 32

//Инвертирует булевый массив
void binaryNumberInversion(int binaryArray[], const int size);

//Считает сумму двух булевых массивов в третий булевый массив
void binarySum(int firstBinaryArray[], int secondBinaryArray[], int resultBinaryArray[], const int size);

//Переводит булевый массив в десятичное число
int fromBinaryToDecimal(int binaryArray[], const int size);

//Переводит десятичное число в булевый массив
void convertToBinary(int number, int binaryArray[], const int size);

//Печатает булевый массив в консоль в виде двоичного числа
void printBinaryArray(int binaryArray[], const int size);