#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int su = 0;
    int su2 = 0;
    int su3 = 0;

    vector<int> v = { 1, 2, 3, 4, 5 };
    vector<int> v2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> v3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    auto it = v.begin();
    auto it2 = v2.begin();
    auto it3 = v3.begin();

    for (int i = 0; i < answers.size(); ++i)
    {
        if (it == v.end())
        {
            it = v.begin();
        }

        if (it2 == v2.end())
        {
            it2 = v2.begin();
        }

        if (it3 == v3.end())
        {
            it3 = v3.begin();
        }

        if (answers[i] == *it)
        {
            su++;
        }

        if (answers[i] == *it2)
        {
            su2++;
        }

        if (answers[i] == *it3)
        {
            su3++;
        }

        it++;
        it2++;
        it3++;
    }

    if (su == su2 && su == su3)
    {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    else if (su == su2 && su != su3)
    {
        if (su > su3)
        {
            answer.push_back(1);
            answer.push_back(2);
        }
        else
        {
            answer.push_back(3);
        }
    }
    else if (su == su3 && su != su2)
    {
        if (su > su2)
        {
            answer.push_back(1);
            answer.push_back(3);
        }
        else
        {
            answer.push_back(2);
        }
    }
    else if (su2 == su3 && su2 != su)
    {
        if (su2 > su)
        {
            answer.push_back(2);
            answer.push_back(3);
        }
        else
        {
            answer.push_back(1);
        }
    }
    else
    {
        if (su > su2 && su > su3)
        {
            answer.push_back(1);
        }
        else if (su2 > su && su2 > su3)
        {
            answer.push_back(2);
        }
        else if (su3 > su && su3 > su2)
        {
            answer.push_back(3);
        }
    }

    return answer;
}