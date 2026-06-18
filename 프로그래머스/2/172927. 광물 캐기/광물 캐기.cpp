#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 하나의 묶음(최대 광물 5개)의 정보를 담을 구조체
struct MineralGroup {
    int dia = 0;
    int iron = 0;
    int stone = 0;
    int total_stone_fatigue = 0; // 돌 곡괭이로 캤을 때의 총 피로도 (정렬 기준)
};

// 돌 곡괭이 기준 피로도가 높은 순으로 정렬
bool compare(const MineralGroup& a, const MineralGroup& b) {
    return a.total_stone_fatigue > b.total_stone_fatigue;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    int total_picks = picks[0] + picks[1] + picks[2];
    // 가질 수 있는 최대 묶음 수는 곡괭이 총 개수와 광물 묶음 수 중 작은 값
    int max_groups = min(total_picks, (int)ceil((double)minerals.size() / 5.0));
    
    vector<MineralGroup> groups(max_groups);
    
    // 1. 광물을 5개씩 묶어서 피로도 계산
    for (int i = 0; i < max_groups * 5 && i < minerals.size(); i++) {
        int group_idx = i / 5;
        
        if (minerals[i] == "diamond") {
            groups[group_idx].dia++;
            groups[group_idx].total_stone_fatigue += 25;
        } else if (minerals[i] == "iron") {
            groups[group_idx].iron++;
            groups[group_idx].total_stone_fatigue += 5;
        } else if (minerals[i] == "stone") {
            groups[group_idx].stone++;
            groups[group_idx].total_stone_fatigue += 1;
        }
    }
    
    // 2. 피로도가 높은 순서대로 묶음 정렬
    sort(groups.begin(), groups.end(), compare);
    
    // 3. 좋은 곡괭이부터 차례대로 배정하여 피로도 계산
    int pick_idx = 0; // 0: 다이아, 1: 철, 2: 돌
    for (const auto& group : groups) {
        // 남은 곡괭이 찾기
        while (pick_idx < 3 && picks[pick_idx] == 0) {
            pick_idx++;
        }
        
        if (pick_idx >= 3) break; // 곡괭이를 다 쓴 경우
        
        // 다이아몬드 곡괭이
        if (pick_idx == 0) {
            answer += group.dia + group.iron + group.stone;
        }
        // 철 곡괭이
        else if (pick_idx == 1) {
            answer += (group.dia * 5) + group.iron + group.stone;
        }
        // 돌 곡괭이
        else if (pick_idx == 2) {
            answer += group.total_stone_fatigue;
        }
        
        picks[pick_idx]--; // 사용한 곡괭이 개수 차감
    }
    
    return answer;
}