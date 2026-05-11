#include <string>
#include <vector>
using namespace std;

vector<string> words;
string vowels = "AEIOU";

void dfs(string cur) 
{
    if (cur.size() > 5) return;
    
    words.push_back(cur); 
    
    for (char c : vowels) 
    {
        dfs(cur + c);    
    }
}

int solution(string word) 
{
    for (char c : vowels) 
    {
        dfs(string(1, c));         // A, E, I, O, U로 시작하는 모든 단어 생성
    }
    
    for (int i = 0; i < (int)words.size(); i++) 
    {
        if (words[i] == word) return i + 1;
    }
    return -1;
}