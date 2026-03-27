#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) 
{
    vector<bool> check (10,0);
    for(const int& num : numbers)
    {
        check[num] = true;
    }
    int sum = 0;
    for(int i=0;i<10;i++)
    {
        if(check[i]==0) sum +=i;
    }
    
    return sum;
}