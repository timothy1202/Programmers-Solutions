#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) 
{
    unordered_map<string, int> c;
    

    for (int i = 0; i < clothes.size(); i++) 
        c[clothes[i][1]]++;
    
    int answer = 1;
    for (const auto& [key, value] : c)
        answer *= (value + 1);
    
    return answer - 1;  
}