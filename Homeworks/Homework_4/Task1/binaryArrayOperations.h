#pragma once

#define ARRAY_SIZE 32

//����������� ������� ������
void binaryNumberInversion(int binaryArray[], const int size);

//������� ����� ���� ������� �������� � ������ ������� ������
void binarySum(int firstBinaryArray[], int secondBinaryArray[], int resultBinaryArray[], const int size);

//��������� ������� ������ � ���������� �����
int fromBinaryToDecimal(int binaryArray[], const int size);

//��������� ���������� ����� � ������� ������
void convertToBinary(int number, int binaryArray[], const int size);

//�������� ������� ������ � ������� � ���� ��������� �����
void printBinaryArray(int binaryArray[], const int size);