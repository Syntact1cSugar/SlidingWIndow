/**
Problem Statement : 
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
**/

class Solution 
{
    // Alternative Problem Statement: Find the longest substring that has ATMOST ONE 0 element.
    // Defining subarray condition: 
    // nums[i..k] is valid iff: countZero(i..k) <= 0

    public int longestSubarray(int[] nums) 
    {
        int n               = nums.length;
        int countZero       = 0;
        int longestSubarray = 0;

        // Two Pointers: 
        int left  = 0;
        int right = 0;

        while(right < n)
        {
            countZero += (1 - nums[right]);
            // Fix subarray to satsify the subarray condition.
            while(countZero > 1)
            {
                countZero -= (1 - nums[left]);
                ++left;
            }
            longestSubarray = Math.max(longestSubarray, right - left + 1);
            ++right;
        }

        return longestSubarray - 1;
    }
}
