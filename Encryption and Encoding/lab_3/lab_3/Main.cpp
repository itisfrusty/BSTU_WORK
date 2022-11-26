#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "archive.h"

int main()

{

	std::string files[3] = { "Pic03.bmp", "text03.doc", "text03.txt" };

	archive a1;

	a1.compress(files[0]);

	a1.compress(files[1]);

	a1.compress(files[2]);

	a1.decompress(files[0]);

	a1.decompress(files[1]);

	a1.decompress(files[2]);

	return 0;

}