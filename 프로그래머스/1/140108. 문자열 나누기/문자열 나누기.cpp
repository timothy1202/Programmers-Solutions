#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int count_f = 0;
    int count_s = 0;
    char alphabet = '0';
    int answer = 0;
    
    for(const char& sa: s)
    {
        if(alphabet == '0')
        {
            alphabet = sa;
            count_f++;
        }
        
        else if(alphabet != sa)
        {
            count_s++;
            if(count_s == count_f)
            {
                count_s=0;
                count_f=0;
                alphabet ='0';
                answer++;
            }
        }
        else if(alphabet == sa)
        {
            count_f++;
        }
            
    }
    if(alphabet !='0') answer++;
    
    return answer;
}