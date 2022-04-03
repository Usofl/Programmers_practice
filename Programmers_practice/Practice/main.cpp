#include <iostream>

using namespace std;

int sun(int i, int j);

int main()
{
	cout << sun(6, 3) << endl;

	return 0;
}

int sun(int i, int j)
{
	if (i == 1 || j == 1)
	{
		return i;
	}

	return i * sun(i - 1, j - 1);
}