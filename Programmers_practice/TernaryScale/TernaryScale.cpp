#include <string>
#include <vector>
#include <stack>

using namespace std;

int Pow(int _num, int _i)
{
	int num = 1;
	for (int i = 0; i < _i; ++i)
	{
		num *= _num;
	}
	return num;
}

int solution(int n) {
	int answer = 0;
	stack<int> Tenary;
	int num = n;

	while (2 < num)
	{
		Tenary.push(num % 3);
		num = num / 3;
	}

	Tenary.push(num);

	int i = 0;
	while (!Tenary.empty())
	{
		answer += (Pow(3, i++) * (Tenary.top()));
		Tenary.pop();
	}

	return answer;
}
