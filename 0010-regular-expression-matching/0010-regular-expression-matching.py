class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        #print(f"s->{s}   |   p->{p}")
        if len(s) == 0:
            if len(p) == 0:
                return True
            if len(p) == 1:
                return False
            if p[1] == '*':
                if len(p) == 2:
                    return True
                return self.isMatch(s, p[2:])
            return False
        if len(p) == 0:
            return False
        if len(p) == 1:
            if len(s) == 1 and p == '.':
                return True
            return s == p
        if p[1] == '*':
            if p[0] == '.':
                si = 0
                while si < len(s):
                    if self.isMatch(s[si:], p[2:]):
                        return True
                    si += 1
                return self.isMatch(s[si:], p[2:])
            else:
                si = 0
                while si < len(s) and s[si] == p[0]:
                    if self.isMatch(s[si:], p[2:]):
                        return True
                    si += 1
                return self.isMatch(s[si:], p[2:])
        else:
            if s[0] == p[0] or p[0] == '.':
                if len(s) == 1 and len(p) == 1:
                    return True
                if len(s) == 1:
                    return self.isMatch('', p[1:])  
                if len(p) == 1:
                    return self.isMatch(s[1:], '')      
                return self.isMatch(s[1:], p[1:])
            return False
        