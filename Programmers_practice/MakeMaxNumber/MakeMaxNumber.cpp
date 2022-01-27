#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> v;
    string answer = "";

    while (numbers.size() != 0)
    {
        string num = to_string(numbers[0]);
        int count = 0;

        for (int i = 0; i < numbers.size(); ++i)
        {
            if (numbers[i] % 10 != 0)
            {
                if (num.compare(to_string(numbers[i])) < 0)
                {
                    num = to_string(numbers[i]);
                    count = i;
                }
            }
            else
            {
                if (num[0] == to_string(numbers[i])[0])
                {
                    if (num.compare(to_string(numbers[i])) > 0)
                    {
                        num = to_string(numbers[i]);
                        count = i;
                    }
                }
                else
                {
                    if (num.compare(to_string(numbers[i])) < 0)
                    {
                        num = to_string(numbers[i]);
                        count = i;
                    }
                }
            }
        }

        answer += num;
        numbers.erase(numbers.begin() + count);
    }
    
    return answer;
}