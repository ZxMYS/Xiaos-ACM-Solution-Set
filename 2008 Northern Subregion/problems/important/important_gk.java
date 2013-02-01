import java.util.*;
import java.io.*;

public class important_gk {
    static Scanner in;
    static PrintWriter out;

    public void run() {
    	out.println("Yes");

        int n = in.nextInt();
        in.nextLine();
        for (int i = 0; i < n; i++) {
            String line = in.nextLine().trim();
            char function = line.charAt(0);
            if (i > 0) {
                out.print('&');
            }
            out.format("(%1$s|~%1$s)", function);
        }
    }

    public static void main(String[] args) throws Exception {        
        in = new Scanner(new File("important.in"));
        out = new PrintWriter("important.out");

        new important_gk().run();

        in.close();
        out.close();
    }
}
