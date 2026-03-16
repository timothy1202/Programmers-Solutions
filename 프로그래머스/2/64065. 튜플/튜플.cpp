#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) 
{
    vector<vector<int>> num;
    string cur_num = "";
    vector<int> temp_vec;
    
    // 1. 문자열 파싱
    for (int i = 0; i < s.size(); i++) 
    {
        if (isdigit(s[i])) 
        {
            cur_num += s[i];
        } 
        else 
        {
            if (!cur_num.empty()) 
            {
                temp_vec.push_back(stoi(cur_num));
                cur_num = "";
            }
            if (s[i] == '}' && !temp_vec.empty()) 
            {
                num.push_back(temp_vec);
                temp_vec.clear();
            }
        }
    }
    
    // 2. 길이 순 정렬
    sort(num.begin(), num.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size();
    });
    
    // 3. 튜플 순서대로 복원
    vector<int> answer;
    unordered_map<int, bool> visited; // 사용된 숫자 체크
    
    for (const auto& vec : num) 
    {
        for (int n : vec) 
        {
            if (visited.find(n) == visited.end()) 
            {
                answer.push_back(n);
                visited[n] = true;
            }
        }
    }
    
    return answer;
}