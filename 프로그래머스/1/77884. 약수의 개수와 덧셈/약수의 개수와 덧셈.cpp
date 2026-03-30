#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) 
{
    int answer = 0;
    for(int i=left;i<=right;i++)
    {
        int num=0;
        for(int j=1;j*j<=i;j++)
        {
            if(i%j==0 && j*j==i) num ++;
            else if(i%j==0)
            {
                num +=2;
            }
        }
        
        if(num%2==0)
        {
            answer += i;
        }
        else
        {
            answer -= i;
        }
    }
        
    return answer;
}