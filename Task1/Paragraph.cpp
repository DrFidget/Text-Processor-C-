#include"Paragraph.h"
#include<iostream>
#include<fstream>
using namespace std;

char* regrow1d(char* arr, int size)
{
	if (size == 0)
	{
		arr = new char[size + 1];
	}
	else
	{
		char* temp = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		delete[]arr;
		arr = temp;
		temp = nullptr;
	}
	return arr;
}

Paragraph::Paragraph(int p, int s[], int w[], char**** arr, int*** siz) 
{
	if (arr != nullptr)
	{
		array4d = arr;
	}
	if (siz != nullptr)
	{
		size = siz;
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			wordcount[i][j] = 0;
		}
	}
	for (int j = 0; j < 20; j++)
	{
		sentencecount[j] = 0;
	}
	number_of_paragraphs = 0;
}


Paragraph::Paragraph(const Paragraph& para)
{
	number_of_paragraphs = para.number_of_paragraphs;

	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		sentencecount[i] = para.sentencecount[i];
	}

	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		for (int j = 0; j < para.sentencecount[i]; j++)
		{
			wordcount[i][j] = para.wordcount[i][j];
		}
	}

	array4d = new char***[para.number_of_paragraphs];
	size = new int**[para.number_of_paragraphs];

	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		array4d[i] = new char**[para.sentencecount[i]];
		size[i] = new int*[para.sentencecount[i]];
	}

	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		for (int j = 0; j < para.sentencecount[i]; j++)
		{
			array4d[i][j] = new char*[para.wordcount[i][j]];
			size[i][j] = new int[para.wordcount[i][j]];
		}
	}

	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			for (int k = 0; k < wordcount[i][j]; k++)
			{
				size[i][j][k] = para.size[i][j][k];
			}
		}
	}

	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		for (int j = 0; j < para.sentencecount[i]; j++)
		{
			for (int k = 0; k < para.wordcount[i][j]; k++)
			{
				
				array4d[i][j][k] = new char[size[i][j][k]];
			}
		}
	}

	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		for (int j = 0; j < para.sentencecount[i]; j++)
		{
			for (int k = 0; k < para.wordcount[i][j]; k++)
			{
				for (int l = 0; l < para.size[i][j][k]; l++)
				{
					array4d[i][j][k][l] = para.array4d[i][j][k][l];
				}
			}
		}
	}
}


char*** Paragraph::getarray(int pnum)const
{
	return array4d[pnum];
}

int Paragraph::getpara()const
{
	return number_of_paragraphs;
}

void Paragraph::showcharacters()
{
	int* english = new int[number_of_paragraphs];
	int* punctuation = new int[number_of_paragraphs];
	for (int i = 0; i < number_of_paragraphs; i++)
	{
		english[i] = 0;
		punctuation[i] = 0;
	}

	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			for (int k = 0; k < wordcount[i][j]; k++)
			{
				for (int l = 0; l < size[i][j][k]; l++)
				{
					if ((array4d[i][j][k][l] >= 65 && array4d[i][j][k][l] <= 90) || (array4d[i][j][k][l] >= 97 && array4d[i][j][k][l] <= 122))
					{
						english[i]++;
					}
					else if (array4d[i][j][k][l] != ' '&&array4d[i][j][k][l]!=10)
					{
						punctuation[i]++;
					}
				}
			}
		}
	}

	for (int i = 0; i < number_of_paragraphs; i++)
	{
		cout << "Number of English Characters in Paragraph " << i + 1 << " : " << english[i] << endl;
	}

	for (int i = 0; i < number_of_paragraphs; i++)
	{
		cout << "Number of Punctuation Characters in Paragraph " << i + 1 << " : " << punctuation[i] << endl;
	}

}

void Paragraph::showwords()
{
	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			for (int k = 0; k < wordcount[i][j]; k++)
			{
				cout << "Number of Characters in word " << k + 1 << " of Sentence " << j + 1 << " of Paragraph " << i + 1 << " : " << size[i][j][k] - 1 << endl;
			}
		}
	}
}

