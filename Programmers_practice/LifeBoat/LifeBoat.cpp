#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int solution(vector<int> people, int limit) {
	deque<int> save_people;
	int answer = 0;
	int i = 0, j = (people.size() - 1);

	sort(people.begin(), people.end());

	while (i <= j)
	{
		if (limit >= (people[i] + people[j]))
		{
			++i;
			--j;
			++answer;
		}
		else
		{
			--j;
			++answer;
		}
	}
	
	return answer;
}