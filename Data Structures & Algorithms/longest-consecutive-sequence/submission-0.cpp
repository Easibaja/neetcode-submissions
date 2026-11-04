class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> numbers;

        for (auto num : nums) {
            numbers.insert(num);
        }

        int index = 0;
        int longest = 0;
        int streak = 1;

        auto it = numbers.begin();

        while (it != numbers.end()) {
            int value = *it;

            std::cout << value << std::endl;

            if (value == *std::next(it) - 1) {
                ++streak;
            } else {
                if (streak > longest) {
                    longest = streak;
                }
                streak = 1;
            }

            ++it;
        }

        if (streak > longest) {
            longest = streak - 1;
        }

        return longest;
    }
};
