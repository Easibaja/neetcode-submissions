class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> sChar;
        std::unordered_map<char, int> tChar;

        if (s.size() != t.size()) {
            return false;
        } else {
            for (int i = 0; i < s.size(); ++i) {
                sChar[s[i]] += 1;
                tChar[t[i]] += 1;
            }
            for (auto letter : s) {
                if (sChar[letter] == tChar[letter]) {
                    continue;
                } else {
                    return false;
                }
            }
            return true;
        }
    }
};
