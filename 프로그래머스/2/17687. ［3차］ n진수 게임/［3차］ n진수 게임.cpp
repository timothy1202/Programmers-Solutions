#include <string>
using namespace std;

string solution(int n, int t, int m, int p) 
{
    string all = "";
    string answer = "";
    int num = 0;

    // 필요한 길이만큼 진법 변환 문자열 생성
    while ((int)all.size() < m * t) 
    {
        string converted = "";
        int temp = num;
        if (temp == 0) 
        {
            converted = "0";
        } 
        else 
        {
            while (temp > 0) 
            {
                int digit = temp % n;
                // 10 이상이면 A, B, C... (16진수 대응)
                converted = (char)(digit < 10 ? '0' + digit : 'A' + digit - 10)
                            + converted;
                temp /= n;
            }
        }
        all += converted;
        num++;
    }

    // p번째(1-indexed)부터 m 간격으로 t개 추출
    for (int i = p - 1; i < (int)all.size() && (int)answer.size() < t; i += m)
        answer += all[i];

    return answer;
}