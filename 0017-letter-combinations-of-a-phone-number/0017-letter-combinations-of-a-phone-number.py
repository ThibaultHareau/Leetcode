class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        MAP = {
            '2' : ['a','b','c'],
            '3' : ['d','e','f'],
            '4' : ['g','h','i'],
            '5' : ['j','k','l'],
            '6' : ['m','n','o'],
            '7' : ['p','q','r', 's'],
            '8' : ['t','u','v'],
            '9' : ['w','x','y', 'z']
        }
        possibilities = MAP[digits[0]]
        for digit in digits[1:]:
            temp = list()
            for possibility in possibilities:
                for char in MAP[digit]:
                    temp.append(f"{possibility}{char}")
            possibilities = temp
        return possibilities
        
