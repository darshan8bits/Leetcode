class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        leftproduct = [1] * len(nums)
        rightproduct = [1] * len(nums)

        for i in range(1, len(nums)):
            leftproduct[i] = leftproduct[i - 1] * nums[i - 1]

        for i in range(len(nums) - 2, -1, -1):
            rightproduct[i] = rightproduct[i + 1] * nums[i + 1]

        product = [1] * len(nums)
        for i in range(0, len(nums)):
            product[i] = leftproduct[i] * rightproduct[i]

        return product
