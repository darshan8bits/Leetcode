class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        s = 0
        e = m * n - 1

        while s <= e:
            mid = s + (e - s) // 2

            r = mid // n
            c = mid % n

            if matrix[r][c] == target:
                return True
            elif matrix[r][c] < target:
                s = mid + 1
            else:
                e = mid - 1
        
        return False