#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    if (n > 3) 
    {
        for (int i = 2; i < n; ++i)
        {
            if (n % i == 1)
            {
                answer = i;
                break;
            }
        }
    }

    return answer;
}