import java.util.ArrayList;

/*You are given a string s, where every two consecutive vertical bars '|' are grouped into a pair. In other words, the 1st and 2nd '|' make a pair, the 3rd and 4th '|' make a pair, and so forth.
Return the number of '*' in s, excluding the '*' between each pair of '|'.
Note that each '|' will belong to exactly one pair.


solution: this question we should create a flag to decide which stars we should count, then to count the stars.it is quit simple
*/
public class Solution {
    public int countAsterisks(String s) {
        int ans = 0;
        boolean flag = true;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '|') flag = !flag;
            else if (c == '*' && flag) ans++;
        }
        return ans;
    }

    //You are given an integer array nums. You can choose exactly one index (0-indexed) and remove the element. Notice that the index of the elements may change after the removal.
//leetcode question 1664

    public int waysToMakeFair(int[] nums){
        int oddSum =0, evenSum = 0; //定义odd位之和 和 偶数位之和
        int n = nums.length;
        for(int i = 0; i < n; i++){
            if (i % 2 == 0) evenSum += nums[i];
            else oddSum += nums[i];
        }
        int count = 0; // 定义答案
        int curOdd = 0, curEven = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                if(curEven + oddSum - curOdd == curOdd + evenSum - curEven-nums[i])count++; //i之前的偶不变 + 之后的奇数 = 之前的奇数和 - 之后的奇数和 =
                curOdd += nums[i];
            }
            else{
                if(curEven + oddSum - curOdd -nums[i]== curOdd + evenSum - curEven)count++;
                curEven += nums[i];
            }

        }
        return count;

    }

    public static void main(String[] args){
        Solution s = new Solution();
        String TestInput = "***hello world***";
        int[] nums = {2,1,6,4};
        int expectedOutput = 6;
        int actualOutput = s.countAsterisks(TestInput);
        int count = s.waysToMakeFair(nums);
        if(expectedOutput == actualOutput) {
            System.out.println("successful");
        }else{
            System.out.println("unsuccessful");
        }
        System.out.println(count);
    }

}




