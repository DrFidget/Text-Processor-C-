#pragma once
#include<iostream>
#include<fstream>
#include"word.h"
using namespace std;

class line {
	char* arr;
	word* words;
	int count_of_words;
public:
	line(); 
	int GetWordsInSentence();
	void GetFrequency(ofstream& fout); 
	line& operator=(const char* array);
	friend ostream& operator<<(ostream& out, line& obj);
	friend ofstream& operator<<(ofstream& out, line& obj); 
	bool operator ==(line& obj); 
	bool operator !=(line& obj);
	void reset(char* temp);
	line& operator++(int); 
	line& operator--(int);
	void Encrypt(int key);
	void Decrypt(int key);
	~line();
};

