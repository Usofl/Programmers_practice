#include <string>
#include <vector>
#include <stack>
#include<cmath>

using namespace std;

string solution(int n) {
    string answer = "";

    if (n == 3)
    {
        return "4";
    }

    stack<int> s;

    while (n > 3) 
    {
        int temp = n % 3;
        
        if (temp == 0)
        {
            s.push(3);
            n = n / 3 - 1;
        }
        else
        {
            s.push(n % 3);
            n /= 3;
        }
    }
    s.push(n);

    while (!s.empty())
    {
        int num = s.top();

        s.pop();

        if (num == 3)
        {
            answer += "4";
        }
        else
        {
            answer += to_string(num);
        }
    }

    return answer;
}