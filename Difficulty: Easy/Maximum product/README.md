<h2><a href="https://www.geeksforgeeks.org/problems/maximum-product4633/0">Maximum product</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array <strong>arr[]</strong> of integers, the task is to find a subsequence of size <strong>k</strong> whose product is maximum among all possible&nbsp;<span style="box-sizing: border-box; margin: 0px; padding: 0px;"><strong>k-</strong>sized</span>&nbsp;subsequences of a given array.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [1, 2, 0, 3], k = 2
<strong>Output:</strong> 6
<strong>Explanation</strong>: Subsequence containing elements {2, 3} gives maximum product: 2*3 = 6</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [1, 2, -1, -3, -6, 4], k = 4
<strong>Output:</strong> 14
<strong>Explanation</strong>: Subsequence containing {2, -3, -6, 4} gives maximum product: 2*(-3)*(-6)*4 = 144</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(nlogn).<br><strong>Expected Space&nbsp;</strong></span><strong style="font-size: 18px;">Complexity</strong><strong style="font-size: 18px;">:</strong><span style="font-size: 18px;">&nbsp;O(1).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ arr.size() ≤ 10<sup>5<br></sup></span><span style="font-size: 18px;">1 ≤ arr[i] ≤ 10<sup>6</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;