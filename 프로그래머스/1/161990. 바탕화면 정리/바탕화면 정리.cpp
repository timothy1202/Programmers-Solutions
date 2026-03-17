#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> solution(vector<string> wallpaper) 
{
    int h = wallpaper.size();
    int w = wallpaper[0].size();

    int start_x = INT_MAX;
    int start_y = INT_MAX;
    int end_x = 0;
    int end_y = 0;

    for (int i = 0; i < h; i++) 
    {
        for (int j = 0; j < w; j++) 
        {
            if (wallpaper[i][j] == '#') 
            {
                if (i < start_x) start_x = i;
                if (j < start_y) start_y = j;
                
                if (i > end_x) end_x = i;
                if (j > end_y) end_y = j;
            }
        }
    }

    return {start_x, start_y, end_x + 1, end_y + 1};
}