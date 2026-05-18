#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    int n = land.size();

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int best = 0;
            for (int k = 0; k < 4; k++)
            {
                if (k == j) continue;
                best = max(best, land[i-1][k]);
            }
            land[i][j] += best;
        }
    }

    return *max_element(land[n-1].begin(), land[n-1].end());
}