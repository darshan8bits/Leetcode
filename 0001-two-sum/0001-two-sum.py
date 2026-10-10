class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i in range(0, len(nums)):
            num = nums[i]
            req = target - num
            if req in d:
                return [d[req], i]
            else:
                d[num] = i

        return [-1, -1] 