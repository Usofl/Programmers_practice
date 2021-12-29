#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> selectDoll;

    for (int i = 0; i < moves.size(); ++i)
    {
        for (int j = 0; j < board.size(); ++j)
        {
            if (board[j][moves[i] - 1] != 0)
            {
                if (selectDoll.empty())
                {
                    selectDoll.push(board[j][moves[i] - 1]);
                }
                else
                {
                    if (selectDoll.top() == board[j][moves[i] - 1])
                    {
                        selectDoll.pop();
                        answer += 2;
                    }
                    else
                    {
                        selectDoll.push(board[j][moves[i] - 1]);
                    }
                }
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> test;

    vector<int> test1;
    vector<int> test2;
    vector<int> test3;
    vector<int> test4;
    vector<int> test5;

    test1.push_back(0);
    test1.push_back(0);
    test1.push_back(0);
    test1.push_back(0);
    test1.push_back(0);

    test2.push_back(0);
    test2.push_back(0);
    test2.push_back(1);
    test2.push_back(0);
    test2.push_back(3);

    test3.push_back(0);
    test3.push_back(2);
    test3.push_back(5);
    test3.push_back(0);
    test3.push_back(1);

    test4.push_back(4);
    test4.push_back(2);
    test4.push_back(4);
    test4.push_back(4);
    test4.push_back(2);

    test5.push_back(3);
    test5.push_back(5);
    test5.push_back(1);
    test5.push_back(3);
    test5.push_back(1);

    test.push_back(test1);
    test.push_back(test2);
    test.push_back(test3);
    test.push_back(test4);
    test.push_back(test5);

    vector<int> move;

    move.push_back(1);
    move.push_back(5);
    move.push_back(3);
    move.push_back(5);
    move.push_back(1);
    move.push_back(2);
    move.push_back(1);
    move.push_back(4);

    cout << solution(test, move) << endl;

    return 0;
}