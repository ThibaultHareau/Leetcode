class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        maxlen = 1
        for i in range(len(s)-1):
            nextstart = False
            if maxlen + i > len(s):
                return maxlen
            encountered = {s[i]}
            for j in range(i+1, len(s)):
                if s[j] in encountered:
                    maxlen = max(maxlen, j-i)
                    nextstart = True
                    break
                encountered.add(s[j])
            if nextstart:
                continue
            return len(s) - i
        return maxlen