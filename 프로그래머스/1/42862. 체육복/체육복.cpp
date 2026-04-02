#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    map<int, int> s;
    
    for(int i = 1; i <= n; i++) 
    {
        s[i] = 1; 
    }
    
    for(int l : lost) s[l]--;
    
    for(int r : reserve) s[r]++;
    
    for(int i = 1; i <= n; i++) 
    {
        if(s[i] == 0) 
        {
            if(i - 1 >= 1 && s[i - 1] == 2) 
            {
                s[i] = 1;
                s[i - 1] = 1;
            }
            else if(i + 1 <= n && s[i + 1] == 2) 
            {
                s[i] = 1;
                s[i + 1] = 1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) 
    {
        if(s[i] >= 1) answer++;
    }
    
    return answer;
}