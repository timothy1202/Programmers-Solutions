#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    // 1. 누가 누구를 신고했는지 기록 (중복 신고 방지를 위해 unordered_set 사용)
    unordered_map<string, unordered_set<string>> report_map;
    // 2. 각 유저가 신고당한 횟수
    unordered_map<string, int> reported_count;

    // report 배열 처리
    for (const string& r : report) 
    {
        stringstream ss(r);
        string reporter, reported;
        ss >> reporter >> reported;

        // 이미 신고한 적 있는지 확인 (없을 때만 카운트 증가)
        if (report_map[reporter].find(reported) == report_map[reporter].end()) 
        {
            report_map[reporter].insert(reported);
            reported_count[reported]++;
        }
    }

    // 3. 결과 계산
    vector<int> answer;
    for (const string& id : id_list) 
    {
        int mail_count = 0;
        // 내가 신고한 사람들을 확인
        for (const string& reported : report_map[id]) 
        {
            // 그 사람이 k번 이상 신고당했는지 확인
            if (reported_count[reported] >= k) 
            {
                mail_count++;
            }
        }
        answer.push_back(mail_count);
    }

    return answer;
}