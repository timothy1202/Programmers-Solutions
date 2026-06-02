#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) 
{
    vector<string> answer;
    unordered_map<string, string> nickMap; // uid -> 닉네임
    
    // 1패스: uid별 최종 닉네임 저장
    for (int i = 0; i < record.size(); i++) 
    {
        vector<string> words;
        string w;
        
        for (int j = 0; j < record[i].size(); j++) 
        {
            if (record[i][j] == ' ') 
            { 
                words.push_back(w);
                w = "";
            } 
            else 
            {
                w += record[i][j];
            }
        }
        words.push_back(w);
        
        if (words[0] == "Enter" || words[0] == "Change") 
        {
            nickMap[words[1]] = words[2]; // uid -> 닉네임 갱신
        }
    }
    
    // 2패스: 메시지 생성
    for (int i = 0; i < record.size(); i++) 
    {
        vector<string> words;
        string w;
        
        for (int j = 0; j < record[i].size(); j++) 
        {
            if (record[i][j] == ' ') 
            {
                words.push_back(w);
                w = "";
            } 
            else 
            {
                w += record[i][j];
            }
        }
        words.push_back(w);
        
        string uid = words[1];
        if (words[0] == "Enter") 
        {
            answer.push_back(nickMap[uid] + "님이 들어왔습니다.");
        } 
        else if (words[0] == "Leave") 
        {
            answer.push_back(nickMap[uid] + "님이 나갔습니다.");
        }
        // Change는 출력 없음
    }
    
    return answer;
}