#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) 
{
    int h = park.size();
    int w = park[0].size();
    int cur_r = 0, cur_c = 0;

    // 1. 시작 위치 찾기
    for (int i = 0; i < h; i++) 
    {
        for (int j = 0; j < w; j++) 
        {
            if (park[i][j] == 'S') 
            {
                cur_r = i;
                cur_c = j;
                break;
            }
        }
    }

    for (const string& route : routes) 
    {
        stringstream ss(route);
        char dir;
        int dist;
        ss >> dir >> dist;

        int nr = cur_r;
        int nc = cur_c;
        bool is_safe = true;

        // 2. 이동 가능 여부 체크 (한 칸씩 확인)
        for (int i = 0; i < dist; i++) 
        {
            if (dir == 'N') nr--;
            else if (dir == 'S') nr++;
            else if (dir == 'W') nc--;
            else if (dir == 'E') nc++;

            // 공원 범위를 벗어나거나 장애물('X')을 만나는지 확인
            if (nr < 0 || nr >= h || nc < 0 || nc >= w || park[nr][nc] == 'X') 
            {
                is_safe = false;
                break;
            }
        }

        // 3. 안전할 때만 현재 위치 업데이트
        if (is_safe) 
        {
            cur_r = nr;
            cur_c = nc;
        }
    }

    return { cur_r, cur_c };
}