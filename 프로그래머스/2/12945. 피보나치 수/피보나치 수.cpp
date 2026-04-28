#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    vector<int> f;
    f.push_back(0);
    f.push_back(1);
    for(int i=2;i<=n;i++) 
    {
       f.push_back((f[i-2] + f[i-1]) % 1234567);  
    }
    answer = f[n];
    return answer;
}