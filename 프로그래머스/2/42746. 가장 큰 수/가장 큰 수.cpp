#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) 
{
    string sa = to_string(a), sb = to_string(b);
    return sa + sb > sb + sa;
}

string solution(vector<int> numbers) 
{
    sort(numbers.begin(), numbers.end(), compare);
    
    string answer = "";
    for (int n : numbers)
        answer += to_string(n);
    
    // 모두 0인 경우: "000..." → "0"
    if (answer[0] == '0') return "0";
    
    return answer;
}