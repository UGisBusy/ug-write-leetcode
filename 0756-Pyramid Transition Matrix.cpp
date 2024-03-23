#include <bits/stdc++.h>
using namespace std;

/*
dfs + moemization
這209ms, 一堆解20ms, 不知道是不是dp
*/

class Solution {
    public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> m;
        for (auto a : allowed) {
            m[a.substr(0, 2)].push_back(a[2]);
        }
        bool r = sol(bottom, m, 0, "");
        for (auto& s : seen) {
            cout << s << " ";
        }
        return r;
    }

    unordered_set<string> seen;
    bool sol(string bottom, unordered_map<string, vector<char>>& m, int i, string top) {
        if (bottom.size() == 1) {
            return true;
        }
        if (seen.count(bottom)) {
            return false;
        }
        if (i == bottom.size() - 1) {
            if (sol(top, m, 0, "")) {
                return true;
            }
            seen.insert(top);
            return false;
        }
        for (auto c : m[bottom.substr(i, 2)]) {
            if (sol(bottom, m, i + 1, top + c)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    string bottom = "DBCDA";
    vector<string> allowed = {"DBD", "BCC", "CDD", "DAD", "DDA", "AAC", "CCA", "BCD"};
    cout << s.pyramidTransition(bottom, allowed) << endl;
    return 0;
}