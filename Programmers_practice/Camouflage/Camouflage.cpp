#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int combination(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	else
		return combination(n - 1, r - 1) + combination(n - 1, r);
}

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	set<string> clo_kind;
	map<string, int> clo_kind_count;

	auto iter = clo_kind_count.begin();

	for (int i = 0; i < clothes.size(); ++i)
	{
		clo_kind.insert(clothes[i][1]);
		if ((iter = clo_kind_count.find(clothes[i][1])) != clo_kind_count.end())
		{
			++(iter->second);
		}
		else 
		{
			clo_kind_count.insert({ clothes[i][1], 1 });
		}
	}

	if (1 == clo_kind.size())
	{
		return clothes.size();
	}

	for (auto iter2 = clo_kind_count.begin(); iter2 != clo_kind_count.end(); ++iter2)
	{
		answer *= (iter2->second + 1);
	}

	--answer;

	return answer;
}

