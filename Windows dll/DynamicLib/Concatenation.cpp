#include <string.h>
#include <iostream>
extern "C" __declspec(dllexport) char* concatination(char s1[], char s2[]) {
	strcat(s1, s2);
	return &s1[0];
}
