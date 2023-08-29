#include<iostream>
#include<fstream>
#include"paragraph.h"
using namespace std;

paragraph::paragraph()
{
	arr = nullptr;
	lines = nullptr;
	no_of_lines = 0;
	no_of_chars = 0;
	no_of_alphas = 0;
}

int paragraph::GetLinesInPara()
{
	return no_of_lines;
}

int paragraph::GetNoOfChar()
{
	return no_of_chars;
}

int paragraph::GetNoOfAlpha()
{
	return no_of_alphas;
}

void paragraph::GetFrequency(ofstream& fout)
{
	for (int i = 0; i < no_of_lines; i++) {
		fout << "sentence no :" << i + 1 << endl;
		fout << "words in sentence :" << i + 1 << "   are :" << lines[i].GetWordsInSentence() << endl;
		lines[i].GetFrequency(fout);
	}
}

paragraph& paragraph::operator=(const char* array)
{
	char temp[500] = { '\0' };
	if (arr != nullptr) { delete[]arr; arr = nullptr; }
	if (lines != nullptr) { delete[]lines, lines = nullptr; };
	if (array != nullptr) {
		arr = new char[strlen(array) + 1];
		for (int i = 0; i < strlen(array); i++) {
			arr[i] = array[i];
			arr[i + 1] = '\0';
		}
		for (int i = 0; i < strlen(arr); i++) {
			if (arr[i] == '.') {
				no_of_lines++;
			}
		}
		lines = new line[no_of_lines];
		for (int i = 0, j = 0, k = 0; i < strlen(arr); i++) {
			temp[j++] = arr[i];
			if (arr[i] == '.') {
				lines[k++] = temp;
				reset(temp);
				j = 0;

			}
		}
	}
	no_of_chars = 0;
	no_of_alphas = 0;
	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == '.' || arr[i] == ',' || arr[i] == ';' || arr[i] == ':' || arr[i] == '\'' || arr[i] == '\"') no_of_chars++;
		if (arr[i] >= 'a' && arr[i] <= 'z' || arr[i] >= 'A' && arr[i] <= 'Z') no_of_alphas++;
	}

	return *this;
}

void paragraph::reset(char* temp)
{
	for (int i = 0; i < 500; i++)
	{
		temp[i] = '\0';
	}
}

paragraph& paragraph::operator++(int)
{
	for (int i = 0; i < no_of_lines; i++)
	{
		lines[i]++;
	}
	return *this;
}

paragraph& paragraph::operator--(int)
{
	for (int i = 0; i < no_of_lines; i++)
	{
		lines[i]--;
	}
	return *this;
}

paragraph::~paragraph()
{
	if (arr)delete[]arr;
	if (lines)delete[]lines;
}

bool paragraph::operator==(paragraph& obj)
{
	if (obj.no_of_lines == no_of_lines) {
		for (int i = 0; i < no_of_lines; i++) {
			if (lines[i] != obj.lines[i]) {
				return false;
			}
		}
		return true;
	}
	else return false;
}

bool paragraph::operator!=(paragraph& obj)
{
	int count = 0;
	if (obj.no_of_lines != no_of_lines) {
		for (int i = 0; i < no_of_lines; i++) {
			if (lines[i] == obj.lines[i]) {
				count++;
			}
		}
		if (count != no_of_lines)
			return true;
		else
			return false;
	}
	else return true;
}

void paragraph::Encrypt(int key)
{
	for (int i = 0; i < no_of_lines; i++)
	{
		lines[i].Encrypt(key);
	}
}

void paragraph::Decrypt(int key)
{
	for (int i = 0; i < no_of_lines; i++)
	{
		lines[i].Decrypt(key);
	}
}

ostream& operator<<(ostream& out, paragraph& obj)
{
	for (int i = 0; i < obj.no_of_lines; i++) {
		out << obj.lines[i];
	}
	return out;
}

ofstream& operator<<(ofstream& out, paragraph& obj)
{
	for (int i = 0; i < obj.no_of_lines; i++) {
		out << obj.lines[i];
	}
	return out;
}