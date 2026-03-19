#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    stringstream ss(today);
    string ty, tm, td;
    getline(ss, ty, '.');
    getline(ss, tm, '.');
    getline(ss, td, '.');
    int t_year = stoi(ty);
    int t_month = stoi(tm);
    int t_day = stoi(td);
    
    int today_total_days = (t_year * 12 * 28) + (t_month * 28) + t_day;

    unordered_map<char, int> term_map;
    for (string s : terms) 
    {
        stringstream t_ss(s);
        char type;
        int month;
        t_ss >> type >> month;
        term_map[type] = month;
    }

    vector<int> answer;
    for (int i = 0; i < privacies.size(); i++) 
    {
        stringstream p_ss(privacies[i]);
        string py, pm, pd;
        char p_term;
        
        getline(p_ss, py, '.');
        getline(p_ss, pm, '.');
        getline(p_ss, pd, ' '); 
        p_ss >> p_term;

        int year = stoi(py);
        int month = stoi(pm);
        int day = stoi(pd);

        int expiry_days = (year * 12 * 28) + ((month + term_map[p_term]) * 28) + day;
        
        if (expiry_days <= today_total_days) 
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}