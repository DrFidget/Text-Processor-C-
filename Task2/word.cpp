#include"word.h"
#include<iostream>
#include<fstream>
using namespace std;


word::word()
{
	arr = nullptr;
	int siz = 0;

}

int word::GetCharactersInWord()
{
	return siz;
}

word& word::operator=(const char* array)
{
	if (array != nullptr) {
		if (arr)
			delete[]arr;
		arr = new char[strlen(array) + 1];
		siz = strlen(array);
		for (int i = 0; i < strlen(array); i++) {
			arr[i] = array[i];
			arr[i + 1] = '\0';
		}
	}
	return *this;
}

bool word::operator==(word& obj)
{
	if (siz == obj.siz) {
		for (int i = 0; i < siz; i++) {
			if (arr[i] != obj.arr[i]) {
				return false;
			}
		}
		return true;
	}
	else
		return false;
}

bool word::operator!=(word& obj)
{
	int count = 0;
	if (siz == obj.siz) {
		for (int i = 0; i < siz; i++) {
			if (arr[i] == obj.arr[i]) {
				count++;
			}
		}
		if (count != siz) return true;
		else return false;
	}
	else
		return true;
}
word& word::operator++(int)
{
	for (int i = 0; i < siz; i++) {
		if (arr[i] >= 'a' && arr[i] <= 'z') {
			arr[i] -= 32;
		}
	}
	return *this;
}
word& word::operator--(int)
{
	for (int i = 0; i < siz; i++) {
		if (arr[i] >= 'A' && arr[i] <= 'Z') {
			arr[i] += 32;
		}
	}
	return *this;
}
void word::Encrypt(int key)
{
	for (int i = 0; i < siz; i++)
	{
		arr[i] += key;
	}
}
void word::Decrypt(int key)
{
	for (int i = 0; i < siz; i++)
	{
		arr[i] -= key;
	}
}
word::~word()
{
	if (arr) {
		delete[]arr;
	}
}
ostream& operator<<(ostream& out, word& obj)
{
	if (obj.siz > 0)
		out << obj.arr ;
	return out;
}

ofstream& operator<<(ofstream& out, word& obj)
{
	if (obj.siz > 0)
		out << obj.arr;
	return out;
}