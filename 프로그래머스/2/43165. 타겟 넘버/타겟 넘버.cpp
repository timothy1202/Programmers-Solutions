#include <string>
#include <vector>

using namespace std;

int answer =0;

void dfs(vector<int>& numbers,int target,int index,int currentSum)
{
    if(index==numbers.size())
    {
        if(currentSum == target) answer++;
        return;
    }
    
    dfs(numbers,target,index+1,currentSum+numbers[index]);
    dfs(numbers,target,index+1,currentSum-numbers[index]);
}

int solution(vector<int> numbers, int target) 
{    
    dfs(numbers,target,0,0);
    
    return answer;
}