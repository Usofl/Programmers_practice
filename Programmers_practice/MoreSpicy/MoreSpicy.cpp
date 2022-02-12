#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;

    if (scoville.size() == 1)
    {
        if (scoville[0] >= K)
        {
            return answer;
        }
        else
        {
            return -1;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < scoville.size(); ++i)
    {
        pq.push(scoville[i]);
    }

    while (pq.top() < K)
    {
        int min = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        min = min + (min2 * 2);
        pq.push(min);

        answer++;

        if (pq.size() == 1)
        {
            if (pq.top() >= K)
            {
                return answer;
            }
            else
            {
                return -1;
            }
        }
    }

    return answer;
}