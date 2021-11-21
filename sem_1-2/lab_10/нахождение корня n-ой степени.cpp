#include <iostream>
#include <cmath>

using namespace std;

float rec(const float x, const int k, int n)
{
	if (n == 0)
		return 1;
	return rec(x, k, n - 1) - (rec(x, k, n - 1) - x / pow(rec(x, k, n - 1), k - 1)) / k;
}

int main()
{
	cout << "Enter number, X, K, N: ";
	float x;
	int k, n;
	cin >> x >> k >> n;
	cout << rec(x, k, n) << endl;
	return 0;
}