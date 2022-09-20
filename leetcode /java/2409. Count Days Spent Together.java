class Solution {
    int [] MM = new int []{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int [] presum;

    public int func(String s){
        int m = Integer.parseInt(s.substring(0, 2));
        int d = Integer.parseInt(s.substring(3, 5));
        int day = presum[m - 1] + d;
        return day;
    }

    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        presum = new int[13];
        for (int i = 0; i < 12; i ++){
            presum[i + 1] = presum[i] + MM[i];
        }

        int al = func(arriveAlice);
        int ar = func(leaveAlice);
        int bl = func(arriveBob);
        int br = func(leaveBob);

        int res = Math.max(0, Math.min(ar, br) - Math.max(al, bl) + 1);
        return res;

    }
}

