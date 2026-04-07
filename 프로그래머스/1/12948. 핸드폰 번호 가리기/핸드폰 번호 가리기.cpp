#include <string>
#include <vector>
using namespace std;

string solution(string phone_number) 
{
    string answer = "";
    int len = phone_number.length() - 4;
    string a = phone_number.substr(phone_number.length() - 4, 4);

    for(int i = 0; i < len; i++) 
    {
        answer += "*";
    }
    answer += a;
    
    return answer;
}