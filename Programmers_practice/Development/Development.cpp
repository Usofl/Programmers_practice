#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int count = 0;
	int check = 0;

	while (count < progresses.size())
	{
		check = count;

		for (int i = check; i < progresses.size(); ++i)
		{
			progresses[i] += speeds[i];
		}

		while (100 <= progresses[count] && count != progresses.size())
		{
			if (count < progresses.size())
			{
				++count;
			}
		}

		if (count != check)
		{
			answer.push_back(count - check);
		}
	}

	return answer;
}