import java.util.Scanner;

//You are given an integer array nums. You can choose exactly one index (0-indexed) and remove the element. Notice that the index of the elements may change after the removal.
//leetcode question 1664
public class waysToMakeFair {
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
}
