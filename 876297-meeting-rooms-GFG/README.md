# [Meeting Rooms](https://www.geeksforgeeks.org/problems/attend-all-meetings/1)
## Easy
Given a 2D array arr[][], where arr[i][0]&nbsp;is the&nbsp;starting time&nbsp;of ith meeting and arr[i][1]&nbsp;is the&nbsp;ending time&nbsp;of ith meeting, the task is to check if it is possible for a person to attend all the meetings such that he can attend only one meeting at a particular time.
Note: A person can attend a meeting if its starting time is greater than or equal to the previous meeting's ending time.
Examples:
Input: arr[][] = [[1, 4], [10, 15], [7, 10]]Output: trueExplanation: Since all the meetings are held at different times, it is possible to attend all the meetings.
Input: arr[][] = [[2, 4], [9, 12], [6, 10]]
Output: false
Explanation: Since the second and third meeting overlap, a person cannot attend all the meetings.
Constraints:1 ≤ arr.size() ≤ 1050 ≤ arr[i] ≤ 2*106