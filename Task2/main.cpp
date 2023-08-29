#include"word.h"
#include<iostream>
#include<fstream>
#include"sentence.h"
#include"paragraph.h"
#include"file.h"
using namespace std;

//L1F20BSCS0372  Mohid Hameed  Section 'C7' task 1
//L1F20BSCS0381  Ahmad Hassan  Section 'C7' task 2


int main() {
	ifstream fin;
	ofstream fout("output.txt");
	file f1;
	file f2;
	bool f=false;
	//fin >> f1;
	////f2 = f1;
	////f3 = f1 + f2;
	///*cout << f1;
	//cout << f2;*/
	////f2 + f1;
	///*f1.EncryptData(12);
	//f1.DecryptData(12);
	//f1++;
	//fout << f1;
	//f1--;
	//cout << f1;
	//f1.operationSix();
	//f1.GetFrequency();*/
	//f1.spell_check();
	int choice;
	while (1) {
		//system("CLS");
		cout << "Press 0 > to EXIT " << endl;
		cout << "Press 1 > to Read Data In OBJECT " << endl;
		cout << "Press 2 > to Write in File " << endl;
		cout << "Press 3 > to Write on console " << endl;
		cout << "Press 4 > to Convert Paragraph into Upper Case " << endl;
		cout << "Press 5 > to Convert Paragraph into Lower Case " << endl;
		cout << "Press 6 > to Encript Data " << endl;
		cout << "Press 7 > to Decrypt Data " << endl;
		cout << "Press 8 > to Concatinate " << endl;
		cout << "Press 9 > to print frequency " << endl;
		cout << "Press 10 > to word check using dictionary " << endl;
		cout << "Press 11 > to count Punctuations and Alphabets " << endl;
		cout << "PLEASE ENTER : ";
		cin >> choice;
		if (choice == 0) {
			break;
		}
		else if (choice == 1) {
			system("CLS");
			cout << "INPUT FROM FILE SUCESSFUL !!!\n\n";
			fin >> f1;
			cout << endl << endl << endl;
			f = true;
		}
		if (f) {

		if (choice == 2) {
			system("CLS");
			cout << "DATA STORED IN output.txt \n\n";
			fout << f1;
			cout << endl << endl << endl;
		}
		else if (choice == 3) {
			system("CLS");
			cout << f1 << endl;
			cout << endl << endl << endl;
		}
		else if (choice == 4) {
			system("CLS");
			f1++;
			cout << "converted to upper case sucessfully !!!!\n\n";
			cout << f1;
			cout << endl << endl << endl;
		}
		else if (choice == 5) {
			system("CLS");
			f1--;
			cout << "converted to lower case sucessfully !!!!\n\n";
			cout << f1;
			cout << endl << endl << endl;
		}
		else if (choice == 6) {
			system("CLS");
			f1 * 10;
			cout << "Data Encrypted sucessfully !!!!\n\n";
			cout << f1;
			cout << endl << endl << endl;
		}
		else if (choice == 7) {
			system("CLS");
			f1 % 10;
			cout << "Data Decrypted sucessfully !!!!\n\n";
			cout << f1;
			cout << endl << endl << endl;
		}
		else if (choice == 8) {
			fin >> f2;
			f1 + f2;
			system("CLS");
			cout << "data after concatination :\n\n";
			cout << f1;
			cout << endl << endl << endl;
		}
		else if (choice == 9) {
			system("CLS");
			cout << "Frequency stored in frequency.txt\n\n";
			f1.GetFrequency();
			cout << endl << endl << endl;
		}
		else if (choice == 10) {
			system("CLS");
			cout << "words not present in dictionary are :-\n\n";
			f1.spell_check();
			cout << endl << endl << endl;
		}
		else if (choice == 11) {
			system("CLS");
			f1.operationSix();
			cout << endl << endl << endl;
		}
		}
		else {
			cout << "First Read DATA \n\n\n";
		}

	}
}