def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        N = len(nums)
        pre = [0]
        suff = [0]
        
        res = [0] * N
        
        for n in nums:
            pre.append(n + pre[-1])
            
        for i in range(N - 1, -1, -1):
            suff.append(nums[i] + suff[-1])
        
        suff = suff[::-1]
        #print(pre)
        #print(suff)
        
        for i in range(N):
            res[i] += abs(pre[i] - (nums[i] * i))
            res[i] += abs(suff[i] - (nums[i] * (N - i)))
            
        return res
