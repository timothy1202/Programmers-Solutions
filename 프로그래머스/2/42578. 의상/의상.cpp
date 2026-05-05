#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) 
{
    unordered_map<string, int> c;
    
    // 카테고리별 의상 수 카운트
    for (int i = 0; i < clothes.size(); i++) 
        c[clothes[i][1]]++;
    
    // (각 카테고리 수 + 1) 모두 곱하기
    int answer = 1;
    for (const auto& [key, value] : c)
        answer *= (value + 1);
    
    return answer - 1;  // 아무것도 안 입는 경우 제거
}