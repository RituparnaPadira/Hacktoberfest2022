def destroyTargets(self, nums: List[int], space: int) -> int:
        nums.sort()
        modArr = []
        for n in nums:
            modArr.append(n % space)
            
        #print(nums)
        #print(modArr)
        
        have = set(nums)
        
        count = Counter()
        
        for mod in modArr:
            count[mod] += 1
        
        res = -1
        tmp = -1
        
        for i, n in enumerate(nums):
            if count[modArr[i]] > tmp:
                tmp = count[modArr[i]]
                res = n
            elif count[modArr[i]] == tmp:
                res = min(res, n)
                    
        #print(res, tmp)
        return res
