#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void sosu_check(set<int>& _set, set<int>& _nset, int& _num)
{
	if ((_set.find(_num) == _set.end()))
	{
		if ((_nset.find(_num) == _nset.end()))
		{
			int num = sqrt(_num);
			for (int i = 2; i <= num; ++i)
			{
				if (0 == (_num % i))
				{
					_nset.insert(_num);
					return;
				}
			}
			_set.insert(_num);
		}
	}
}

int solution(vector<int> nums) {
	int answer = 0;
	set<int> sosu;
	set<int> nsosu;
	sort(nums.begin(), nums.end());

	int num = 0;

	do {
		num = 0;
		for (int i = 0; i < 3; ++i) {
			num += nums[i];
		}
		if (0 != num % 2)
		{
			sosu_check(sosu, nsosu, num);
		}
	} while (next_permutation(nums.begin(), nums.end()));

	return sosu.size();
}