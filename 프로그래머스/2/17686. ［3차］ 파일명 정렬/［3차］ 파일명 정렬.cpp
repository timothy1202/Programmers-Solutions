#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

struct FileInfo {
    string head;
    int number;
    string original;
};

FileInfo parse(const string& file) {
    int i = 0, n = file.size();
    
    // HEAD: 숫자 나오기 전까지
    string head = "";
    while (i < n && !isdigit(file[i])) {
        head += tolower(file[i]);
        i++;
    }
    
    // NUMBER: 연속된 숫자
    string num_str = "";
    while (i < n && isdigit(file[i]) && num_str.size() < 5) {
        num_str += file[i];
        i++;
    }
    
    return { head, stoi(num_str), file };
}

vector<string> solution(vector<string> files) {
    vector<FileInfo> parsed;
    for (auto& f : files)
        parsed.push_back(parse(f));
    
    stable_sort(parsed.begin(), parsed.end(), [](const FileInfo& a, const FileInfo& b) {
        if (a.head != b.head) return a.head < b.head;
        return a.number < b.number;
    });
    
    vector<string> answer;
    for (auto& p : parsed)
        answer.push_back(p.original);
    
    return answer;
}