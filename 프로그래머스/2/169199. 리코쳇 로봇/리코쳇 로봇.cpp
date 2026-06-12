#include <string>
#include <vector>
#include <queue>

using namespace std;

// 상, 하, 좌, 우 이동을 위한 방향 배열
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Robot {
    int x, y, dist;
};

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();
    
    int startX = 0, startY = 0;
    int goalX = 0, goalY = 0;
    
    // 시작 위치(R)와 목표 위치(G) 찾기
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'R') {
                startX = i; startY = j;
            }
            if(board[i][j] == 'G') {
                goalX = i; goalY = j;
            }
        }
    }
    
    // 방문 여부 체크 배열
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<Robot> q;
    
    // 시작점 큐에 삽입 및 방문 처리
    q.push({startX, startY, 0});
    visited[startX][startY] = true;
    
    while(!q.empty()) {
        Robot cur = q.front();
        q.pop();
        
        // 목표 지점에 도달하면 현재까지의 이동 횟수 반환
        if(cur.x == goalX && cur.y == goalY) {
            return cur.dist;
        }
        
        // 4방향으로 미끄러지기
        for(int i = 0; i < 4; i++) {
            int nx = cur.x;
            int ny = cur.y;
            
            // 벽이나 장애물('D')을 만나기 직전까지 계속 직진
            while(true) {
                int nextX = nx + dx[i];
                int nextY = ny + dy[i];
                
                // 범위를 벗어나거나 장애물을 만나면 멈춤
                if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || board[nextX][nextY] == 'D') {
                    break;
                }
                
                nx = nextX;
                ny = nextY;
            }
            
            // 도달한 최종 위치가 아직 방문하지 않은 곳이라면 큐에 추가
            if(!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, cur.dist + 1});
            }
        }
    }
    
    // 목표 지점에 도달할 수 없는 경우 -1 반환
    return -1;
}