/* Factors as */
import java.io.*;
import java.util.*;

public class deposits_gk_factor {
    static StreamTokenizer tokenizer;
    static PrintWriter out;

    static final int MAX_PRIME = 10009;
    static final int MAX_MULT = 100;

    int primes[] = new int[MAX_PRIME + 1];
    int cprimes;
    int power[] = new int[MAX_MULT];
    int value[] = new int[MAX_MULT];
    int cmults;
    int count[];
    long result;

    int nextInt() throws IOException {
        tokenizer.nextToken();
        return (int) tokenizer.nval;
    }

    public void calculatePrimes() {
        for (int i = 2; i <= MAX_PRIME; i++) {
            primes[cprimes++] = i;
            for (int j = 0; j < cprimes - 1; j++) {
                if (i % primes[j] == 0) {
                    cprimes--;
                    break;
                }
            }
        }
    }

    void factorize(int i) {
        cmults = 0;
        for (int j = 0; primes[j] * primes[j] <= i; j++) {
            if (i % primes[j] == 0) {
                value[cmults] = primes[j];
                for (power[cmults] = 0; i % primes[j] == 0; i /= primes[j]) {
                    power[cmults]++;
                }
                cmults++;
            }
        }

        if (i != 1) {
            value[cmults] = i;
            power[cmults] = 1;
            cmults++;
        }
    }

    void multipliers(int level, int val) {
        if(level == cmults) {
            if (val < count.length) {
                result += count[val];
            }
        } else {
            for(int k = 0; k <= power[level]; k++) {
                multipliers(level + 1, val);
                val *= value[level];
            }
        }
    }

    public void run() throws IOException {
        int n = nextInt();
        int a[] = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = nextInt();
        }

        int m = nextInt();
        int b[] = new int[m];
        for(int i = 0; i < m; i++) {
            b[i] = nextInt();
        }

        System.out.println("read");

        calculatePrimes();

        int maxB = 0;
        for (int i = 0; i < m; i++) {
            int j2 = b[i];
            maxB = Math.max(maxB, j2);
        }
        count = new int[maxB + 1];

        for (int i = 0; i < m; i++) {
            count[b[i]]++;
        }

        for (int i = 0; i < a.length; i++) {
            factorize(a[i]);
            multipliers(0, 1);
        }

        out.println(result);
    }

    public static void main(String args[]) throws Exception {
        tokenizer = new StreamTokenizer(new FileReader("deposits.in"));
        out = new PrintWriter("deposits.out");
        (new deposits_gk_factor()).run();
        out.close();
    }
}
