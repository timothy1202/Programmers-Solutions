#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) 
{
    string answer = "";
    for(int i = 0; i < s.size(); i++) 
    {
        if(s[i] == ' ') 
        {
            answer += " ";
            continue;
        }

        if (s[i] >= 'A' && s[i] <= 'Z') 
        {
            int a = s[i] + n;
            if (a > 'Z') a -= 26; 
            answer += (char)a;
        } 
        else if (s[i] >= 'a' && s[i] <= 'z') 
        {
            int a = s[i] + n;
            if (a > 'z') a -= 26; 
            answer += (char)a;
        }
    }
    
    return answer;
}