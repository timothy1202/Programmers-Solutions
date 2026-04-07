#include <string>
#include <vector>
using namespace std;

bool solution(int x) 
{
    int sum = 0;
    int origin = x;  // 원본 값 저장

    while(x > 0)
    {
        sum += x % 10;  // 간결하게 통합
        x = x / 10;
    }
    
    if(origin % sum == 0) return true;  // return 추가
    else return false;
}