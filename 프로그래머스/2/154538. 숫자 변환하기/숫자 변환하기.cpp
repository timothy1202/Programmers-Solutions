#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int solution(int x, int y, int n) 
{
    if(x == y) return 0;
    
    queue<int> q;
    unordered_set<int> visited;
    q.push(x);
    visited.insert(x);
    int steps = 0;
    
    while(!q.empty()) 
    {
        steps++;
        int size = q.size();
        
        for(int i = 0; i < size; i++) 
        {
            int cur = q.front(); q.pop();
            
            for(int next : {cur + n, cur * 2, cur * 3}) 
            {
                if(next == y) return steps;
                if(next < y && !visited.count(next)) 
                {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
    }
    return -1;
}