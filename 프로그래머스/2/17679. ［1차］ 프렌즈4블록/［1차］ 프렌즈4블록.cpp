#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<string> board) 
{
    int answer = 0;

    while (true) 
    {
        // 1. 제거 대상 마킹
        vector<vector<bool>> remove(m, vector<bool>(n, false));
        
        for (int i = 0; i < m - 1; i++) 
        {        // ✅ m-1까지만
            for (int j = 0; j < n - 1; j++) 
            {    // ✅ n-1까지만
                char block = board[i][j];
                if (block == '.' ) continue;      // 빈칸 스킵
                
                if (board[i+1][j] == block &&
                    board[i][j+1] == block &&
                    board[i+1][j+1] == block) 
                {
                    // 4칸 모두 마킹
                    remove[i][j] = remove[i+1][j] = true;
                    remove[i][j+1] = remove[i+1][j+1] = true;
                }
            }
        }
        
        // 2. 제거할 블록이 없으면 종료
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (remove[i][j]) cnt++;
        
        if (cnt == 0) break;   // ✅ 종료 조건
        answer += cnt;
        
        // 3. 블록 제거 ('.'으로 교체)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (remove[i][j]) board[i][j] = '.';
        
        // 4. 블록 낙하 (열 단위로 아래부터 채우기)
        for (int j = 0; j < n; j++) 
        {
            int empty = m - 1;  // 빈 자리 포인터
            for (int i = m - 1; i >= 0; i--) 
            {
                if (board[i][j] != '.') 
                {
                    board[empty][j] = board[i][j];
                    if (empty != i) board[i][j] = '.';
                    empty--;
                }
            }
            // 남은 위쪽 빈칸 처리
            while (empty >= 0) 
            {
                board[empty][j] = '.';
                empty--;
            }
        }
    }

    return answer;
}