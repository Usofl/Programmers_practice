#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string ns, ns2;
    map<string, char> m;

    m.insert(pair<string, char>("zero", '0'));
    m.insert(pair<string, char>("one", '1'));
    m.insert(pair<string, char>("two", '2'));
    m.insert(pair<string, char>("three", '3'));
    m.insert(pair<string, char>("four", '4'));
    m.insert(pair<string, char>("five", '5'));
    m.insert(pair<string, char>("six", '6'));
    m.insert(pair<string, char>("seven", '7'));
    m.insert(pair<string, char>("eight", '8'));
    m.insert(pair<string, char>("nine", '9'));

    for (int i = 0; i < s.size(); ++i)
    {
        if (!('0' <= s[i] && '9' >= s[i]))
        {
            ns.push_back(s[i]);
        }
        else
        {
            ns2.push_back(s[i]);
        }

        auto it = m.find(ns);

        if (it != m.end())
        {
            ns2.push_back(it->second);
            ns.clear();
        }
    }

    stringstream ssInt(ns2);

    ssInt >> answer;

    return answer;
}

int main()
{
    string s = "one4seveneight";

    cout << solution(s) << endl;

    return 0;
}