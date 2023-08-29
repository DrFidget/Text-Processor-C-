#pragma once
#include<iostream>
#include<fstream>
#include"sentence.h"
using namespace std;
class paragraph {
	char* arr;
	int no_of_lines;
	line* lines;
	int no_of_alphas;
	int no_of_chars;
public:
	paragraph();
	int GetLinesInPara(); 
	int GetNoOfChar();
	int GetNoOfAlpha();
	void GetFrequency(ofstream& fout);
	paragraph& operator=(const char* array);
	void reset(char* temp); 
	paragraph& operator++(int);
	paragraph& operator--(int); 
	friend ostream& operator<<(ostream& out, paragraph& obj); 
	friend ofstream& operator<<(ofstream& out, paragraph& obj);
	~paragraph(); 
	bool operator==(paragraph& obj); 
	bool operator!=(paragraph& obj); 
	void Encrypt(int key);
	void Decrypt(int key);
};
