#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) 
{
    unordered_map<char,int> alphabet;
    vector<int> answer;
    answer.push_back(-1);
    
    for(int i=0; i<s.size();i++)
    {
        if( i==0)
        alphabet[s[i]] = i;
        else
        {
            if(alphabet.find(s[i]) == alphabet.end())
            {
                answer.push_back(-1);
                alphabet[s[i]] = i;
            }
            else
            {
                answer.push_back(i-alphabet[s[i]]);
                alphabet[s[i]] = i;
            }
        }
    }
    
    return answer;
}