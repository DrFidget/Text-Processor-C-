#pragma once
#include<iostream>
#include<fstream>
#include"paragraph.h"
using namespace std;

class file {
	int no_of_para;
	char* arr;
	int no_of_char;
	paragraph *paragraphs;
public:
	file(); 
	int GetParasInFile();
	friend ifstream& operator>>(ifstream& fin, file& obj); 
	char* regrow(char* arr); 
	void reset(char* temp); 
	friend ostream& operator<<(ostream& out, file& obj); 
	friend ofstream& operator<<(ofstream& out, file& obj);
	file& operator++(int a); 
	file& operator--(int a); 
	void operationSix();
	void GetFrequency(); 
	void operator*(int key);
	void operator%(int key);
	void spell_check();
	void operator=(file& obj); 
	void operator+(file& obj); 
	bool cmpstring(char* arr1, char* arr2);
	~file(); 
};
