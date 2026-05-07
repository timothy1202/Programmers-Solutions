#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) 
{
    int answer = 0;
    queue<int> q;
    for(int i = 0; i < priorities.size(); i++) 
        q.push(i);

    while(!q.empty())
    {
        int max = 0;
        for(int i = 0; i < priorities.size(); i++)
            if(priorities[i] > max) max = priorities[i];
        
        if(priorities[q.front()] < max)
        {
            int num = q.front();
            q.pop();
            q.push(num);
        }
        else
        {
            answer++;
            if(q.front() == location) break;
            
            priorities[q.front()] = 0;
            q.pop();
        }
    }
    
    return answer;
}