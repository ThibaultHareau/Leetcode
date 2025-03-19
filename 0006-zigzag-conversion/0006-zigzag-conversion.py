class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 :
            return s
        row = 0
        increaseRow = True 
        substrings = ["" for i in range(numRows)]
        for char in s:
            substrings[row] = substrings[row] + char
            if increaseRow:
                if row < numRows - 1:
                    row += 1 
                    continue
                row -= 1
                increaseRow = False
                continue
            if row > 0:
                row -= 1
                continue
            row = 1
            increaseRow = 1
            continue
        return "".join(substrings)

