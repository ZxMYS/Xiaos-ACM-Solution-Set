/* Zero prefix is ignored */
import java.util.*;
import java.io.*;
import static java.lang.Long.parseLong;

public class access_gk_prefix {
    static Scanner in;
    static PrintWriter out;
    Map<Long, Boolean> acl = new HashMap<Long, Boolean>();

    long prefix(long ip, long mask) {
        return (ip >> (32 - mask)) & ((1L << mask) - 1);
    }

    Boolean getDeepest(long ip, long mask) {
        for (long i = mask; i > 0; i--) {
            Boolean allow = acl.get(prefix(ip, i));
            if (allow != null) {
                System.out.println(i);
                return allow;
            }
        }
        return null;
    }

    public void nextNetwork(boolean allow) {
        String[] a = in.next().split("[./]");
        long ip = ((parseLong(a[0]) * 256 + parseLong(a[1])) * 256 + parseLong(a[2])) * 256 + parseLong(a[3]);
        long mask = a.length == 4 ? 32 : parseLong(a[4]);
        if (getDeepest(ip, mask) == null) {
            System.out.println("add " + Long.toString(ip, 2) + " " + Long.toString(prefix(ip, mask), 2));
            acl.put(prefix(ip, mask), allow);
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

        new access_gk_prefix().run();

        in.close();
        out.close();
    }
}
