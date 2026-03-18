#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) 
{
    string answer = "";
    
    vector<bool> skipped(26, false);
    for (char c : skip) 
    {
        skipped[c - 'a'] = true;
    }

    for (char c : s) 
    {
        char current = c;
        int count = 0;

        while (count < index) 
        {
            current++; 
            
            if (current > 'z') 
            {
                current = 'a';
            }

            // 만약 현재 문자가 skip에 포함되지 않는다면 이동 횟수 증가
            if (!skipped[current - 'a']) 
            {
                count++;
            }
        }
        answer += current;
    }

    return answer;
}