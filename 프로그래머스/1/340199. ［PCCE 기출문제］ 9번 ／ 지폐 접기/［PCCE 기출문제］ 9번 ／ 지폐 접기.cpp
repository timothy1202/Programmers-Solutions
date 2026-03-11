#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) 
{
    int w_long = 0;
    int w_short = 0;
    if(wallet[0]>wallet[1])
    {
        w_long =wallet[0];
        w_short = wallet[1];
    }
    else
    {
        w_long=wallet[1];
        w_short = wallet[0];
    }
    
    int b_long =0;
    int b_short = 0;
    
    if(bill[0]>bill[1])
    {
        b_long = bill[0];
        b_short = bill[1];
    }
    else
    {
         b_long = bill[1];
        b_short = bill[0];
    }
    
    int answer = 0;
    while(1)
    {
        if((b_long<=w_long && b_short<=w_short) || (b_short<=w_long && b_long<=w_short))
            return answer;
        
        if(b_long>b_short)
        {
            b_long /=2;
        }
        else b_short /=2;
        answer++;
    }
    
    
    
    return answer;
}