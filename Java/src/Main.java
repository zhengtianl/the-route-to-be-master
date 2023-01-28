//题目描述：输入一个奇数 n，输出一个由 * 构成的 n 阶实心菱形。
//
//输入格式
//一个奇数 n。
//
//输出格式
//输出一个由 * 构成的 n 阶实心菱形。
// 曼哈顿距离，画上下左右都对称的图形
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int cx = n / 2, cy = n / 2; //计算中心点的坐标
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (Math.abs(i - cx) + Math.abs(j - cy) <= n / 2) //计算每个点到中心点Manhattan distance = abs（x- x1) + abs(y-y1)
                    System.out.printf("*"); //<=distance的为*
                else
                    System.out.printf("");//否则为空格
            }
            System.out.println("");//换行
        }
    }
}

