#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = n; i > 0; --i)
    {
        if (n % i == 0)
        {
            answer += i;
        }
    }

    return answer;
}