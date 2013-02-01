/* Uses set comparison instead of list comparison. */
import java.util.*;
import java.io.*;

public class enchanted_gk_wrong {
    static Scanner in;
    static PrintWriter out;

    String reverse(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    Set<String> build(String s1, String s2) {
        s2 = reverse(s2);
        Set<String> result = new HashSet<String>();
        for (int i = 0; i < s1.length(); i++) {
            result.add(s1.charAt(i) + "" + s2.charAt(i));
        }
        return result;
    }

    public void run() {
        String s1 = in.next();
        String s2 = in.next();
        String t1 = in.next();
        String t2 = in.next();

        boolean result = build(s1, s2).equals(build(t1, t2));
        out.println(result ? "Yes" : "No");
    }

    public static void main(String[] args) throws Exception {        
        in = new Scanner(new File("enchanted.in"));
        out = new PrintWriter("enchanted.out");

        new enchanted_gk_wrong().run();

        in.close();
        out.close();
    }
}
