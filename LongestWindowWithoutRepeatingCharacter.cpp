class Solution 
{
    public:
    
    //Algorithm       : Dynamic Size Sliding Window
    //Time Complexity : 0(n)

    // SUBARRAY MUST SATISFY FOLLOWING CONDITION : 
    // s[l...r] has NO repeating characters.

    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, int> mp;
        //Mapping Function : M(element) = frequency

        //Window Boundaries : 
        int startWindow = 0, endWindow = 0;
        int n = (int)s.length();

        int answer = 0;
      
        while(endWindow < n)
        {
            mp[s[endWindow]]++;

            // The first repeating character is caught at endWindow itself.
            // FIX Subarray s[startWindow....endWindow] 
            while(mp[s[endWindow]] > 1)
            {
                --mp[s[startWindow]];
                ++startWindow;
            }

            //s[startWindow...endWindow] satisfies the subarry condition.

            answer = max(answer, endWindow - startWindow + 1);
          
            ++endWindow;
        }

        return answer;
    }
};
