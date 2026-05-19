#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) 
{
    int answer = 0;
    stack<int> sub;
    int n = order.size();
    int order_idx = 0;
    
    for(int i = 1; i <= n && order_idx < n; i++) 
    {
        sub.push(i);
        
        while(!sub.empty() && order_idx < n 
              && sub.top() == order[order_idx]) 
        {
            sub.pop();
            order_idx++;
            answer++;
        }
    }
    
    return answer;
}