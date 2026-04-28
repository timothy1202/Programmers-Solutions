#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int one_num=0;
    int a=n;
    while(a>0)
    {
        if(a%2==1)one_num++;
        a/=2;
    }
    for(int i=n+1;i<1000000;i++)
    {
        int num=i;
        int one=0;
        while(num>0)
        {
            if(num%2==1)one++;
            num/=2;
        }
        if(one==one_num) return i;
    }
    
}