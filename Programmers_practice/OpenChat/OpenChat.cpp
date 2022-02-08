#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<string> v;
    map<string, string> m;

    for (int i = 0; i < record.size(); ++i)
    {
        int count = 0;

        string s = record[i];

        stringstream ss(s);
        string word;

        while (getline(ss, word, ' ')) {
            if (count == 2)
            {
                m[v[v.size() - 1]] = word;
                break;
            }
            v.push_back(word);
            count++;
        }
    }

    for (int i = 0; i < v.size() - 1; ++i)
    {
        if (i % 2 == 0)
        {
            string name = m[v[i + 1]];

            if (v[i] == "Enter")
            {
                answer.push_back(name + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
            }
            else if (v[i] == "Leave")
            {
                answer.push_back(name + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
            }
        }
    }

    return answer;
}