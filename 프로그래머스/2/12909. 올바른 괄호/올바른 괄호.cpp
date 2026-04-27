#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int open=0;
    int close=0;
    
    for(int i=0;i<s.size();i++) 
    {
        if(s[i] == '(') open++;
        else if(s[i]==')')
        {
            if(open>0) open--;
            else return false;
        }
        
    }
      if(open!=0) return false;
    return answer;
}