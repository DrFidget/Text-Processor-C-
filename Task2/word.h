#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class word
{
	char* arr;
	int siz;
public:
	word();
	int GetCharactersInWord();
	word& operator=(const char* array);
	bool operator==(word& obj);
	bool operator!=(word& obj);
	friend ostream& operator<<(ostream& out, word& obj);
	friend ofstream& operator<<(ofstream& out, word& obj);
	word& operator++(int);
	word& operator--(int);
	void Encrypt(int key);
	void Decrypt(int key);
	~word(); 
};



