#include <iostream>
#include <string.h>

#include "N1.h"

#define N 100

using namespace std;

void CinText(char Text[], int Size) {
	cout << "Enter Text: ";
	cin.getline(Text, Size);
}


void PrintText(char Text[]) {
	for (int i = 0; i < strlen(Text); i++) {
		cout << Text[i];
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

	PrintText(Text);
	delete[] Text;
}