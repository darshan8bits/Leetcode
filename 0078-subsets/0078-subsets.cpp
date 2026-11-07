class Solution {
public:
    void solve(int index, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        solve(index + 1, temp, ans, nums);
        temp.pop_back();
        solve(index + 1, temp, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        int index = 0;

        solve(index, temp, ans, nums);
        return ans;
    }
};
