import java.util.*;
import java.io.*;

public class fenwick_gk_check {
    static Scanner in;
    static PrintWriter out;
    static final int MAX_N = 200000;
    static final int MAX_VALUE = 1000000000;

    public void run() {
        int n = in.nextInt();
        assert 1 <= n && n <= MAX_N;

        long[] a = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = in.nextInt();
            assert -MAX_VALUE <= a[i] && a[i] <= MAX_VALUE;

            long sum = 0;
            System.out.print(i);
            for (int j = 1; (i & j) == 0; j *= 2) {
                sum += a[i - j];
                System.out.print(" " + (i - j));
            }
            System.out.println();
            a[i - 1] -= sum;
        }

        for (int i = 1; i <= n; i++) {
            out.println(a[i]);
        }
    }

    public static void main(String[] args) throws Exception {        
        in = new Scanner(new File("fenwick.in"));
        out = new PrintWriter("fenwick.out");

        new fenwick_gk_check().run();

        in.close();
        out.close();
    }
}
