//{ Driver Code Starts
// Initial Template for javascript

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => { inputString += inputStdin; });

process.stdin.on('end', _ => {
    inputString =
        inputString.trim().split('\n').map(string => { return string.trim(); });

    main();
});

function readLine() { return inputString[currentLine++]; }

/* Function to print an array */
function printArray(arr, size) {
    let i;
    let s = '';
    for (i = 0; i < size; i++) {
        s += arr[i] + " ";
    }
    console.log(s);
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for (; i < t; i++) {
        let input1 = readLine().split(' ').map(x => parseInt(x));
        let n = input1.length;
        let arr = new Array(n);
        for (let i = 0; i < n; i++) {
            arr[i] = input1[i];
        }
        let obj = new Solution();
        let res = obj.findSplit(arr);
        if (res[0] === -1 && res[1] === -1 || res.length != 2)
            console.log("false");
        else {
            let sum1 = 0, sum2 = 0, sum3 = 0;
            for (let i = 0; i < arr.length; i++) {
                if (i <= res[0]) {
                    sum1 += arr[i];
                } else if (i <= res[1]) {
                    sum2 += arr[i];
                } else {
                    sum3 += arr[i];
                }
            }

            if (sum1 === sum2 && sum2 === sum3) {
                console.log("true");
            } else {
                console.log("false");
            }
        }
        console.log("~");
    }
}
// } Driver Code Ends


// User function Template for Javascript
/**
 * @param {number[]} arr
 * @returns {boolean}
 */

class Solution {

    findSplit(arr) {
        // Return an array of possible answer, driver code will judge and return true or
        // false based on
        let n = arr.length
        let total = arr.reduce((acc, curr) => acc+curr, 0)
        if(total%3 != 0)
            return [-1, -1]
        let k = Math.floor(total/3);
        let i, j, sum1, sum2;
        for(i = 0, j = n-1, sum1 = 0, sum2 = 0; sum1 < k || k > sum2; ){
            if(sum1 < k) sum1 += arr[i++]
            if(sum2 < k) sum2 += arr[j--]
        }
        return [i-1, j]
    }
}