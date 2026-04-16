#include <string>
#include <vector>

using namespace std;

bool solution(string s) 
{
    if(s.size()!=4 &&s.size()!=6) return false;
    for(const char& a : s)
    {
        if(a<'0'||a>'9') return false;
    }
    
    return true;
}