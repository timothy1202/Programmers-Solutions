#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) 
{
    vector<int> answer;
    unordered_map<string, int> num; 

    char w = 'A';
    for(int i = 0; i < 26; i++)
    {
        num[string(1, w)] = i + 1;
        w++;
    }

    int max_num = 27;
    string word;

    for(int i = 0; i < msg.size(); i++) 
    {       
        word += msg[i];
        
        if(num.count(word) == 0)
        {
            num[word] = max_num++;      
            word.pop_back();            
            answer.push_back(num[word]);
            word = string(1, msg[i]);  
        }
    }
    
    answer.push_back(num[word]); 

    return answer;
}