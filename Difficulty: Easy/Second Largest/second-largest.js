//{ Driver Code Starts
// Initial Template for javascript

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => { inputString += inputStdin; });

process.stdin.on('end', _ => {
    inputString = inputString.trim().split("\n").map(string => string.trim());
    main();
});

function readLine() { return inputString[currentLine++]; }

function main() {
    let t = parseInt(readLine());
    for (let i = 0; i < t; i++) {
        const arr = readLine().split(' ').map(x => parseInt(x));
        let obj = new Solution();
        let ans = obj.print2largest(arr);
        console.log(ans);
    }
}

// } Driver Code Ends

// } Driver Code Ends


// User function Template for javascript

class Solution {
    // Function returns the second largest element
    print2largest(arr) {
        // Code Here
        function removeDuplicates(arr) {
            return [...new Set(arr)];
        }
        
        const findSecondMaximum = (arr) => {
            arr = removeDuplicates(arr)
            let maxi = -1e18, sec_maxi = -1e18
            arr.forEach((ele) => {
                if(ele > maxi){
                    sec_maxi = maxi
                    maxi = ele;
                } else if (ele > sec_maxi){
                    sec_maxi = ele
                }
            })
            return sec_maxi
        }

        
        return findSecondMaximum(arr)
    }
}