#include <string>
#include <vector>
using namespace std;

int solution(string dirs) 
{
    // [x][y][방향]: U=0, D=1, L=2, R=3
    vector<vector<vector<bool>>> visited(11, vector<vector<bool>>(11, vector<bool>(4, false)));

    int x = 5, y = 5, answer = 0;

    // U, D, L, R 순서
    int dx[] = { 0,  0, -1,  1};
    int dy[] = { 1, -1,  0,  0};
    int reverse_dir[] = {1, 0, 3, 2};  // U↔D, L↔R 명시적으로 정의
    //U→D D→U L→R R→L

    for (char c : dirs) 
    {
        int dir;
        if      (c == 'U') dir = 0;
        else if (c == 'D') dir = 1;
        else if (c == 'L') dir = 2;
        else               dir = 3;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx > 10 || ny < 0 || ny > 10) continue;

        if (!visited[x][y][dir]) 
        {
            visited[x][y][dir]      = true;  // 정방향
            visited[nx][ny][reverse_dir[dir]] = true;  // 역방향 배열로 해결
            answer++;
        }

        x = nx;
        y = ny;
    }

    return answer;
}