import java.util.*;
import java.io.*;
import static java.lang.Long.parseLong;

public class access_gk_check {
    static Scanner in;
    static PrintWriter out;

    static final long MAX = 100000;

    Map<String, Boolean> acl = new HashMap<String, Boolean>();


    String prefix(long ip, long mask) {
        if (mask == 0) {
            return "";
        }
        StringBuilder sb = new StringBuilder(Long.toString((ip >> (32 - mask)) & ((1L << mask) - 1), 2));
        while (sb.length() < mask) {
            sb.insert(0, '0');
        }
        return sb.toString();
    }

    Boolean getDeepest(long ip, long mask) {
        for (long i = mask; i >= 0; i--) {
            Boolean allow = acl.get(prefix(ip, i));
            if (allow != null) {
                return allow;
            }
        }
        return null;
    }

    public void nextNetwork(boolean allow) {
        String s = in.next();
        System.out.println(s);
        assert s.matches("([1-9][0-9]*|0)\\.([1-9][0-9]*|0)\\.([1-9][0-9]*|0)\\.([1-9][0-9]*|0)*(/([1-9][0-9]*|0))?");
        String[] a = s.split("[./]");

        assert a.length == 4 || a.length == 5;
        assert 0 <= parseLong(a[0]) && parseLong(a[0]) <= 255;
        assert 0 <= parseLong(a[1]) && parseLong(a[1]) <= 255;
        assert 0 <= parseLong(a[2]) && parseLong(a[2]) <= 255;
        assert 0 <= parseLong(a[3]) && parseLong(a[3]) <= 255;
        assert a.length == 4 || 0 <= parseLong(a[4]) && parseLong(a[4]) <= 32;

        long ip = ((parseLong(a[0]) * 256 + parseLong(a[1])) * 256 + parseLong(a[2])) * 256 + parseLong(a[3]);
        long mask = a.length == 4 ? 32 : parseLong(a[4]);

        long prefix = ((1L << mask) - 1) << (32 - mask);
        assert (ip | prefix) == prefix;
       
        if (getDeepest(ip, mask) == null) {
            acl.put(prefix(ip, mask), allow);
        }
    }

    public long nextIp() {
        String s = in.next();
        assert s.matches("([1-9][0-9]*|0)\\.([1-9][0-9]*|0)\\.([1-9][0-9]*|0)\\.([1-9][0-9]*|0)");

        String[] a = s.split("[.]");

        assert a.length == 4;
        assert 0 <= parseLong(a[0]) && parseLong(a[0]) <= 255;
        assert 0 <= parseLong(a[1]) && parseLong(a[1]) <= 255;
        assert 0 <= parseLong(a[2]) && parseLong(a[2]) <= 255;
        assert 0 <= parseLong(a[3]) && parseLong(a[3]) <= 255;
        return ((parseLong(a[0]) * 256 + parseLong(a[1])) * 256 + parseLong(a[2])) * 256 + parseLong(a[3]);
    }

    public void run() {
        int n = in.nextInt();
        assert 0 <= n && n <= MAX;

        for (int i = 0; i < n; i++) {   
            String word = in.next();
            assert word.equals("allow") || word.equals("deny");
            boolean allow = word.equals("allow");
            word = in.next();
            assert word.equals("from");
            nextNetwork(allow);
        }

        int m = in.nextInt();
        assert 1 <= m && m <= MAX;

        for (int i = 0; i < m; i++) {
            Boolean allow = getDeepest(nextIp(), 32);
            out.print(allow == null || allow ? 'A' : 'D');
        }
        assert !in.hasNext();
        out.println();
    }

    public static void main(String[] args) throws Exception {        
        in = new Scanner(new File("access.in"));
        out = new PrintWriter("access.out");

        new access_gk_check().run();

        in.close();
        out.close();
    }
}
