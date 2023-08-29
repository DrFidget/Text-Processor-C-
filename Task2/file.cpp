#include<iostream>
#include<fstream>
#include"file.h"
using namespace std;

file::file()
{
	arr = nullptr;
	paragraphs = nullptr;
	no_of_para = 0;
	no_of_char = 0;
}

int file::GetParasInFile()
{
	return no_of_para;
}

char* file::regrow(char* arr)
{
	if (arr == nullptr) {
		arr = new char[2];
	}
	else {
		char* temp = new char[strlen(arr) + 2];
		for (int i = 0; i < strlen(arr); i++)
		{
			temp[i] = arr[i];
		}
		delete[]arr;
		arr = temp;
		temp = nullptr;
	}
	return arr;
}

void file::reset(char* temp)
{
	for (int i = 0; i < 500; i++)
	{
		temp[i] = '\0';
	}
}
file& file::operator++(int a)
{
	for (int i = 0; i < no_of_para; i++)
	{
		paragraphs[i]++;
	}
	return *this;
}
file& file::operator--(int a)
{
	for (int i = 0; i < no_of_para; i++)
	{
		paragraphs[i]--;
	}
	return *this;
}
void file::operationSix()
{
	for (int i = 0; i < no_of_para; i++) {
		cout << "paragraph no :" << i + 1 << endl;
		cout << "characters :" << paragraphs[i].GetNoOfChar() << "\t" << "Alphabets :" << paragraphs[i].GetNoOfAlpha() << endl << endl;
	}
}
void file::GetFrequency()
{
	ofstream fout("frequency.txt");
	for (int i = 0; i < no_of_para; i++) {
		fout << "Paragraph no :" << i + 1 << endl;
		paragraphs[i].GetFrequency(fout);
	}
	fout.close();
}
void file::operator*(int key)
{
	for (int i = 0; i < no_of_para; i++)
	{
		paragraphs[i].Encrypt(key);
	}
}

void file::operator%(int key)
{
	for (int i = 0; i < no_of_para; i++)
	{
		paragraphs[i].Decrypt(key);
	}
}

