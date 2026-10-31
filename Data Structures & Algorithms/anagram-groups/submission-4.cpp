class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};

        vector<vector<string>> result;
        std::map<std::array<int, 26>, int> groups;
        int totalGroups = 0;
        int groupIndex = -1;

        for (int i = 0; i < strs.size(); ++i){
            std::array<int, 26> representation{};
            for (char letter : strs[i]){
                representation[letter - 'a'] +=1;
            }
            if (groups.contains(representation)) {
                groupIndex = groups[representation];
            } else {
                groups[representation] = totalGroups++;
                groupIndex = groups[representation];
                result.push_back({});
            }
            
            result[groupIndex].push_back(strs[i]);
        }
        return result;
    }
};



/**
        // std::vector<std::array<int, 26>> charOccurrence(strs.size());
        
        // for (auto word = 0; word < strs.size(); ++ word) {
        //     for (char letter : strs[word]) {
        //         ++charOccurrence[word][letter - 'a'];
        //     }
        // }


   int totalAnagrams = 1;
        vector<int> representatives;
        representatives.push_back(0);

        for (int i = 1; i < strs.size(); ++i) { // index strs
            bool added = false;
            for (int j = 0; j < totalAnagrams; ++j) { // anagram index
                if (charOccurrence[i] == charOccurrence[representatives[j]]) {
                    result[j].push_back(strs[i]);
                    added = true;
                    break;
                }
            }
            if (added == false) {
                result.push_back({strs[i]});
                representatives.push_back(i);
                ++totalAnagrams;
            }
        }

*/
