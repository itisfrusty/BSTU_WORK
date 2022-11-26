/*#include <iostream>
#include <ctime>
#include <string.h>
using namespace std;

void C_tab(char* str, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			str[i] = '\t';
		}
	}
}

int main()
{
	char str[100];
	cout << "Please input string: ";
	cin.getline(str, 100);
	int len = strlen(str);
	cout << "C++ result: ";
	clock_t start = clock();
	for (int i = 0; i < 10000; i++)
		C_tab(str, len);
	clock_t finish = clock();
	for (int i = 0; i < len; i++)
	{
		cout << str[i];
	}
	cout << endl;
	cout << "Time:" << finish - start << endl;
	return 0;
} 
*/

