#include <string>
#include <cctype>

using namespace std;

string solution(string s) 
{
    bool isFirst = true;

    for (int i = 0; i < s.length(); i++) 
    {
        if (s[i] == ' ') 
        {
            // 공백을 만나면 다음 글자는 단어의 시작이 됨
            isFirst = true;
        } else 
        {
            if (isFirst) 
            {
                s[i] = toupper(s[i]);
                isFirst = false; 
            } else 
            {
                s[i] = tolower(s[i]);
            }
        }
    }
    return s;
}