#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    // 1. 꺼내려는 상자의 행(r)과 열(c) 구하기 (0-indexed)
    int r = (num - 1) / w;
    int idx = (num - 1) % w; // 층 내에서의 순서
    
    // 2. 지그재그 보정: 짝수 행(0, 2, ...)은 왼쪽->오른쪽, 홀수 행(1, 3, ...)은 오른쪽->왼쪽
    // 모든 상자의 열(c)을 '왼쪽 기준'으로 통일합니다.
    int c = (r % 2 == 0) ? idx : (w - 1 - idx);
    
    int count = 0;
    
    // 3. 내 상자(r, c) 위쪽 행들을 하나씩 검사
    for (int next_r = r; next_r * w + 1 <= n; ++next_r) {
        // 짝수 행이면 c번째, 홀수 행이면 (w-1-c)번째에 상자가 있음
        int current_col = (next_r % 2 == 0) ? c : (w - 1 - c);
        
        // 해당 행에 상자 번호가 존재하는지 확인
        if (next_r * w + current_col + 1 <= n) {
            count++;
        }
    }
    
    return count;
}