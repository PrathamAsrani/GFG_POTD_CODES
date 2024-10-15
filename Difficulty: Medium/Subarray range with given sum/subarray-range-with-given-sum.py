#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    
    #Complete this fuction
    #Function to count the number of subarrays which adds to the given sum.
    def subArraySum(self,arr, tar):
        #Your code here
        umpp = {}
        acc = 0
        ans = 0
        for i in range(len(arr)):
            acc += arr[i]
            if acc == tar:
                ans += 1
            if umpp.get(acc - tar):
                ans += umpp.get(acc-tar)
            umpp[acc] = umpp.get(acc, 0)+1
        return ans
        

#{ 
 # Driver Code Starts.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        tar= int(input())
        ob = Solution()
        res = ob.subArraySum(arr,tar)
        print(res)
        # print("~")
        t -= 1


# } Driver Code Ends