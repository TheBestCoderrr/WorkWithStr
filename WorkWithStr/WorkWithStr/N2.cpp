#include <string.h>

typedef unsigned short int sot;
typedef long double lodo;
typedef long long int llont;

llont SetDil(llont Dil, llont FullNum) {
	while (Dil <= FullNum)
		Dil *= 10;
	Dil /= 10;

	return Dil;
}

sot CountNumsPeredCom(llont Dil, lodo Number) {
	sot  CountNumsPeredComa = 0;
	while (Dil <= Number) {
		Dil *= 10;
		CountNumsPeredComa++;
	}
	return CountNumsPeredComa;
}

void TransformNumberInStr(lodo Number, char StrNum[]) {

	sot Index = 0, TempZyfra , CountNumsPeredComa;

	llont FullNum, Dil = 1;

	if(Number > 0)
		CountNumsPeredComa = CountNumsPeredCom(Dil, Number);
	else if (Number < 0)
		CountNumsPeredComa = CountNumsPeredCom(Dil, Number * -1);

	do {
		FullNum = Number;
		Number *= 10;
	} while (FullNum % 10 != 0);
	FullNum /= 10;
	


	if (FullNum > 0) {
		

		Dil = SetDil(Dil, FullNum);
		
		while (Dil > 0) {
			if (Index == CountNumsPeredComa) {
				StrNum[Index++] = '.';
			}
			TempZyfra = FullNum / Dil % 10;
			Dil /= 10;
			StrNum[Index++] = TempZyfra + '0';

		}
	}
	else if (FullNum < 0) {
		StrNum[Index++] = '-';
		
		FullNum *= -1;
		Dil = SetDil(Dil, FullNum);

		while (Dil > 0) {
			if (Index == CountNumsPeredComa + 1) {
				StrNum[Index++] = '.';
			}
			TempZyfra = FullNum / Dil % 10;
			Dil /= 10;
			StrNum[Index++] = TempZyfra + '0';
		}
	}
	else
		StrNum[Index++] = '0';
	StrNum[Index] = '\0';
}