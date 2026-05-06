#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    int n = progresses.size();
    vector<bool> done(n,false);
    
    while(done[n-1]==false)
    {
        int num = 0;
        for(int i=0;i<n;i++) 
        {   
            progresses[i] += speeds[i];
        }
        for(int i=0;i<n;i++) 
        {
            if(done[i]==true) continue;
            else //false 일때
            {
                if(progresses[i]>=100) 
                {
                    done[i]=true;
                    num++;
                }
                else break;
            }
        }
        if(num>0)
        answer.push_back(num);
    }
    
    
    return answer;
}