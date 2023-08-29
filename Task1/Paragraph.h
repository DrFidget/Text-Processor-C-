#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class Paragraph
{
	int wordcount[20][100];
	int sentencecount[20];
	int number_of_paragraphs = 0; 
	char**** array4d;
	int*** size;
public:
	Paragraph(int = 0, int [] = 0, int [] = 0, char**** = nullptr, int*** = nullptr);
	Paragraph(const Paragraph& para);

	char*** getarray(int )const;
	int getpara()const;

	void showcharacters();
	void showwords();
	void showsentence();
	void showpargraph();

	void frequency();
	void check();
	Paragraph& operator =(const Paragraph& para);
	friend ostream& operator <<(ostream& out,const Paragraph& para);
	friend ofstream& operator <<(ofstream& fout, const Paragraph& para)
	{
		fout.open("file2.txt");
		for (int i = 0; i < para.number_of_paragraphs; i++)
		{
			for (int j = 0; j < para.sentencecount[i]; j++)
			{
				for (int k = 0; k < para.wordcount[i][j]; k++)
				{
					for (int l = 0; l < para.size[i][j][k]; l++)
					{
						fout << para.array4d[i][j][k][l];
					}
				}
			}
		}
		fout << endl;
		return fout;
	}
	friend ifstream& operator >>(ifstream& in, Paragraph& para);
	char***& operator[](int);
	bool operator ==(const Paragraph& para);
	bool operator !=(const Paragraph& para);

	Paragraph& operator +();
	Paragraph& operator -();

	Paragraph& operator %(int);
	Paragraph& operator *(int);

	Paragraph concatinate(int, int);
};
