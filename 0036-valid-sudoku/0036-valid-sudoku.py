class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for _ in range(0, 9)]
        cols = [set() for _ in range(0, 9)] 
        boxes = [set() for _ in range(0, 9)]

        for i in range(0, 9):
            for j in range(0, 9):
                row = i
                col = j

                box = 3 * (row // 3) + (col // 3)

                if board[i][j] == '.':
                    continue
                
                dig = board[i][j]
                if dig in rows[row]:
                    return False
                elif dig in cols[col]:
                    return False
                elif dig in boxes[box]:
                    return False

                else:
                    rows[row].add(dig)
                    cols[col].add(dig)
                    boxes[box].add(dig)

        return True