void Paragraph::showsentence()
{
	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			cout << "Number of Words in Sentence " << j + 1 << " of Paragraph " << i + 1 << " : " << wordcount[i][j] << endl;
		}
	}
}

void Paragraph::showpargraph()
{
	for (int i = 0; i < number_of_paragraphs; i++)
	{
		cout << "Number of Sentences in Paragraph " << i + 1 << " : " << sentencecount[i] << endl;
	}
}

Paragraph& Paragraph::operator = (const Paragraph& para)
{
	number_of_paragraphs = para.number_of_paragraphs;

	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		sentencecount[i] = para.sentencecount[i];
	}

	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		for (int j = 0; j < para.sentencecount[i]; j++)
		{
			wordcount[i][j] = para.wordcount[i][j];
		}
	}

	array4d = new char***[para.number_of_paragraphs];
	size = new int**[para.number_of_paragraphs];

	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		array4d[i] = new char**[para.sentencecount[i]];
		size[i] = new int*[para.sentencecount[i]];
	}

	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		for (int j = 0; j < para.sentencecount[i]; j++)
		{
			array4d[i][j] = new char*[para.wordcount[i][j]];
			size[i][j] = new int[para.wordcount[i][j]];
		}
	}

	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			for (int k = 0; k < wordcount[i][j]; k++)
			{
				size[i][j][k] = para.size[i][j][k];
			}
		}
	}

	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		for (int j = 0; j < para.sentencecount[i]; j++)
		{
			for (int k = 0; k < para.wordcount[i][j]; k++)
			{

				array4d[i][j][k] = new char[size[i][j][k]];
			}
		}
	}

	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		for (int j = 0; j < para.sentencecount[i]; j++)
		{
			for (int k = 0; k < para.wordcount[i][j]; k++)
			{
				for (int l = 0; l < para.size[i][j][k]; l++)
				{
					array4d[i][j][k][l] = para.array4d[i][j][k][l];
				}
			}
		}
	}
	
	return *this;
}
ostream& operator <<(ostream& out,const Paragraph& para)
{
	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		for (int j = 0; j < para.sentencecount[i]; j++)
		{
			for (int k = 0; k < para.wordcount[i][j]; k++)
			{
				for (int l = 0; l < para.size[i][j][k]; l++)
				{
					out << para.array4d[i][j][k][l];
				}
			}
		}
		out << endl;
	}
	out << endl;

	return out;
}

ifstream& operator >>(ifstream& in, Paragraph& para)
{
	in.open("data.txt");

	char ch = '\0';
	int i = 0;

	while (!in.eof())
	{
		for (int j = 0; ch != 10; j++)
		{
			for (int k = 0; ch != '.' || ch == '?'; k++)
			{
				in.get(ch);
				for (int l = 0; ch != ' '; l++)
				{
					in.get(ch);
					if (ch == '.' || ch == '?')
						break;
					if (in.eof())
					{
						break;
					}
				}
				para.wordcount[i][j]=k;
				para.wordcount[i][j]++;
				if (in.eof())
				{
					break;
				}
			}
			para.sentencecount[i] = j;
			para.sentencecount[i]++;
			in.get(ch);

			if (in.eof())
			{
				break;
			}
		}
		i++;
		para.number_of_paragraphs = i;
		in.get(ch);
		
	}


	para.array4d = new char***[para.number_of_paragraphs];
	para.size = new int**[para.number_of_paragraphs];

	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		para.array4d[i] = new char**[para.sentencecount[i]];
		para.size[i] = new int*[para.sentencecount[i]];
	}

	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		for (int j = 0; j < para.sentencecount[i]; j++)
		{
			para.array4d[i][j] = new char*[para.wordcount[i][j]];
			para.size[i][j] = new int[para.wordcount[i][j]];
		}

	}
	for (int i = 0; i < para.number_of_paragraphs; i++)
	{
		for (int j = 0; j < para.sentencecount[i]; j++)
		{
			for (int k = 0; k < para.wordcount[i][j]; k++)
			{
				para.array4d[i][j][k] = new char[1];
			}
		}
	}


	int j = 0, k = 0, l = 0;
	i = 0;
	in.close();
	in.open("data.txt");
	while (!in.eof())
	{

		for (j = 0; j< para.sentencecount[i]; j++)
		{
			for (k = 0; k<para.wordcount[i][j]; k++)
			{
				for (l = 0; para.array4d[i][j][k][l - 1] != ' '; l++)
				{
					para.array4d[i][j][k] = regrow1d(para.array4d[i][j][k], l);
					in.get(para.array4d[i][j][k][l]);
					para.size[i][j][k] = l + 1;
					if (in.eof() || para.array4d[i][j][k][l - 1] == '.')
					{
						break;
					}

				}
				if (in.eof())
				{
					break;
				}
			}
			if (in.eof())
			{
				break;
			}
		}
		i++;
	}
	para.size[para.number_of_paragraphs - 1][para.sentencecount[para.number_of_paragraphs - 1] - 1][para.wordcount[para.number_of_paragraphs - 1][para.sentencecount[para.number_of_paragraphs - 1] - 1] - 1] --;
	
	return in;
}

