#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(sizeof(char) * (2 * n) + 1);
    int j = 0;

    const char* su = "수";
    const char* bark = "박";

    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            answer[i + j] = su[0];
            j++;
            answer[i + j] = su[1];
            j++;
        }
        else
        {
            answer[i + j] = bark[0];
            j++;
            answer[i + j] = bark[1];
            j++;
        }
    }

    return answer;
}