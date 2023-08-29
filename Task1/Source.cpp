#include<iostream>
#include<fstream>
#include"Paragraph.h"
using namespace std;

//L1F20BSCS0372  Mohid Hameed  Section 'C7'
//L1F20BSCS0381  Ahmed Hassan  Section 'C7'

void menu(ifstream& fin, ofstream& fout, Paragraph& p1)
{
	int choice = 0;
	int choice2 = 0;
	int choice3 = 0;
	while (choice3 != 2)
	{
		cout << "1. Run code" << endl;
		cout << "2. Exit code" << endl;
		cin >> choice3;

		switch (choice3)
		{
		case 1:
			system("CLS");
			cout << "1. Read the file." << endl;
			cout << "2. Write the Paragraphs in the file." << endl;
			cout << "3. Display the paragraph on screen." << endl;
			cout << "4. Check if two paragraphs are equal" << endl;
			cout << "5. Convert all characters into UPPERCASE or lowercase." << endl;
			cout << "6. Count number of English and Punctuation charactors in each paragraph." << endl;
			cout << "7. Count number of characters in every word of every sentence." << endl;
			cout << "8. Count number of words in every paragraph, in every sentence." << endl;
			cout << "9. Count number of sentences in the whole text, in every paragraph as well." << endl;
			cout << "10. Encrypt and Decrypt the paragraph." << endl;
			cout << "11. Spellcheck words of the paragraph against a given dictionary." << endl;
			cout << "12. Add two Paragraphs in to a single Paragraph." << endl;
			cout << "14. Print Frequency of text." << endl;
			cout << "\nChoise :: ";
			cin >> choice;

			switch (choice)
			{
			case 1:
				fin >> p1;
				break;
			case 2:
				fout << p1;
				break;
			case 3:
				cout << p1;
				break;
			case 4:
				if (p1 == p1)
				{
					cout << "The Paragraphs are same.\n";
				}
				else
					cout << "Paragraphs are not same!\n";
				break;
			case 5:
				cout << "1. UPPERCASE" << endl;
				cout << "2. lowercase" << endl;
				cin >> choice2;
				if (choice2 == 1)
				{
					+p1;
				}
				else if (choice2 == 2)
				{
					-p1;
				}
				else
				{
					cout << "Invlied choice!" << endl;
				}
				break;
			case 6:
				p1.showcharacters();
				break;
			case 7:
				p1.showwords();
				break;
			case 8:
				p1.showsentence();
				break;
			case 9:
				p1.showpargraph();
				break;
			case 10:
				cout << "1. Encrypt" << endl;
				cout << "2. Decrypt" << endl;
				cin >> choice2;
				if (choice2 == 1)
				{
					cout << "Enter number: ";
					cin >> choice2;
					p1 % choice2;
				}
				else if (choice2 == 2)
				{
					cout << "Enter number: ";
					cin >> choice2;
					p1 * choice2;
				}
				else
				{
					cout << "Invlied choice!" << endl;
				}
				break;
			case 11:
				p1.check();
				break;
			case 12:
				cout << "First entered number should be smaller than second!\n";
				cout << "Enter number of Paragraph to add with: ";
				cin >> choice;
				while (choice > p1.getpara())
				{
					cout << "Invalied Number!\nEnter again: ";
					cin >> choice;
				}
				cout << "Enter number of Paragraph to add: ";
				cin >> choice2;
				while (choice2 > p1.getpara() || choice >= choice2)
				{
					cout << "Invalied Number!\nEnter again: ";
					cin >> choice2;
				}
				p1 = p1.concatinate(choice, choice2);
				break;
			case 13:

				break;
			case 14:
				cout << "The Frequency of text has been printed in the file Frequency.txt Successfully." << endl;
				p1.frequency();
				break;
			}
			break;
		case 2:
			break;
		}


	}
}


int main()
{
	Paragraph p1;

	ifstream fin;

	ofstream out;

	menu(fin, out, p1);

	return 0;
}





































//int main()
//{
//	char**** arr = nullptr;
//	arr = new char***[10];
//	
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = new char**[1];
//		arr[i][0] = new char*[1];
//		arr[i][0][0] = new char[1];
//	}
//
//	cout << "Enter : ";
//	for (int i = 1; i < 10; i++)
//	{
//		cin >> arr[i][0][0][0];
//	}
//	arr[0][0][0][0] = ' ';
//	for (int i = 1; i < 10; i++)
//	{
//		cout << arr[i][0][0][0];
//	}
//	cout << endl;
//
//	return 0;
//}