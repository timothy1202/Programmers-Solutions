#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) 
{
    int answer = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) 
    {
        stack<char> st;
        bool ok = true;

        for (int j = i; j < n + i; j++) 
        {
            char c = s[j % n];

            if (c == '(' || c == '{' || c == '[') 
            {
                st.push(c);
            } 
            else 
            {
                if (st.empty()) 
                { 
                    ok = false; 
                    break; 
                }

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) 
                {
                    ok = false;
                    break;
                }
            }
        }

        if (ok && st.empty()) answer++;
    }

    return answer;
}