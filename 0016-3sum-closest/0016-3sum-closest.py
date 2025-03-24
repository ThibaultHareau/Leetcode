class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        result = -10**6
        for i in range(len(nums)-2):
            if nums[i]*3 > target + abs(target-result):
                return result
            j = i+1
            k = len(nums)-1
            while j!=k:
                res = nums[i]+nums[j]+nums[k]
                gap = abs(target-res)
                if gap == 0:
                    return res
                if abs(target-result) > gap:
                    result = res
                if res <= target:
                    j += 1
                else:
                    k -= 1
        return result
        