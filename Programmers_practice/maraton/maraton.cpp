#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    for (int i = 0; i < completion.size(); ++i) {
        auto it = find(participant.begin(), participant.end(), completion[i]);

        if (it != participant.end())
        {
            participant.erase(it);
            continue;
        }
    }

    answer = participant[0];

    return answer;
}