char***& Paragraph::operator[](int index)
{
	return array4d[index];
}

bool Paragraph::operator == (const Paragraph& para)
{
	int para1 = 0, para2 = 0;
	cout << "Enter the Paragraph number to check: ";
	cin >> para1;

	while (para1 > para.getpara() || para1 < 0)
	{
		cout << "Does not exist!\nEnter again: ";
		cin >> para1;
	}
	cout << "Enter the Paragraph number to check with: ";
	cin >> para2;
	while (para2 > para.getpara() || para2 < 0)
	{
		cout << "Does not exist!\nEnter again: ";
		cin >> para2;
	}

	for (int j = 0; j < para.sentencecount[para1-1]; j++)
	{
		for (int k = 0; k < para.wordcount[para1 - 1][j]; k++)
		{
			for (int l = 0; l < para.size[para1 - 1][j][k]; l++)
			{
				if (para.array4d[para1 - 1][j][k][l] != array4d[para2 - 1][j][k][l])
					return false;
			}
		}
	}
	return true;
}
bool Paragraph::operator !=(const Paragraph& para)
{
	int para1 = 0, para2 = 0;
	cout << "Enter the Paragraph number to check: ";
	cin >> para1;

	while (para1 > para.getpara() || para1 < 0)
	{
		cout << "Does not exist!\nEnter again: ";
		cin >> para1;
	}
	cout << "Enter the Paragraph number to check with: ";
	cin >> para2;
	while (para2 > para.getpara() || para2 < 0)
	{
		cout << "Does not exist!\nEnter again: ";
		cin >> para2;
	}

	for (int j = 0; j < para.sentencecount[para1 - 1]; j++)
	{
		for (int k = 0; k < para.wordcount[para1 - 1][j]; k++)
		{
			for (int l = 0; l < para.size[para1 - 1][j][k]; l++)
			{
				if (para.array4d[para1 - 1][j][k][l] != array4d[para2 - 1][j][k][l])
					return true;
			}
		}
	}
	return false;
}


Paragraph& Paragraph::operator +()
{
	bool flag = false;
	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			for (int k = 0; k < wordcount[i][j]; k++)
			{
				for (int l = 0; l < size[i][j][k]; l++)
				{
					flag = false;
					if (array4d[i][j][k][l] >= 97 && array4d[i][j][k][l] <= 122)
					{
						flag = true;
					}
					if (flag)
					{
						array4d[i][j][k][l] = array4d[i][j][k][l] - 32;
					}
				}
			}
		}
	}
	return *this;
}

Paragraph& Paragraph::operator -()
{
	bool flag = false;
	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			for (int k = 0; k < wordcount[i][j]; k++)
			{
				for (int l = 0; l < size[i][j][k]; l++)
				{
					flag = false;
					if (array4d[i][j][k][l] >= 65 && array4d[i][j][k][l] <= 90)
					{
						flag = true;
					}
					if (flag)
					{
						array4d[i][j][k][l] = array4d[i][j][k][l] + 32;
					}
				}
			}
		}
	}
	return *this;
}

