class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            if (seen.contains(complement)) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }


        // This needs ordered array
        // int low = 0;
        // int high = nums.size() - 1;

        // while (low <= high) {
        //     if (nums[low] + nums[high] == target) {
        //         return {low, high};
        //     } else if (nums[low] + nums[high] > target) {
        //         --high;
        //     } else if (nums[low] + nums[high] < target) {
        //         ++low;
        //     } else {
        //         break;
        //     }
        // }
        // return {};
    }
};
