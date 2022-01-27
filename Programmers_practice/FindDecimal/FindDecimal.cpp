#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

bool sosu(int num) {

    if (num < 2)
    {
        return false;
    }

    int a = (int)sqrt(num);

    for (int i = 2; i <= a; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;
    string num = "";

    set<int> s;

    sort(numbers.begin(), numbers.end());

    do {
        num = "";

        for (int i = 0; i < numbers.size(); ++i)
        {
            num += numbers[i];

            s.insert(stoi(num));
        }
    } while (next_permutation(numbers.begin(), numbers.end() + 1));

    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if (sosu(*it))
        {
            answer++;
        }
    }

    return answer;
}