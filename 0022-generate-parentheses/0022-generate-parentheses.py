class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        # (current string, remaining opening, remaining closing)
        queue = [('('*i+')', n-i, n-1) for i in range(1,n+1)]
        output = set()
        while len(queue) > 0:
            element = queue.pop(0)
            if element[1] == 0 and element[2] == 0:
                output.add(element[0])
                continue
            #Add opening
            if element[1] > 0:
                queue.append((element[0]+'(', element[1]-1, element[2]))
            #Add closing
            if element[2] > element[1]:
                queue.append((element[0]+')', element[1], element[2]-1))
        return list(output)
        
