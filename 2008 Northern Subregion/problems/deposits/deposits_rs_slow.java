import java.io.*;
import java.util.StringTokenizer;

/**
 * @author Roman V Satyukov
 */
public class deposits_rs_slow implements Runnable {
    private final String problemID = getClass().getName().split("_")[0].toLowerCase();
    private BufferedReader in;
    private PrintWriter out;
    
    private void check(boolean expr, String message) {
        if (!expr) {
            throw new AssertionError(message);
        }
    }
    
    private void solve() throws IOException {
        int n = Integer.parseInt(in.readLine());
        check((1 <= n) && (n <= 100000), "n is not in [1..100,000]");
        int[] a = new int[n];
        StringTokenizer st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
            check((1 <= a[i]) && (a[i] <= 1000000), "some of a[i] is not in [1..1000,000]");
        }
        int m = Integer.parseInt(in.readLine());
        check((1 <= m) && (m <= 100000), "m is not in [1..100,000]");
        int[] b = new int[m];
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < m; i++) {
            b[i] = Integer.parseInt(st.nextToken());
            check((1 <= b[i]) && (b[i] <= 1000000), "some of b[i] is not in [1..1000,000]");
        }
        int[] count = new int[1000001];
        for (int i = 0; i < m; i++) {
            int addon = b[i];
            for (int j = b[i]; j <= 1000000; j += addon) {
                count[j]++;
            }
        }
        long answer = 0;
        for (int i = 0; i < n; i++) {
            answer += count[a[i]];
        }
        out.println(answer);
    }
    
    public static void main(String[] args) {
        new Thread(new deposits_rs_slow()).start();
    }

    public void run() {
        try {
            in = new BufferedReader(new FileReader(new File(problemID + ".in")));
            out = new PrintWriter(new File(problemID + ".out"));
            solve();
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}
