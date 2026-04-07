#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int m) 
{
    vector<int> answer;
    int num = min(n, m);
    int a = 0;  // 최대공약수 (GCD)

    for(int i = 1; i <= num; i++) 
    {
        if(n % i == 0 && m % i == 0)  // ✅ 1 → i 로 수정
        {
            a = i;
        }
    }

    int b = n * m / a;  // ✅ 최소공배수 = n*m / GCD

    answer.push_back(a);
    answer.push_back(b);
    return answer;
}