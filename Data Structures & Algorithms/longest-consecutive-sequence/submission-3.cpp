class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numbers(nums.begin(), nums.end());

        int longest = 0;
        int streak = 1;

        auto it = numbers.begin();

        while (it != numbers.end()) {
            int value = *it;

            if (!numbers.contains(value - 1)) {
                while (numbers.contains(value + 1)) {
                    ++streak;
                    ++value;
                }

                longest = std::max(longest, streak);
                streak = 1;
            }

            ++it;
        }

        return longest;
    }
};