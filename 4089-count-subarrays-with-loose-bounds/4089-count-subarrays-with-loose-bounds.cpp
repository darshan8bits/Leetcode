class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int s = 0, e = 0;
        long long ans = 0;

        while(e < n){
            int num = nums[e];

            if(num > maxK || num < minK){
                s = e + 1;
                e++;
                continue;
            }

            ans += (long long)(e - s + 1);
            e++;
            
        }

        return ans;
        
        
    }
};