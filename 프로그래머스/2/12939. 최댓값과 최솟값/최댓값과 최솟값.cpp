#include <string>
#include <vector>
#include <sstream>
#include <climits>
using namespace std;

string solution(string s) 
{
    string answer = "";
    stringstream ss(s); 
    int max = INT_MIN;  
    int min = INT_MAX;
    
    int num;
    while(ss >> num)    
    {
        if(num > max) max = num;
        if(num < min) min = num;
    }
    
    answer = to_string(min) + " " + to_string(max);
    
    return answer;
}