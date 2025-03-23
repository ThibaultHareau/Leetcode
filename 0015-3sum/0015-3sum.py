class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        dic = dict()
        output = list()
        for num in nums:
            if num in dic.keys():
                dic[num] += 1
            else:
                dic[num] = 1
        print(dic)
        nums = list(set(nums))
        nums.sort()
        for i in range(len(nums)):
            if nums[i] > 0: 
                return output
            if nums[i] == 0:
                if dic[0] >= 3:
                    output.append([0,0,0])
                return output
            if dic[nums[i]] >= 2:
                if -2*nums[i] in dic.keys():
                    output.append([nums[i], nums[i], -2*nums[i]])
            if i < len(nums) - 1:
                for num2 in nums[i+1:]:
                    if -(nums[i]+num2) < num2 :
                        break
                    if -(nums[i]+num2) == num2:
                        if dic[num2] >= 2:
                            output.append([nums[i], num2, num2])
                    elif -(nums[i]+num2) in dic.keys() :
                        output.append([nums[i], num2, -(nums[i]+num2)])
            else: 
                return output


                        
        return output
                    


             
        
