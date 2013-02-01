/* Generates input */
import java.util.*;
import java.io.*;

public class deposits_gk_input {
    static Scanner in;
    static PrintWriter out;

    public void run() {
        int countA = 100000;
        int countB = 100000;
        int a = 8648640;
        int b = 8648640;

        out.println(countA);
        for (int i = 0; i < countA - 1; i++) {
            out.println(i + 1);
        }
        out.println(10000000);

        out.println(countB);
        for (int i = 0; i < countB; i++) {
            out.println(i + 1);
        }
    }

    public static void main(String[] args) throws Exception {        
        out = new PrintWriter("deposits.in");

        new deposits_gk_input().run();

        out.close();
    }
}
