#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> moveList;

    for (int i = 0; i < commands.size(); ++i)
    {
        moveList.clear();

        moveList.assign(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        
        sort(moveList.begin(), moveList.end());

        answer.push_back(moveList[commands[i][2] - 1]);
    }

    return answer;
}