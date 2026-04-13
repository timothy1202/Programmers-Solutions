#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

// 단어 정보를 저장할 구조체
struct WordInfo {
    string text;
    int start;
    int end;
};

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    vector<WordInfo> all_words;
    
    // 1. 모든 단어와 그 위치를 추출
    string word;
    int current_pos = 0;
    stringstream ss(message);
    while (ss >> word) {
        int word_start = message.find(word, current_pos);
        int word_end = word_start + word.length() - 1;
        all_words.push_back({word, word_start, word_end});
        current_pos = word_end + 1; // 다음 검색 위치 갱신
    }

    // 2. 각 단어가 스포일러 구간에 포함되는지 확인
    // 그리고 스포일러가 아닌 구간에서 등장하는 단어들을 미리 파악
    unordered_set<string> non_spoiler_words;
    vector<bool> is_spoiler_word(all_words.size(), false);

    for (int i = 0; i < all_words.size(); ++i) {
        bool covered = false;
        for (const auto& range : spoiler_ranges) {
            // 단어의 일부라도 구간 [range[0], range[1]]에 포함되는지 검사
            if (!(all_words[i].end < range[0] || all_words[i].start > range[1])) {
                covered = true;
                break;
            }
        }
        
        if (covered) {
            is_spoiler_word[i] = true;
        } else {
            // 스포일러 구간에 전혀 걸치지 않은 단어들 저장
            non_spoiler_words.insert(all_words[i].text);
        }
    }

    // 3. 순서대로 탐색하며 중요 단어 판단
    unordered_set<string> counted_important_words;
    for (int i = 0; i < all_words.size(); ++i) {
        if (is_spoiler_word[i]) {
            string current_text = all_words[i].text;
            
            // 조건 1: 스포 방지 단어여야 함 (이미 if문으로 걸러짐)
            // 조건 2: 비-스포일러 구간에 등장한 적이 없어야 함
            // 조건 3: 이전에 공개된 중요 단어와 중복되지 않아야 함
            if (non_spoiler_words.find(current_text) == non_spoiler_words.end() &&
                counted_important_words.find(current_text) == counted_important_words.end()) {
                
                answer++;
                counted_important_words.insert(current_text);
            }
        }
    }

    return answer;
}