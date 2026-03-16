#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) 
{
    // 1. 이름과 그리움 점수를 map에 저장
    unordered_map<string, int> miss;
    for (int i = 0; i < name.size(); i++) 
    {
        miss[name[i]] = yearning[i];
    }
    
    vector<int> answer;
    
    // 2. 각 사진(photo)을 순회
    for (int i = 0; i < photo.size(); i++) 
    {
        int miss_num = 0;
        
        // 각 사진 속 인물들을 순회
        for (int j = 0; j < photo[i].size(); j++) 
        {
            string person = photo[i][j];
            
            // map에서 해당 인물의 점수를 찾음
            auto it = miss.find(person);
            if (it != miss.end()) 
            {
                miss_num += it->second; // 점수가 있다면 더함
            }
        }
        answer.push_back(miss_num);
    }
    
    return answer;
}