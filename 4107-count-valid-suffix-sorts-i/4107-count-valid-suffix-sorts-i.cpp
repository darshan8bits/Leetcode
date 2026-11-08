class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {

        if(nums.size() == 1){
            if(target == nums) return 1;

            return 0;
        }
        
        unordered_map<int, int> f1;
        unordered_map<int, int> f2;

        int n = nums.size();

        for(auto &i : nums){
            f1[i]++;
        }
        for(auto &i : target){
            f2[i]++;
        }
        if(f2 != f1) return 0;

        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        prefix[0] = 1;
        suffix[n - 1] = 1;
        for(int i = 1; i < n; i++){
            if(nums[i - 1] != target[i - 1]) break;
            prefix[i] = 1;
        }
        for(int i = n - 2; i >= 0; i--){
            if(target[i] < target[i + 1]) break;
            suffix[i] = 1;
        }
        int c = 0;
        for(int i = 0; i < n; i++){
            if(suffix[i] && prefix[i]) c++;
        }
        return c;
    }
};