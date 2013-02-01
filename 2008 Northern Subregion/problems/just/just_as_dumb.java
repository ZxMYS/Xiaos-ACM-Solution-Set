import java.io.*;
import java.util.*;

public class just_as_dumb implements Runnable {

    public void solve() throws IOException {
        Scanner in = new Scanner(new File("just.in"));
        PrintWriter out = new PrintWriter(new File("just.out"));

        long n = in.nextLong();

        long ans = 0;
        for (long v = 1; v <= n; v++) {
            int s = 0;
            long w = v;
            while (w > 0) {
                s += w % 10;
                w /= 10;
            }
            if (v % s == 0) {
                ans++;
            }
        }

        out.println(ans);

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            System.exit(64);
        }
    }

    public static void main(String[] arg) throws IOException {
        new Thread(new just_as_dumb()).start();
    }
}