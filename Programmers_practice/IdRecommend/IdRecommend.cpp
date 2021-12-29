#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    vector<char> space;

    for (int i = 0; i < new_id.size(); ++i)
    {
        if ('A' <= new_id[i] && 'Z' >= new_id[i])
        {
            new_id[i] += 32;
        }

        if (!('.' == new_id[i] || '_' == new_id[i] || '-' == new_id[i] || ('a' <= new_id[i] && 'z' >= new_id[i])
            || ('0' <= new_id[i] && '9' >= new_id[i])))
        {
            auto it = find(space.begin(), space.end(), new_id[i]);

            if(it == space.end())
            {
                space.push_back(new_id[i]);
            }
        }
    }

    for (int j = 0; j < space.size(); j++)
    {
        new_id.erase(remove(new_id.begin(), new_id.end(), space[j]), new_id.end());
    }

    if (new_id != "")
    {
        while ('.' == new_id[0])
        {
            new_id.erase(0, 1);
        }
    }

    if (new_id != "")
    {
        while ('.' == new_id[new_id.size() - 1])
        {
            new_id.erase(new_id.size() - 1);
        }
    }

    for (int i = 0; i < new_id.size(); ++i)
    {
        if ('.' == new_id[i])
        {
            if ('.' == new_id[i + 1])
            {
                new_id.erase(i + 1, 1);
                i--;
                continue;
            }
        }
    }

    if (new_id == "")
    {
        new_id.push_back('a');
    }

    if (new_id.size() >= 16)
    {
        new_id.resize(15);
    }

    while('.' == new_id[new_id.size() - 1])
    {
        new_id.erase(new_id.size() - 1);
    }

    if (new_id.size() <= 2)
    {
        while (new_id.size() < 3)
        {
            new_id.push_back(new_id[new_id.size() - 1]);
        }
    }

    return new_id;
}

int main()
{
    string test = "...!@BaT#*..y.abcdefghijklm";

    cout << solution(test) << endl;

    return 0;
}