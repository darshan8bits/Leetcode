class Solution {
public:
    int sum(int n){
        int s = 0;
        while(n){
            int d = n % 10;
            s += d;
            n /= 10;
        }
        return s;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<tuple<int, int, int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({sum(nums[i]), nums[i], i});
        }
        sort(v.begin(), v.end());
        int swaps = 0;
        vector<bool> visited(n, false);

        int minswaps = 0;

        for(int i = 0; i < n; i++){
            if(visited[i] || get<2>(v[i]) == i) continue;

            int cycleLength = 0;
            int j = i;

            while(!visited[j]){
                visited[j] = true;
                j = get<2>(v[j]);
                cycleLength++;
            }

            minswaps += cycleLength - 1;
        }

        return minswaps;
    }
};