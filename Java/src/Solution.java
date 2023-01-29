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

    public static void main(String[] args){
        Solution s = new Solution();
        String  TestInput = "***hello world***";
        int expectedOutput = 6;
        int actualOutput = s.countAsterisks(TestInput);
        if(expectedOutput == actualOutput) {
            System.out.println("successful");
        }else{
            System.out.println("unsuccessful");
        }
    }

}




