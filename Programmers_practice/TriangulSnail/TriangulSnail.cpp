#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	vector<int> snail;

	snail.reserve(n * n);
	int row = 0;
	int col = 0;
	int cross = 0;
	int num = 1;

	for (int i = 0; i < (n / 2) + 1; ++i)
	{
		for (int j = col; j < n - col - row; ++j)
		{
			snail[(n * (j + row)) + col] = num++;
		}

		row++;

		for (int j = row; j <= n - col - row; ++j)
		{
			snail[(n * (n - row)) + j] = num++;
		}

		col++;

		for (int k = n - col - row + i; k > i + cross; --k)
		{
			snail[(n * k) + (k - i)] = num++;
		}
		
		cross++;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			answer.push_back(snail[(n * i) + j]);
		}
	}

	return answer;
}