/** 
Problem Statement : 
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

    You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
    Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
    Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array fruits, return the maximum number of fruits you can pick.
**/

class Solution 
{
    //Alternative Problem Statement : 
    // Find largest subarray that has ATMOST 2 distinct / unique integers.

    // Algorithm        : Variable Size Sliding Window 
    // Time Complexity  : 0(n)
    // Space Complexity : 0(1)

    public :
    int totalFruit(vector<int>& fruits) 
    {
        int n = (int)fruits.size();

        //Two Pointers : 
        int left = 0, right = 0;

        int distinctFruit = 0;
        unordered_map<int, int> mp;
        //mapping function : M(fruit type) = frequency 

        int answer = 0;

        //Subarray Condition : fruits[startWindow...endWindow] contains ATMOST 2 distinct interger / fruit type
      
        while(right < n)
        {
            //Inlude item at right boundary of the window.
            if(++mp[fruits[right]] == 1)
            {
                ++distinctFruit;
            }
            //Fix Window : Slide left boudnary of the window till the SUBARRAY CONDITION is satisfied.
            while(distinctFruit > 2)
            {
                if(--mp[fruits[left]] == 0)
                {
                    --distinctFruit;
                }
                ++left;

            }

            //Now subarray [left, left + 1, ....., right] has ATMOST distinct fruits
            //record the current subarray (possible answer)
            answer = max(answer, right - left + 1);
            
            //Slide right boundary of the window
            ++right;
        }
        return answer;
    }
};
