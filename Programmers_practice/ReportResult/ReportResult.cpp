#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    vector<string> v;
    set<string> s;

    map<string, int> m;
    map<string, int> m2;

    for (int i = 0; i < id_list.size(); ++i)
    {
        m[id_list[i]] = 0;
        m2[id_list[i]] = 0;
    }

    for (int i = 0; i < report.size(); ++i)
    {
        s.insert(report[i]);
    }

    if (s.size() < k)
    {
        for (int i = 0; i < id_list.size(); ++i)
        {
            answer.push_back(0);
        }

        return answer;
    }

    for(auto it = s.begin(); it != s.end(); ++it)
    {
        string report = *it;

        stringstream ss(report);
        string word;

        string name = "";

        while (getline(ss, word, ' ')) {
            
            v.push_back(word);

            if (name != "")
            {
                m[word]++;
            }

            name = word;
        }
    }

    for (int i = 0; i < v.size(); ++i)
    {
        if (i % 2 == 0)
        {
            continue;
        }

        if (m[v[i]] >= k)
        {
            m2[v[i - 1]]++;
        }
    }

    for (int i = 0; i < id_list.size(); ++i)
    {
        answer.push_back(m2[id_list[i]]);
    }

    return answer;
}