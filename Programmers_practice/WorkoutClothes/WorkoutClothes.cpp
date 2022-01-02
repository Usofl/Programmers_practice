#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = (n - lost.size());

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (auto lost_it = lost.begin(); lost_it != lost.end(); ++lost_it)
    {
        for (auto it = reserve.begin(); it != reserve.end(); ++it)
        {
            if (*lost_it == *it)
            {
                answer++;
                lost.erase(lost_it);
                reserve.erase(it);
                lost_it--;
                break;
            }
        }
    }

    for (int i = 0; i < lost.size(); ++i)
    {
        for (auto it = reserve.begin(); it != reserve.end(); ++it)
        {
            if (1 >= lost[i] - *it && -1 <= lost[i] - *it)
            {
                answer++;
                reserve.erase(it);
                break;
            }
        }
    }

    return answer;
}