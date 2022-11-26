#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;
int Asmb_tabl(char* str, int len)
{
	_asm
	{
		jmp start

		zamena :
		mov[esi], 9h
			inc esi
			jmp loopstart

			start :
		mov esi, str
			mov ecx, len

			loopstart :
		mov eax, esi
			cmp byte ptr[esi], 20h
			je zamena
			inc esi
			loop loopstart
	}
	return 0;
}

int main()
{
	clock_t start, finish;
	char str[100];
	cout << "Please input string: ";
	cin.getline(str, 100);
	int len = strlen(str);
	cout << "Assembler result: \t";
	start = clock();
	for (int i = 0; i < 1000000; i++)
		Asmb_tabl(str, len);
	finish = clock();
	for (int i = 0; i < len; i++)
	{
		cout << str[i];
	}
	cout << endl;
	cout << "Time:" << finish - start << endl;
	return 0;
}