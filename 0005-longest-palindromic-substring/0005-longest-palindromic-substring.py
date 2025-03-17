class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 1:
            return s
        queues = dict()
        substring = None
        for i, val in enumerate(s):
            if not 1 in queues.keys():
                substring = s[i]
                queues[1] = [(i, i, s[i])]
            else:
                queues[1].append((i, i, s[i]))
            if i > 0:
                if s[i] == s[i-1]:
                    substring = s[i-1:i+1]
                    if not 2 in queues.keys():
                        queues[2] = [(i-1, i, s[i-1:i+1])]
                    else:
                        queues[2].append((i-1, i, s[i-1:i+1]))
        level = 1
        maximum = 1
        while level in queues.keys():
            while len(queues[level]) > 0:
                current = queues[level].pop(0)
                if current[0] > 0 and current[1] < len(s) - 1:
                    if s[current[0] - 1] == s[current[1] + 1]:
                        if not level + 2 in queues.keys():
                            substring = s[current[0] - 1:current[1] + 2]
                            queues[level + 2] = [(current[0] - 1, current[1] + 1, s[current[0] - 1:current[1] + 2])]
                        else:
                            queues[level + 2].append((current[0] - 1, current[1] + 1, s[current[0] - 1:current[1] + 2]))
            del queues[level]
            if len(queues) > 0:
                level = min(queues.keys())
            #print(level)
            #print(queues)
            #print(substring)
        return substring

        