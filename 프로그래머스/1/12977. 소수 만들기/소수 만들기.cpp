#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) 
{
    int answer = 0;
    vector<int> a;

    for (int i = 0; i < nums.size(); i++) 
    {
        for (int j = i+1; j < nums.size(); j++)
        {
            for (int k = j+1; k < nums.size(); k++) 
            {
                a.push_back(nums[i] + nums[j] + nums[k]); // num -> nums
            }
        }
    }
    
    for (const int& n : a)
    {
        if (n < 2) continue;
        bool isPrime = true;
        for (int i = 2; i*i <= n; i++) 
        {
            if (n % i == 0)
            {
                isPrime = false; // 소수 아님 표시
                break;
            }
        }
        if (isPrime) answer++; // 소수일 때만 카운트
    }

    return answer;
}