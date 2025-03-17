class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        if x < 10:
            return True
        numlen = math.ceil(log10(x+1))
        for i in range(numlen//2):
            if (x//pow(10,i))%10 != (x//pow(10,numlen-i-1))%10:
                return False
        return True
        