#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    string num;
    string word;
    
    for(int i=0;i<s.size();i++)
    {
        
        if('0'<=s[i] && s[i] <= '9')
        {
            num +=s[i];
        }
        else
        {
            word +=s[i];
        }
        
        if(word == "zero")
        {
            num +='0';
            word = "";
        }
        else if (word =="one")
        {
            num +='1';
            word = "";
        }
        else if (word =="two")
        {
            num +='2';
            word = "";
        }
        else if (word =="three")
        {
            num +='3';
            word = "";
        }
        else if (word =="four")
        {
            num +='4';
            word = "";
        }
        else if (word =="five")
        {
            num +='5';
            word = "";
        }
        else if (word =="six")
        {
            num +='6';
            word = "";
        }
        else if (word =="seven")
        {
            num +='7';
            word = "";
        }
        else if (word =="eight")
        {
            num +='8';
            word = "";
        }
        else if (word =="nine")
        {
            num +='9';
            word = "";
        }
        
    }
    
    int answer = stoi(num);
    return answer;
}