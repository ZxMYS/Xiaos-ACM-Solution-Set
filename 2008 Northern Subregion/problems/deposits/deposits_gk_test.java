/* Counts supplimentary information. */
import java.util.*;
import java.io.*;

public class deposits_gk_test {
    static Scanner in;
    static PrintWriter out;

    public void run() {
        int z = (int) Math.sqrt(500000000) + 100;
        int[] primes = new int[z];
        int cprimes = 0;
        for (int i = 2; i < z; i++) {
            primes[cprimes++] = i;
            for (int j = 0; j < cprimes - 1; j++) {
                if (i % primes[j] == 0) {
                    cprimes--;
                    break;
                }
            }
        }

        int maxA = 0;
        int c;
        int[] power = new int[1000];
        int[] value = new int[1000];
        int maxJ = 0;
        for (int i = 2; i < 5000000; i++) {
            c = 0;
            int n = i;
            for (int j = 0; primes[j] * primes[j] <= n; j++) {
                if (n % primes[j] == 0) {
                    value[c] = primes[j];
                    power[c] = 0;
                    while (n % primes[j] == 0) {
                        power[c]++;
                        n /= primes[j];
                    }
                    c++;
                }
                maxJ = Math.max(maxJ, j);
            }
            if (n != 1) {
                value[c] = n;
                power[c] = 1;
                c++;
            }
            int a = 1;
            for (int j = 0; j < c; j++) {
                a *= power[j] + 1;
            }
            if (maxA < a) {
                maxA = a;
                System.out.println(i + " " + a);
                System.out.print("!" + i);
                for (int j = 0; j < c; j++) {
                    System.out.print(" " + value[j] + "^" + power[j]);
                }
                System.out.println();
            }
            maxA = Math.max(maxA, a);
        }
        System.out.println(maxA);
        System.out.println(maxJ + " " + primes[maxJ]);
    }

    public static void main(String[] args) throws Exception {        
        in = new Scanner(new File("deposits.in"));
        out = new PrintWriter("deposits.out");

        new deposits_gk_test().run();

        in.close();
        out.close();
    }
}
