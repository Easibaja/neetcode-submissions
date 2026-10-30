class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> uniques;
        for (auto num : nums) {
            uniques.insert(num);
        }

        if (nums.size() != uniques.size())
        {
            return true;
        } else {
            return false;
        }
    }
};