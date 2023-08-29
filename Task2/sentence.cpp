#include"sentence.h"
#include<iostream>
#include<fstream>
using namespace std;

line::line()
{
	arr = nullptr;
	words = nullptr;
	count_of_words = 0;
}

int line::GetWordsInSentence()
{
	return count_of_words;
}

void line::GetFrequency(ofstream& fout)
{
	for (int i = 0; i < count_of_words; i++) {
		fout << "word no :" << i + 1 << "   total characters :" << words[i].GetCharactersInWord() << endl;
	}
}

line& line::operator=(const char* array)
{
	if (arr)delete[]arr;
	if (words)delete[]words;
	char *temp = new char[100] {'\0'};

	if (array != nullptr) {
		arr = new char[strlen(array) + 1];
		for (int i = 0; i < strlen(array); i++) {
			arr[i] = array[i];
			arr[i + 1] = '\0';
		}
		for (int i = 0; i < strlen(arr); i++) {
			if (arr[i] == ' ' || arr[i] == '.' || arr[i] == ',') {
				count_of_words++;
			}

		}
		words = new word[count_of_words];
		int tempcount = 0;
		for (int i = 0, j = 0; i < strlen(arr); i++) {
			temp[j++] = arr[i];
			if (arr[i] == ' ' || arr[i] == '.' || arr[i] == ',') {
				words[tempcount++] = temp;
				delete[]temp;
				temp = new char[100]{ '\0' };
				j = 0;
			}
		}

	}
	return *this;
}

ostream& operator<<(ostream& out, line& obj)
{
	if (obj.count_of_words >= 1) {
		for (int i = 0; i < obj.count_of_words; i++) {
			out << obj.words[i];
		}
	}
	else {
		out << "no words\n";
	}
	return out;
}

ofstream& operator<<(ofstream& out, line& obj)
{
	if (obj.count_of_words >= 1) {
		for (int i = 0; i < obj.count_of_words; i++) {
			out << obj.words[i];
		}
	}
	else {
		out << "no words\n";
	}
	return out;
}
bool line::operator==(line& obj)
{
	if (count_of_words == obj.count_of_words) {
		for (int i = 0; i < count_of_words; i++) {
			if (words[i] != obj.words[i]) {
				return false;
			}
		}
		return true;
	}
	else return false;
}
bool line::operator!=(line& obj)
{
	int count = 0;
	if (count_of_words == obj.count_of_words) {
		for (int i = 0; i < count_of_words; i++) {
			if (words[i] == obj.words[i]) {
				count++;
			}
		}
		if (count != count_of_words)
			return true;
		else
			return false;
	}
	else return false;
}
void line::reset(char* temp)
{
	for (int i = 0; i < 50; i++)
	{
		temp[i] = '\0';
	}
}
line::~line()
{
	if (words) {
		delete[]words;
	}
	if (arr) {
		delete[]arr;
	}
}

line& line::operator++(int)
{
	for (int i = 0; i < count_of_words; i++) {
		words[i]++;
	}
	return *this;
}

line& line::operator--(int)
{
	for (int i = 0; i < count_of_words; i++) {
		words[i]--;
	}
	return *this;
}

void line::Encrypt(int key)
{
	for (int i = 0; i < count_of_words; i++)
	{
		words[i].Encrypt(key);
	}
}

void line::Decrypt(int key)
{
	for (int i = 0; i < count_of_words; i++)
	{
		words[i].Decrypt(key);
	}
}
