#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) 
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int answer = 0;
set<int> visited;

void dfs(string current, string remaining) 
{
    if (!current.empty()) 
    {
        int num = stoi(current);
        if (visited.find(num) == visited.end()) 
        {
            visited.insert(num);
            if (isPrime(num)) answer++;
        }
    }
    for (int i = 0; i < remaining.size(); i++) 
    {
        dfs(current + remaining[i],
            remaining.substr(0, i) + remaining.substr(i + 1));
    }
}

int solution(string numbers) 
{
    dfs("", numbers);
    return answer;
}