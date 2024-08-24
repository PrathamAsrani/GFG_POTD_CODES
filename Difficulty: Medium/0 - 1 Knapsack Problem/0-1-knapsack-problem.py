#User function Template for python3

class Solution:
    
    #Function to return max value that can be put in knapsack of capacity W.
    def knapSack(self,W, wt, val):
        dp = [[-1]*(W+1) for _ in range(len(wt))]
        def fun(i, cap):
            nonlocal wt
            nonlocal val
            nonlocal dp
            if i == len(wt): return 0
            if dp[i][cap] != -1: return dp[i][cap]
            
            notTake = fun(i+1, cap)
            take = (fun(i+1, cap - wt[i]) + val[i]) if cap >= wt[i] else 0
            
            dp[i][cap] = max(take, notTake)
            return dp[i][cap]
            
        return fun(0, W)


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        # n = int(input())
        W = int(input())
        val = list(map(int, input().strip().split()))
        wt = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.knapSack(W, wt, val))

# } Driver Code Ends