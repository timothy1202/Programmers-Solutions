#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) 
{
    int answer = 0;
    int num=0;
    int max =0;
    for(int i=0;i<citations.size();i++) 
    {
        if(citations[i]>max) max=citations[i];
    }
    
    while(num<=max)
    {
        bool good = true;
        num++;
        int up = 0;
        int down = 0;
        for(int i=0;i<citations.size();i++) 
        {
            if(citations[i]>=num) up++;
            else if(citations[i]<=num) good = true;
            else 
            {
                good = false;
                break;
            }
        }
        if(up>=num && good==true) answer = num;
    }
    
    return answer;
}