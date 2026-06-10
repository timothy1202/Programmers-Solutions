#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int solution(vector<string> storage, vector<string> requests) {
    int n = storage.size();
    int m = storage[0].size();
    
    // 외곽에 1칸씩 패딩을 두른 대형 지도 생성 (n+2 x m+2)
    // '.' 은 비어있는 공간을 의미합니다.
    vector<vector<char>> grid(n + 2, vector<char>(m + 2, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i + 1][j + 1] = storage[i][j];
        }
    }
    
    for (const string& req : requests) {
        char target = req[0];
        
        if (req.size() == 2) {
            // 1. 크레인 작동: 조건 없이 해당 알파벳 모두 제거
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (grid[i][j] == target) {
                        grid[i][j] = '.';
                    }
                }
            }
        } 
        else {
            // 2. 지게차 작동: 외부와 연결된 알파벳만 제거
            queue<pair<int, int>> q;
            vector<vector<bool>> visited(n + 2, vector<bool>(m + 2, false));
            vector<pair<int, int>> targets_to_remove;
            
            // 외부(0, 0)에서 시작해 탐색 진행
            q.push({0, 0});
            visited[0][0] = true;
            
            while (!q.empty()) {
                auto [y, x] = q.front();
                q.pop();
                
                for (int d = 0; d < 4; d++) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];
                    
                    if (ny < 0 || ny >= n + 2 || nx < 0 || nx >= m + 2) continue;
                    if (visited[ny][nx]) continue;
                    
                    // 빈 공간이면 계속해서 파고 들어감
                    if (grid[ny][nx] == '.') {
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                    } 
                    // 외부와 맞닿은 목표 컨테이너 발견 시 제거 목록에 추가 (더 전진은 불가)
                    else if (grid[ny][nx] == target) {
                        visited[ny][nx] = true;
                        targets_to_remove.push_back({ny, nx});
                    }
                }
            }
            
            // 수집한 외부 노출 컨테이너들을 한 번에 제거
            for (auto& p : targets_to_remove) {
                grid[p.first][p.second] = '.';
            }
        }
    }
    
    // 최종적으로 남아있는 컨테이너 개수 count
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] != '.') {
                answer++;
            }
        }
    }
    
    return answer;
}