#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(int a, int b, int n) 
{
    int answer = 0;
    int current_bottles = n; 

    while(current_bottles >= a)
    {
        int give = current_bottles / a;     
        int after_give = current_bottles % a; 
        
        int get = give * b;      
        answer += get;           
        
        current_bottles = get + after_give;
    }
    
    return answer;
}