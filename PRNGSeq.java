import java.util.Scanner;
import java.util.Random;

public class Solution {
    public static void main(String[] args) {
        Scanner istream = new Scanner(System.in);
        int t = istream.nextInt();
        while(t-- > 0) {
            int minval = istream.nextInt(), maxval = istream.nextInt();
            int[] num = new int[10];
            for(int i = 0; i < 10; i++)
                num[i] = istream.nextInt();
            int ds = 0;
            for(int s = minval; s <= maxval; s++) {
                boolean flag = true;
                Random r = new Random(s);
                for(int i = 0; i < 10; i++)
                    if (r.nextInt(1000) != num[i])
                        flag = false;
                if(flag) {
                    System.out.print(s + " ");
                    for(int i =0; i < 10; i++)
                        System.out.print(r.nextInt(1000) + " ");
                    System.out.println();
                }
            }
        }
    }
}
