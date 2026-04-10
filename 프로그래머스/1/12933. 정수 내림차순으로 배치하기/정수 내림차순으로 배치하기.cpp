#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    // 1. 숫자를 문자열로 변환
    string s = to_string(n);
    
    // 2. 문자열 자체를 내림차순 정렬 ('9' -> '0' 순서)
    sort(s.begin(), s.end(), greater<char>());
    
    // 3. 문자열을 다시 long long 타입으로 변환
    return stoll(s);
}