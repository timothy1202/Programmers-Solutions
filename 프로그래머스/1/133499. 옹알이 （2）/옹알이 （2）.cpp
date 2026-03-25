#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) 
{
    int answer = 0;
    
    for(int i=0;i<babbling.size();i++)
    {
        // 1= aya 2=ye 3=woo 4=ma
        int num = 0;
        string word = "";
        for(int j=0; j<babbling[i].size();j++) 
        {
            word += babbling[i][j];
            if(word == "aya") 
            {
                if(num==1) break;
                word = "";
                num=1;
            }
            else if(word =="ye")
            {
                if(num==2) break;
                word = "";
                num=2;
            }
            else if(word =="woo")
            {
                if(num==3) break;
                word = "";
                num=3;
            }
            else if(word =="ma")
            {
                if(num==4) break;
                word = "";
                num =4;
            }
        }
        if( word =="")
        {
            answer++;
        }
    }
    
    return answer;
}