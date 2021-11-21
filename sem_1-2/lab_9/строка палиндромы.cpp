#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

typedef std::istream_iterator<std::string> is;

void pol(const std::string& w)
{
	std::string::size_type i = 0, j = w.size() - 1;
	while (i < j)
	{
		if (w[i++] != w[j--])
		{
			break;
		}
	}
	if (j <= i)
	{
		std::cout << w << ' ';
	}
}

int main()
{
	std::string line;
	std::cout << "Put line: ";
	std::getline(std::cin, line);
	std::stringstream str(line);
	std::vector<std::string> v((is(str)), is());
	std::for_each(v.begin(), v.end(), pol);
}