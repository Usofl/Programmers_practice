#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	map<int, int> Staff;
	int time = 0;

	sort(times.begin(), times.end());

	for (auto iter = times.begin(); iter != times.end(); ++iter)
	{
		Staff[(*iter)] = (*iter);
		--n;
		if (0 == n)
		{
			break;
		}
	}

	while (n != 0)
	{
		for (auto iter = Staff.begin(); iter != Staff.end(); ++iter)
		{
			if (iter->second != 0)
			{
				--(iter->second);
			}

			if (iter->first == times[times.size() - 1])
			{
				++answer;
			}
			if (n == 0)
			{
				if (iter->first != times[times.size() - 1])
				{
					++answer;
				}
				break;
			}

			if (0 == iter->second)
			{
				int gap = iter->first;
				bool wait = false;

				for (auto iter2 = Staff.begin(); iter2 != Staff.end(); ++iter2)
				{
					if (iter2->first >= gap)
					{
						continue;
					}
					else if (iter2->second < (gap - iter2->first))
					{
						wait = true;
						break;
					}
				}
				if (!wait)
				{
					--n;
					iter->second = iter->first;
				}
			}
		}
	}


	for (auto iter = Staff.begin(); iter != Staff.end(); ++iter)
	{
		if (0 < iter->second)
		{
			answer += iter->second;
		}
	}

	return answer;
}