Paragraph& Paragraph::operator % (int num)
{
	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			for (int k = 0; k < wordcount[i][j]; k++)
			{
				for (int l = 0; l < size[i][j][k]; l++)
				{
					if ((array4d[i][j][k][l] >= 65 && array4d[i][j][k][l] <= 90) || (array4d[i][j][k][l] >= 97 && array4d[i][j][k][l] <= 122))
					{
						array4d[i][j][k][l] = array4d[i][j][k][l] + num;
						if (array4d[i][j][k][l] > 122 || (array4d[i][j][k][l] > 90 && array4d[i][j][k][l] < 97) || array4d[i][j][k][l] < 65)
						{
							array4d[i][j][k][l] = array4d[i][j][k][l] - 26;
						}
					}
				}
			}
		}
	}
	return *this;
}

Paragraph& Paragraph::operator * (int num)
{
	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			for (int k = 0; k < wordcount[i][j]; k++)
			{
				for (int l = 0; l < size[i][j][k]; l++)
				{
					if ((array4d[i][j][k][l] >= 65 && array4d[i][j][k][l] <= 90) || (array4d[i][j][k][l] >= 97 && array4d[i][j][k][l] <= 122))
					{
						array4d[i][j][k][l] = array4d[i][j][k][l] - num;
						if (array4d[i][j][k][l] > 122 || (array4d[i][j][k][l] > 90 && array4d[i][j][k][l] < 97) || array4d[i][j][k][l] < 65)
						{
							array4d[i][j][k][l] = array4d[i][j][k][l] + 26;
						}
					}
				}
			}
		}
	}
	return *this;
}

