#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer = 0;
    int size = board.size();
    vector<int> picked; // 인형을 담을 바구니 (스택 역할)
    
    for(const int& num : moves)
    {
        int col = num - 1; // 1-base 인덱스를 0-base로 변환
        
        for(int i = 0; i < size; i++)
        {
            // 인형이 있는 칸을 찾을 때까지 내려감
            if(board[i][col] == 0)
            {
                continue;
            }
            else 
            {
                int current_doll = board[i][col];
                board[i][col] = 0; // 인형을 뽑았으므로 빈칸 처리
                
                // 바구니가 비어있지 않고, 맨 위 인형이 현재 인형과 같은지 확인
                if(!picked.empty() && picked.back() == current_doll) 
                {
                    answer += 2;      // 인형 2개가 사라짐
                    picked.pop_back(); // 바구니에서 기존 인형 제거
                }
                else
                {
                    picked.push_back(current_doll); // 바구니에 새 인형 추가
                }
                
                // 인형을 하나 뽑았으므로 해당 열의 탐색을 종료하고 다음 move로 이동
                break; 
            }
        }
    }
    
    return answer;
}