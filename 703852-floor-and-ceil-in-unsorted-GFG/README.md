# [Floor and Ceil in Unsorted](https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1)
## Easy
Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].

Floor&nbsp;of x is the largest element which is smaller than or equal to x. Floor of x&nbsp;doesn’t exist if x is smaller than smallest element of arr[].
Ceil&nbsp;of x&nbsp;is the smallest element which is greater than or equal to x. Ceil of x&nbsp;doesn’t exist if x is greater than greatest element of arr[].

Return an array of integers denoting the [floor, ceil]. Return -1 for floor or ceiling if the floor or ceiling is not present.
Examples:
Input: x = 7 , arr[] = [5, 6, 8, 9, 6, 5, 5, 6]
Output: 6, 8
Explanation: Floor of 7 is 6 and ceil of 7 is 8.

Input: x = 10 , arr[] = [5, 6, 8, 8, 6, 5, 5, 6]
Output: 8, -1
Explanation: Floor of 10 is 8 but ceil of 10 is not possible.

Constraints :1 ≤ arr.size ≤ 1051 ≤ arr[i], x ≤ 106