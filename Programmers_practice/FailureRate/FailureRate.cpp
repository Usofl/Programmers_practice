#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N, 0);
    map<int, double> m;

    for (int i = 1; i <= N; ++i)
    {
        int challenger = 0;
        int failed = 0;

        for (int j = 0; j < stages.size(); ++j)
        {
            if (i < stages[j])
            {
                challenger++;
            }
            else if (i == stages[j])
            {
                challenger++;
                failed++;
            }
        }
        
        if (challenger == 0)
        {
            m.insert({i, -1});
        }
        else
        {
            m.insert({i, static_cast<double>(failed) / challenger});
        }
    }

    for (auto it = m.begin(); it != m.end(); ++it)
    {
        int count = 0;

        for (auto it2 = m.begin(); it2 != m.end(); ++it2)
        {
            if (it->first != it2->first)
            {
                if (it->second < it2->second || (it->first > it2->first && it->second == it2->second))
                {
                    count++;
                }
            }
        }
        answer[count] = it->first;
    }

    return answer;
}