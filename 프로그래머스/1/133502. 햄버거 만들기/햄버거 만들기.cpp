#include <vector>

using namespace std;

int solution(vector<int> ingredient) 
{
    int answer = 0;
    vector<int> s; // 스택 역할을 할 벡터

    for (int x : ingredient) 
    {
        s.push_back(x); // 일단 재료를 하나 넣는다.

        // 재료가 4개 이상 쌓였을 때만 패턴 체크
        if (s.size() >= 4) 
        {
            int n = s.size();
            
            // 마지막 4개의 재료가 1(빵) - 2(야채) - 3(고기) - 1(빵) 인지 확인
            if (s[n - 4] == 1 && s[n - 3] == 2 && 
                s[n - 2] == 3 && s[n - 1] == 1) 
            {
                
                answer++; // 햄버거 완성!
                
                // 완성된 재료 4개를 뒤에서부터 제거 (pop_back 4번)
                for (int i = 0; i < 4; i++) 
                {
                    s.pop_back();
                }
            }
        }
    }

    return answer;
}