Paragraph Paragraph::concatinate(int c1, int c2)
{
	Paragraph temp;

	temp.number_of_paragraphs = number_of_paragraphs - 1;
	

	for (int i = 0; i < number_of_paragraphs; i++)
	{
		if (i == c1 - 1)
		{
			temp.sentencecount[i] = sentencecount[i] + sentencecount[c2 - 1];
		}
		else if (i == c2 - 1)
		{
			continue;
		}
		else if (i >= c2)
		{
			temp.sentencecount[i - 1] = sentencecount[i];
		}
		else
		{
			temp.sentencecount[i] = sentencecount[i];
		}
	}

	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			if (i == c1 - 1)
			{
				temp.wordcount[i][j] = wordcount[i][j];
			}
			else if (i == c2 - 1)
			{
				temp.wordcount[c1 - 1][j + sentencecount[c1 - 1]] = wordcount[c2 - 1][j];
				continue;
			}
			else if (i >= c2)
			{
				temp.wordcount[i - 1][j] = wordcount[i][j];
			}
			else
			{
				temp.wordcount[i][j] = wordcount[i][j];
			}
		}
	}


	temp.array4d = new char***[number_of_paragraphs-1];
	temp.size = new int**[number_of_paragraphs-1];
	for (int i = 0; i < number_of_paragraphs; i++)
	{
		if (i == c1 - 1)
		{
			temp.array4d[i] = new char**[sentencecount[i] + sentencecount[c2 - 1]];
			temp.size[i] = new int*[sentencecount[i] + sentencecount[c2 - 1]];
		}
		else if (i == c2 - 1)
		{
			continue;
		}
		else if (i >= c2)
		{
			temp.array4d[i-1] = new char**[sentencecount[i]];
			temp.size[i-1] = new int*[sentencecount[i]];
		}
		else
		{
			temp.array4d[i] = new char**[sentencecount[i]];
			temp.size[i] = new int*[sentencecount[i]];
		}
	}

	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			if (i == c1 - 1)
			{
				temp.array4d[i][j] = new char*[wordcount[i][j]];
				temp.size[i][j] = new int[wordcount[i][j]];
		
			}
			else if (i == c2 - 1)
			{
				temp.array4d[c1 - 1][j + sentencecount[c1-1]] = new char*[wordcount[c2 - 1][j]];
				temp.size[c1 - 1][j + sentencecount[c1 - 1]] = new int[wordcount[c2 - 1][j]];
				continue;
			}
			else if (i >= c2)
			{
				temp.array4d[i - 1][j] = new char*[wordcount[i][j]];
				temp.size[i - 1][j] = new int[wordcount[i][j]];
			}
			else
			{
				temp.array4d[i][j] = new char*[wordcount[i][j]];
				temp.size[i][j] = new int[wordcount[i][j]];
			}
		}

	}


	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			for (int k = 0; k < wordcount[i][j]; k++)
			{
				if (i == c1 - 1)
				{
					temp.size[i][j][k] = size[i][j][k];
				}
				else if (i == c2 - 1)
				{
					temp.size[c1 - 1][j + sentencecount[c1 - 1]][k] = size[i][j][k];
					continue;
				}
				else if (i >= c2)
				{
					temp.size[i - 1][j][k] = size[i][j][k];
				}
				else
				{
					temp.size[i][j][k] = size[i][j][k];
				}
				
			}
		}
	}


	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			for (int k = 0; k < wordcount[i][j]; k++)
			{
				if (i == c1 - 1)
				{
					temp.array4d[i][j][k] = new char[size[i][j][k]];
					temp.size[i][j][k] = size[i][j][k];
				}
				else if (i == c2 - 1)
				{
					temp.array4d[c1 - 1][j + sentencecount[c1 - 1]][k] = new char[size[i][j][k]];
					temp.size[c1 - 1][j + sentencecount[c1 - 1]][k] = size[i][j][k];
					continue;
				}
				else if (i >= c2)
				{
					temp.array4d[i - 1][j][k] = new char[size[i][j][k]];
					temp.size[i - 1][j][k] = size[i][j][k];
				}
				else
				{
					temp.array4d[i][j][k] = new char[size[i][j][k]];
					temp.size[i][j][k] = size[i][j][k];
				}
			}
		}
	}

	
	
	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			for (int k = 0; k < wordcount[i][j]; k++)
			{
				for (int l = 0; l < size[i][j][k]; l++)
				{
					if (i == c1 - 1)
					{
						temp.array4d[i][j][k][l] = array4d[i][j][k][l];
					}
					else if (i == c2 - 1)
					{
						temp.array4d[c1 - 1][j + sentencecount[c1 - 1]][k][l] = array4d[i][j][k][l];
						continue;
					}
					else if (i >= c2)
					{
						temp.array4d[i - 1][j][k][l] = array4d[i][j][k][l];
					}
					else
					{
						temp.array4d[i][j][k][l] = array4d[i][j][k][l];
					}

				}
			}
		}
	}

	temp.array4d[c1 - 1][sentencecount[c1 - 1] - 1][wordcount[c1 - 1][sentencecount[c1 - 1] - 1] - 1][size[c1 - 1][sentencecount[c1 - 1] - 1][wordcount[c1 - 1][sentencecount[c1 - 1] - 1] - 1]-1] = '\0';

	
	return temp;
}

