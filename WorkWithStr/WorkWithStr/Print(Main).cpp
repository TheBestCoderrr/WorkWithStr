#include <iostream>
#include <string.h>

#define N 100

using namespace std;

void CinText(char Text[], int Size) {
	cout << "Enter Text: ";
	cin.getline(Text, Size);
}

int SetSizeText(char Text[], int Size) {
	int i = 0;
	while (Text[i] != '\0')
		i++;
	Size = i + 1;
	Text[Size - 1] = '\0';

	return Size;
}

char* DeleteSymbols(char Text[], char PatternSymbols[], int Size) {
	char* NewText = new char[Size];

	for (int i = 0; i < strlen(Text); i++)
		NewText[i] = Text[i];
	NewText[Size - 1] = '\0';

	for (int i = 0; i < strlen(NewText); i++) {
		for (int j = 0; j < strlen(PatternSymbols); j++) {
			if (NewText[i] == PatternSymbols[j]) {
				for (int n = i; n < strlen(Text) - 1; n++) {
					NewText[n] = NewText[n + 1];
				}
				Size -= 1;
				NewText[Size - 1] = '\0';
				i--;
			}
		}
	}

	return NewText;
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