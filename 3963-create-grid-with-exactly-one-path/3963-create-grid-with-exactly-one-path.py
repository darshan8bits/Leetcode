class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        grid = [['#'] * n for _ in range(m)]
        for i in range(m):
            grid[i][0] = '.'
        for i in range(n):
            grid[m - 1][i] = '.'

        grid2 = []
        for i in range(m):
            string = ""
            for j in range(n):
                string += grid[i][j]
            grid2.append(string)
        
        return grid2