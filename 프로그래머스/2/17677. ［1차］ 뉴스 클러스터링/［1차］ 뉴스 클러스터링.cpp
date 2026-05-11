#include <string>
#include <unordered_map>
#include <cctype>
#include <set>
using namespace std;

int solution(string str1, string str2) 
{
    for (char& c : str1) c = tolower(c);
    for (char& c : str2) c = tolower(c);

    unordered_map<string, int> p1, p2;

    for (int i = 0; i < (int)str1.size() - 1; i++) 
    {
        if (!isalpha(str1[i]) || !isalpha(str1[i+1])) continue;
        p1[string(1, str1[i]) + str1[i+1]]++;
    }

    for (int i = 0; i < (int)str2.size() - 1; i++) 
    {
        if (!isalpha(str2[i]) || !isalpha(str2[i+1])) continue;
        p2[string(1, str2[i]) + str2[i+1]]++;
    }

    double same = 0, all = 0;
    set<string> visited;

    for (auto& [word, count] : p1) 
    {
        visited.insert(word);
        if (p2.count(word)) 
        {
            same += min(p1[word], p2[word]);   // 교집합: 작은 값
            all  += max(p1[word], p2[word]);   // 합집합: 큰 값
        } 
        else 
        {
            all += count;                       // p1에만 있는 경우
        }
    }

    for (auto& [word, count] : p2) 
    {
        if (!visited.count(word)) 
        {
            all += count;                       // p2에만 있는 경우
        }
    }

    if (all == 0) return 65536;                 // 둘 다 공집합이면 유사도 1

    return (int)(same / all * 65536);
}