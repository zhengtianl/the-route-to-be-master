import java.util.ArrayList;
import java.util.List;

public class BinarySearch {
    public static void main(String[] args) {
        List<Integer> nums = new ArrayList<>();
        nums.add(1);
        nums.add(2);
        nums.add(3);
        nums.add(4);
        nums.add(5);
        nums.add(6);
        nums.add(9);
        int target = 9;
        System.out.println(search(nums, target));
    }

    public static int search(List<Integer> nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = l +((r - l) >> 1);
            if (target < nums.get(mid)) {
                r = mid - 1;
            }
            if (nums.get(mid) == target) {
                return mid;
            }
            if (target > nums.get(mid)) {
                l = mid + 1;
            }
        }
        return -1;
    }
}