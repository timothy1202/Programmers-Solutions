#include <cmath>
using namespace std;

long long solution(long long n) 
{
    long long a = (long long)sqrt((double)n);
    
    if(a * a == n)          // n이 정수의 제곱인지 확인
        return (a+1) * (a+1);
    else
        return -1;
}