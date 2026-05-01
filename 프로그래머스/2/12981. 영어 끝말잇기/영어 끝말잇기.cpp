#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    vector<int> answer;
    unordered_set<string> said;
    char b_word = '0';
    
    for(int i=0;i<words.size();i++) 
    {
        if(b_word!='0' && b_word!=words[i].front())
        {
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            break;
        }
        if(said.count(words[i]) == 1)
        {
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            break;
        }
        said.insert(words[i]);
        
        b_word = words[i].back();
    }
    
    if(answer.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    

    return answer;
}