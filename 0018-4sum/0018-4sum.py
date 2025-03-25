class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        combinaisons = set()
        nums.sort()
        temp = [nums[0]]
        previous = nums[0]
        counter = 1
        for num in nums[1:]:
            if num == previous:
                counter += 1
            else:
                counter = 1
                previous = num
            if counter <= 4:
                temp.append(num)
        nums = temp
        del(temp)

        for i in range(len(nums)-3):
            if nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target:
                break
            for j in range(i+1,len(nums)-2):
                if nums[i]+nums[j]+nums[j+1]+nums[j+2] > target:
                    break
                for k in range(j+1,len(nums)-1):
                    if nums[i]+nums[j]+nums[k]+nums[k+1] > target:
                        break
                    for l in range(k+1,len(nums)):
                        if nums[i]+nums[j]+nums[k]+nums[l] == target:
                            combinaisons.add((nums[i],nums[j],nums[k],nums[l]))
                        elif nums[i]+nums[j]+nums[k]+nums[l] > target:
                            break
        return [[combinaison[0], combinaison[1], combinaison[2], combinaison[3]] for combinaison in combinaisons]
        