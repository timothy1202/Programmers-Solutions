#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    vector<int> num3;

    while (n > 0) 
    {
        num3.push_back(n % 3);
        n /= 3;
    }

    for (int i = 0; i < num3.size(); i++) 
    {
        int power = num3.size() - 1 - i;
        answer += num3[i] * (int)pow(3, power);
    }

    return answer;
}