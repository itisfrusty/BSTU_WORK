#include <iostream>
#include <Windows.h>

using namespace std;

int main() {

	HINSTANCE load;
	load = LoadLibrary(L"DynamicLib.dll");
	typedef char* (*concatination) (char*, const char*);
	concatination completion;
	completion = (concatination)GetProcAddress(load, "concatination");

	char s1[40];
	char s2[40];
	
	cout << "Enter string one: ";
	cin >> s1;
	cout << "Enter string two: ";
	cin >> s2;
	cout << completion(&s1[0], &s2[0]);
	FreeLibrary(load);
	
}