#include "lotto.h"
#include <string>
#include <vector>

using namespace std;

vector<int> lotto::solution(vector<int> lottos, vector<int> win_nums)
{
	vector<int> answer;

	int count = 0;
	int zero = 0;
	
	for (auto iter = lottos.begin(); iter != lottos.end(); ++iter)
	{
		if (*iter == 0)
		{
			++zero;
		}

		for (auto iter2 = win_nums.begin(); iter2 != win_nums.end(); ++iter2)
		{
			if (*iter == *iter2)
			{
				++count;
			}
		}
	}

	switch (count + zero)
	{
	case 6: 
		answer.push_back(1);
		break;
	case 5:
		answer.push_back(2);
		break;
	case 4:
		answer.push_back(3);
		break;
	case 3:
		answer.push_back(4);
		break;
	case 2:
		answer.push_back(5);
		break;
	default:
		answer.push_back(6);
		break;
	}

	switch (count)
	{
	case 6:
		answer.push_back(1);
		break;
	case 5:
		answer.push_back(2);
		break;
	case 4:
		answer.push_back(3);
		break;
	case 3:
		answer.push_back(4);
		break;
	case 2:
		answer.push_back(5);
		break;
	default:
		answer.push_back(6);
		break;
	}

	return answer;
}