bool file::cmpstring(char* arr1, char* arr2)
{
	if (strlen(arr1) == strlen(arr2)) {
		for (int i = 0; i < strlen(arr1); i++) {
			if (arr1[i] != arr2[i]&& arr1[i] != arr2[i]+32&& arr1[i] != arr2[i] - 32) {
				return false;
			}
		}
		return true;
	}
	else
		return false;
}
void file::spell_check()
{
	char *disposible = new char[50]{ '\0' };
	char *temp = new char[50]{ '\0' };
	bool flag = false;
	ifstream fin;
	ofstream fout("NotInDictionary.txt");
	for (int  i = 0,j=0; i < no_of_char; i++)
	{
		if (arr[i]==' '||arr[i]=='.'||arr[i]==',' || arr[i] == '\n' || arr[i] == '\0') {
			
			fin.open("dictionary.txt");

			while (fin.getline(temp, 50, '\n')) {

				if (cmpstring(disposible, temp)) {
					flag = true;
					break;
				}
				else {
					flag = false;
				}

			}
			if (!flag) {
				cout << disposible << endl;
				fout << disposible << endl;
				flag = true;
			}
			
			fin.close();
			delete[]disposible;
			disposible = new char[50]{ '\0' };
			j = 0;
		}
		else
		disposible[j++] = arr[i];
	}
}
void file::operator=(file& obj)
{
	if (paragraphs) delete[]paragraphs;
	if (arr)delete[]arr;
	no_of_char = obj.no_of_char;
	no_of_para = obj.no_of_para;
	arr = new char[no_of_char + 1];
	for (int i = 0; i < no_of_char; i++)
	{
		arr[i] = obj.arr[i];
		arr[i + 1] = '\0';
	}
	paragraphs = new paragraph[no_of_para];
	char* tempp = new char[1500]{ '\0' };
	int k = 0, l = 0;
	for (int i = 0; i < no_of_char; i++)
	{
		tempp[k++] = arr[i];
		if (arr[i] == '\n' || i == no_of_char - 1) {
			paragraphs[l++] = tempp;
			delete[]tempp;
			tempp = new char[1500]{ '\0' };
			k = 0;
		}
	}
	//return *this;
}
void file::operator+(file& obj)
{
	file F;
	F.no_of_para = 0;
	F.no_of_char = no_of_char + obj.no_of_char;
	F.arr = new char[F.no_of_char + 2];
	int j = 0;
	for (j = 0; j < no_of_char; j++) {
		F.arr[j] = arr[j];
	}
	F.arr[j++] = '\n';
	for (int i = 0; i < obj.no_of_char; i++) {
		F.arr[i + j] = obj.arr[i];
		F.arr[i + j + 1] = '\0';
	}
	for (int i = 0; i < F.no_of_char; i++) {
		if (F.arr[i] == '\n' || i == F.no_of_char - 1) {
			F.no_of_para++;
		}
	}
	F.paragraphs = new paragraph[F.no_of_para];
	char* tempp = new char[1500]{ '\0' };
	int k = 0, l = 0;
	for (int i = 0; i < F.no_of_char; i++)
	{
		tempp[k++] = F.arr[i];
		if (F.arr[i] == '\n' || i == F.no_of_char - 1) {
			F.paragraphs[l++] = tempp;
			delete[]tempp;
			tempp = new char[1500]{ '\0' };
			k = 0;
		}
	}
	if (paragraphs) delete[]paragraphs;
	if (arr)delete[]arr;
	no_of_char = F.no_of_char;
	no_of_para = F.no_of_para;
	arr = new char[no_of_char + 1];
	for (int i = 0; i < no_of_char; i++)
	{
		arr[i] = F.arr[i];
		arr[i + 1] = '\0';
	}
	paragraphs = new paragraph[no_of_para];
	char* tempPp = new char[1500]{ '\0' };
	int kK = 0, lL = 0;
	for (int i = 0; i < no_of_char; i++)
	{
		tempp[kK++] = arr[i];
		if (arr[i] == '\n' || i == no_of_char - 1) {
			paragraphs[lL++] = tempp;
			delete[]tempPp;
			tempPp = new char[1500]{ '\0' };
			kK = 0;
		}
	}
}



file::~file()
{
	if (paragraphs) delete[]paragraphs;
	if (arr) delete[]arr;
}
ifstream& operator>>(ifstream& fin, file& obj)
{
	if (obj.paragraphs == nullptr) {
		char ch;
		char temp[500] = { '\0' };
		if (obj.arr) delete[]obj.arr;
		if (obj.paragraphs)delete[]obj.paragraphs;
		fin.open("input.txt");
		while (fin.get(ch)) {
			obj.arr = obj.regrow(obj.arr);
			obj.arr[obj.no_of_char++] = ch;
			obj.arr[obj.no_of_char] = '\0';
		}
		for (int i = 0; i < obj.no_of_char; i++)
		{
			if (obj.arr[i] == '\n')
				obj.no_of_para++;
			if (obj.arr[i] == '.' && obj.arr[i + 1] == '\0')
				obj.no_of_para++;
		}
		obj.paragraphs = new paragraph[obj.no_of_para];

		for (int i = 0, j = 0, k = 0; i < strlen(obj.arr); i++) {
			temp[j++] = obj.arr[i];
			if (obj.arr[i] == '\n') {

				obj.paragraphs[k++] = temp;
				obj.reset(temp);
				j = 0;
			}
			if (obj.arr[i] == '.' && obj.arr[i + 1] == '\0') {
				obj.paragraphs[k++] = temp;
				obj.reset(temp);
				j = 0;
			}
		}
		fin.close();
		
	}
	else {
		cout << "\n\nDATA ALREADY STORED IN OBJECT\n\n";
	}
	return fin;
}

ostream& operator<<(ostream& out, file& obj)
{
	for (int i = 0; i < obj.no_of_para; i++) {
		out << obj.paragraphs[i]<<endl;
	}
	return out;
}

ofstream& operator<<(ofstream& out, file& obj)
{
	for (int i = 0; i < obj.no_of_para; i++) {
		out << obj.paragraphs[i] << endl;
	}
	out.close();
	return out;
}