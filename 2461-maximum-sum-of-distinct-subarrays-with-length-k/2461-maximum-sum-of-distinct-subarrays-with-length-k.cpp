class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int i = 0;
        long long sum = 0;
        long long maxsum = 0;

        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            freq[nums[j]]++;

            if(j - i + 1 > k){
                freq[nums[i]]--;
                sum -= nums[i];

                if(freq[nums[i]] == 0){
                    freq.erase(nums[i]);
                }

                i++;

            }

            if(j - i + 1 == k && freq.size() == k){
                maxsum = max(sum, maxsum);
            }
        }
        return maxsum;
    }
};