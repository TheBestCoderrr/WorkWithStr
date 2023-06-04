#include <iostream>
#include <string.h>

#include "N1.h"
#include "N2.h"

#define N 100

using namespace std;

typedef long double lodo;

void CinText(char Text[], int Size) {
	cout << "Enter Text: ";
	cin.getline(Text, Size);
}


void PrintStrArr(char StrArr[]) {
	for (int i = 0; i < strlen(StrArr); i++) {
		cout << StrArr[i];
	}
	cout << endl;
}

int main() {
	int Size = N;
	char* Text = new char[Size];

	CinText(Text, Size);

	Size = SetSizeText(Text, Size);

	char PatternSymbols[N];
	CinText(PatternSymbols, N);
	Text = DeleteSymbols(Text, PatternSymbols, Size);

	PrintStrArr(Text);
	delete[] Text;

	lodo Number;
	cout << "Enter Number: ";
	cin >> Number;

	char StrNum[N / 2];

	TransformNumberInStr(Number, StrNum);
	PrintStrArr(StrNum);
}