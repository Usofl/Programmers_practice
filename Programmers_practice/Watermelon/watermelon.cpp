#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

char* solution(int n) {
    // ������ ���� �޸𸮸� ���� �Ҵ����ּ���.
    char* answer = (char*)malloc(sizeof(char) * (2 * n) + 1);
    int j = 0;

    const char* su = "��";
    const char* bark = "��";

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