#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> v;

    for (int i = 0; i < numbers.size(); ++i)
    {
        string num = to_string(numbers[i]);

        for (int j = 0; j < numbers.size(); ++j) 
        {
            if (i != j)
            {
                num += to_string(numbers[j]);
            }
        }

        v.push_back(num);
    }

    string answer = v[0];

    if (v.size() > 1)
    {
        for (int i = 1; i < v.size(); ++i)
        {
            if (answer != v[i])
            {
                int en = 0;

                if (answer.size() < v[i].size())
                {
                    en = 1;
                    continue;
                }
                else if (answer.size() == v[i].size())
                {
                    for (int j = 0; j < answer.size(); ++j)
                    {
                        if (answer[j] < v[i][j])
                        {
                            en = 1;
                            break;
                        }
                    }
                }

                if (en != 0)
                {
                    answer = v[i];
                }
            }
        }
    }

    return answer;
}