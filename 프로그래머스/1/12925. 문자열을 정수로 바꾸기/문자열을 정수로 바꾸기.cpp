#include <string>

using namespace std;

int solution(string s) 
{
    int answer = 0;
    int sign = 1;
    int startIndex = 0;

    
    if (s[0] == '-') 
    {
        sign = -1;
        startIndex = 1;
    } 
    else if (s[0] == '+') 
    {
        sign = 1;
        startIndex = 1;
    }

    for (int i = startIndex; i < s.size(); i++) 
    {
        answer *= 10;
        answer += (s[i] - '0');
    }

    return answer * sign;
}