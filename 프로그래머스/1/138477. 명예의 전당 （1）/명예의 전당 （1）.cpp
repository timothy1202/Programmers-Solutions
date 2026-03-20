#include <vector>
#include <queue>   // priority_queue를 쓰기 위해 필요
#include <functional> // greater를 쓰기 위해 필요

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    // 최소 힙: 가장 작은 값이 항상 TOP에 오도록 설정
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int s : score) {
        pq.push(s);

        // 명예의 전당 정원이 초과되면 가장 낮은 점수를 제거
        if (pq.size() > k) {
            pq.pop();
        }

        // 현재 명예의 전당(큐)에서 가장 낮은 점수는 항상 top()에 있음
        answer.push_back(pq.top());
    }

    return answer;
}