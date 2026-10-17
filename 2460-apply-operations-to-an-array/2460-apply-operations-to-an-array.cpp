class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1]){
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        vector<int> a;
        vector<int> b;
        for(auto &i : nums){
            if(i == 0) b.push_back(i);
            else a.push_back(i);
        }
        vector<int> ans;
        for(auto &i : a){
            ans.push_back(i);
        }
        for(auto &i : b){
            ans.push_back(i);
        }
        return ans;
    }
};