class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int c = 0;
        for(auto &i : arr1){
            bool flag = false;
            for(auto &j : arr2){
                if(abs(i - j) <= d) flag = true;
            }
            if(!flag) c++;
        }
        return c;
    }
};