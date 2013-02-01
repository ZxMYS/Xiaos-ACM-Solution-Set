import java.util.*;
import java.io.*;
import static java.lang.Long.parseLong;

public class access_gk_trie {
    static Scanner in;
    static PrintWriter out;
    static final int TRIE_SIZE = 33 * 100000;
    int[][] trie = new int[TRIE_SIZE][3];
    int nodes = 1;

    Boolean getDeepest(long ip, long mask) {
        int node = 0;
        Boolean value = trie[0][2] == 0 ? null : trie[0][2] == 1;
        for (int i = 1; i <= mask; i++) {
            int bit = (int) ((ip >> (32 - i)) & 1);
            if (trie[node][bit] == 0) {
                return value;
            }
            node = trie[node][bit];
            if (trie[node][2] != 0) {
                value = trie[node][2] == 1;
            }
        }           
        return value;
    }

    public void nextNetwork(boolean allow) {
        String[] a = in.next().split("[./]");
        long ip = ((parseLong(a[0]) * 256 + parseLong(a[1])) * 256 + parseLong(a[2])) * 256 + parseLong(a[3]);
        long mask = a.length == 4 ? 32 : parseLong(a[4]);
        if (getDeepest(ip, mask) == null) {
            int node = 0;
            for (int i = 1; i <= mask; i++) {
                int bit = (int) ((ip >> (32 - i)) & 1);
                if (trie[node][bit] == 0) {
                    trie[node][bit] = nodes++;
                }
                node = trie[node][bit];
            }
            trie[node][2] = allow ? 1 : 2;
        }
    }

    public long nextIp() {
        String[] a = in.next().split("[.]");
        return ((parseLong(a[0]) * 256 + parseLong(a[1])) * 256 + parseLong(a[2])) * 256 + parseLong(a[3]);
    }

    public void run() {
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {   
            boolean allow = in.next().equals("allow");
            in.next();
            nextNetwork(allow);
        }

        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            Boolean allow = getDeepest(nextIp(), 32);
            out.print(allow == null || allow ? 'A' : 'D');
        }
        out.println();
    }

    public static void main(String[] args) throws Exception {        
        in = new Scanner(new File("access.in"));
        out = new PrintWriter("access.out");

        new access_gk_trie().run();

        in.close();
        out.close();
    }
}
