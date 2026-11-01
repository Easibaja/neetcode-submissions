class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frecuency;
        for (int num : nums) {
            frecuency[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (const auto& entry : frecuency) {
            buckets[entry.second].push_back(entry.first);
        }

        vector<int> result;
        result.reserve(k);
        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);

                if (result.size() == k) {
                    return result;
                }
            }
        }
    }
};
