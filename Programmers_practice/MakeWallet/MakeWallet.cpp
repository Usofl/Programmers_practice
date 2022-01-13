#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_width = 0;
    int max_hight = 0;

    for (int i = 0; i < sizes.size(); ++i)
    {
        sort(sizes[i].begin(), sizes[i].end());

        if (i == 0)
        {
            max_width = sizes[i][0];
            max_hight = sizes[i][1];
        }

        if (max_width < sizes[i][0])
        {
            max_width = sizes[i][0];
        }

        if (max_hight < sizes[i][1])
        {
            max_hight = sizes[i][1];
        }
    }

    return max_width * max_hight;
}