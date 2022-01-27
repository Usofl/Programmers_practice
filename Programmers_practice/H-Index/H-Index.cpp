#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int temp = 0;
    int count = 0;
    int maxCount = 0;

    sort(citations.begin(), citations.end());

    if (citations[0] == citations.size())
    {
        return citations[0];
    }

    for(int i = 0; i < citations.size(); ++i)
    {
        count = 0;

        if (citations[i] == 0)
        {
            continue;
        }

        for (int j = 0; j < citations.size(); ++j)
        {
            if (citations[i] <= citations[j])
            {
                count++;
            }
        }

        maxCount = max(count, maxCount);

        if (citations[i] == count)
        {
            return count;
        }
        else if (citations[i] < count)
        {
            temp = citations[i];
        }

        if (temp != citations[i])
        {
            if (temp <= count)
            {
                return count;
            }
        }
    }

    return maxCount;
}