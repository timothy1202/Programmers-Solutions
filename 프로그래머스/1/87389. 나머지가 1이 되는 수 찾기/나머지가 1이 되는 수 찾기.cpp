#include <string>
#include <vector>
//#include <cmath> // sqrt 함수를 사용하기 위해 필요

using namespace std;

int solution(int n) 
{
    int target = n - 1; 
    

    for (int i = 2; i * i <= target; i++) 
    {
        if (target % i == 0) 
        {
            return i; 
        }
    }
    
    return target;
}