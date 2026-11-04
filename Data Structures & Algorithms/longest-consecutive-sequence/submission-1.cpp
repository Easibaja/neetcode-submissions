class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> numbers(nums.begin(), nums.end());

        int longest = 0;
        int streak = 1;

        auto it = numbers.begin();

        while (it != numbers.end()) {
            int value = *it;
            auto next = std::next(it);

            if (next != numbers.end() && value == *next - 1) {
                ++streak;
            } else {
                longest = std::max(longest, streak);
                streak = 1;
            }

            ++it;
        }

        return longest;
    }
};