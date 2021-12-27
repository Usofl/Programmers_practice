#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

	for (auto iter = completion.begin(); iter != completion.end(); ++iter)
	{
		for (auto iter2 = participant.begin(); iter2 != participant.end(); ++iter2)
		{
			if (*iter == *iter2)
			{
				participant.erase(iter2);
				break;
			}
		}
	}

	answer = participant[0];

    return answer;
}