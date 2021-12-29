#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;

	auto iter2 = signs.begin();

	for (auto iter = absolutes.begin(); iter != absolutes.end(); ++iter)
	{
		if (*iter2)
		{
			answer += *iter;
			iter2++;
		}
		else
		{
			answer -= *iter;
			iter2++;
		}
	}

    return answer;
}