void Paragraph::check()
{
	ifstream fin;
	char ch[25] = { '\0' };
	char chek[25] = { '\0' };
	int cheksize = 0;
	int chsize = 0;
	bool flag;

	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			for (int k = 0; k < wordcount[i][j]; k++)
			{
				cheksize = 0;
				if ((array4d[i][j][k][0] > 122 || (array4d[i][j][k][0] > 90 && array4d[i][j][k][0] < 97) || array4d[i][j][k][0] < 65) && (array4d[i][j][k][size[i][j][k] - 2] > 122 || (array4d[i][j][k][size[i][j][k] - 2] > 90 && array4d[i][j][k][size[i][j][k] - 2] < 97) || array4d[i][j][k][size[i][j][k] - 2] < 65))
				{
					for (int l = 0; l < size[i][j][k] - 3; l++)
					{
						chek[l] = array4d[i][j][k][l + 1];
					}
					while (chek[cheksize] != '\0')
					{
						cheksize++;
					}
				}

				else if ((array4d[i][j][k][size[i][j][k] - 3] > 122 || (array4d[i][j][k][size[i][j][k] - 3] > 90 && array4d[i][j][k][size[i][j][k] - 3] < 97) || array4d[i][j][k][size[i][j][k] - 3] < 65) && (array4d[i][j][k][size[i][j][k] - 2] > 122 || (array4d[i][j][k][size[i][j][k] - 2] > 90 && array4d[i][j][k][size[i][j][k] - 2] < 97) || array4d[i][j][k][size[i][j][k] - 2] < 65))
				{
					for (int l = 0; l < size[i][j][k] - 3; l++)
					{
						chek[l] = array4d[i][j][k][l];
					}
					while (chek[cheksize] != '\0')
					{
						cheksize++;
					}
				}

				else if (array4d[i][j][k][size[i][j][k] - 2] > 122 || (array4d[i][j][k][size[i][j][k] - 2] > 90 && array4d[i][j][k][size[i][j][k] - 2] < 97) || array4d[i][j][k][size[i][j][k] - 2] < 65)
				{
					for (int l = 0; l < size[i][j][k] - 2; l++)
					{
						chek[l] = array4d[i][j][k][l];
					}
					while (chek[cheksize] != '\0')
					{
						cheksize++;
					}
				}
				else if (array4d[i][j][k][0] > 122 || (array4d[i][j][k][0] > 90 && array4d[i][j][k][0] < 97) || array4d[i][j][k][0] < 65)
				{
					for (int l = 0; l < size[i][j][k] - 2; l++)
					{
						chek[l] = array4d[i][j][k][l + 1];
					}
					while (chek[cheksize] != '\0')
					{
						cheksize++;
					}
				}
				
				else
				{
					for (int l = 0; l < size[i][j][k] - 1; l++)
					{
						chek[l] = array4d[i][j][k][l];
					}
					while (chek[cheksize] != '\0')
					{
						cheksize++;
					}
				}
		
				fin.open("dictionary.txt");
				flag = false;
				while (!fin.eof())
				{
					chsize = 0;
					fin >> ch;
					while (ch[chsize] != '\0')
					{
						chsize++;
					}
					if (chsize == cheksize)
					{
						for (int l = 0; l < cheksize; l++)
						{
							if (ch[l] != chek[l])
							{
								flag = false;
								break;
							}
							flag = true;
						}

					}
					if (flag)
					{
						break;
					}
				}
				fin.close();
				if (!flag)
				{
					cout << "The Word " << k + 1 << " of Sentence " << j + 1 << " of Paragraph " << i + 1 << " is not present in dictionary.txt : ";
					cout << chek;
					cout << endl;
				}
				for (int l = 0; l < cheksize; l++)
				{
					chek[l] = '\0';
				}
			}
		}
	}
}

void Paragraph::frequency()
{
	ofstream fout;
	fout.open("frequency.txt");

	fout << "Number of Paragraphs : " << number_of_paragraphs << endl;
	fout << endl;
	for (int i = 0; i < number_of_paragraphs; i++)
	{
		fout << "Number of Sentences in Paragraph " << i + 1 << " : " << sentencecount[i] << endl;
	}
	fout << endl;
	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			fout << "Number of Words in Sentence " << j + 1 << " of Paragraph " << i + 1 << " : " << wordcount[i][j] << endl;
		}
	}
	fout << endl;
	for (int i = 0; i < number_of_paragraphs; i++)
	{
		for (int j = 0; j < sentencecount[i]; j++)
		{
			for (int k = 0; k < wordcount[i][j]; k++)
			{
				fout << "Number of Characters in word " << k + 1 << " of Sentence " << j + 1 << " of Paragraph " << i + 1 << " : " << size[i][j][k] - 1 << endl;
			}
		}
	}

	fout << endl;
}