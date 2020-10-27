#pragma once

#define NAME_LENGTH 30
#define NUMBER_LENGTH 30
#define PHONEBOOK_LENGTH 100

//��������� �������� � ���������� �����������, ����� ��� ����: ��� � ����� ��������
struct Contact
{
	char name[NAME_LENGTH];
	char phoneNumber[NUMBER_LENGTH];
};

//������ ������ �� ����� � ������� �� � ���������� ����������
void readFile(struct Contact array[], const char fileName[], int* currentIndex);

//��������� ������ �� ����������� ����������� � ����
void saveFile(struct Contact array[], const char fileName[], const int lasIndex);

//��������� ������� � ���������� ����������
void addContact(struct Contact array[], int* currentIndex, const char name[], const char number[]);

//������� � ������� ��� �������� �� ����������� �����������
void writePhoneBook(struct Contact array[], const int lastIndex);

//���� ��� � ���������� ����������� �� ������ ��������, ���������� ������ �������� ������� � ��������� ������� ��������
int nameSearch(struct Contact array[], const int lastIndex, const char number[]);

//���� ����� �������� � ���������� ����������� �� �����, ���������� ������ �������� ������� � ��������� ������
int phoneNumberSearch(struct Contact array[], const int lastIndex, const char name[]);