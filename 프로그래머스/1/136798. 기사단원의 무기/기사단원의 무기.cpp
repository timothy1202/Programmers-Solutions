#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) 
{
    int answer = 0;

    for (int i = 1; i <= number; i++) 
    {
        int count = 0;
        
        for (int j = 1; j * j <= i; j++) 
        {
            if (i % j == 0) 
            {
                if (j * j == i) 
                {
                    count++; // 제곱근인 경우 (예: 4의 약수 중 2) 하나만 추가
                } 
                else 
                {
                    count += 2; // 그 외에는 j와 i/j 두 개를 추가
                }
            }
        }

        if (count > limit)
        {
            answer += power;
        } 
        else 
        {
            answer += count;
        }
    }

    return answer;
}