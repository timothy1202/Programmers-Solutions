#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) 
{
    int answer = 0;
    map<int, int> g;

    for (int i = 0; i < tangerine.size(); i++) 
    {
        g[tangerine[i]]++;
    }

    vector<int> counts;
    for (auto& p : g) 
    {
        counts.push_back(p.second);
    }

    sort(counts.begin(), counts.end(), greater<int>());

    int num = 0;
    for (int cnt : counts) 
    {
        num += cnt;
        answer++;
        if (num >= k) break;
    }

    return answer;
}