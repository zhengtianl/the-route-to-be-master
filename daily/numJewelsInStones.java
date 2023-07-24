class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        int ans = 0;
        int jewelsLength = jewels.length(), stoneLength = stones.length();
        for(int i = 0; i < stoneLength; i++){
            char stone = stones.charAt(i);
            for (int j = 0; j < jewelsLength; j++){
                char jewel = jewels.charAt(j);
                if(stone == jewel){
                    ans ++;
                }
            }
        }
        //change
        return ans;
    }
}