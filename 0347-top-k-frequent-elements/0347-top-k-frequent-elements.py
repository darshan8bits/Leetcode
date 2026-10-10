class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}
        for i in nums:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        
        l = []
        for key, freq in d.items():
            l.append([freq, key])
        
        l.sort()
        l.reverse()
        ans = []
        for i in range(0, k):
            ans.append(l[i][1])

        return ans