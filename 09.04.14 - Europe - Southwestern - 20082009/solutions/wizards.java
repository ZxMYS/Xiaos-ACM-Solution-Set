// problem: Wizards
// author : Walter Guttmann
// date   : 2008.10.21
// method : greatest common divisor of polynomial and its derivative
// runtime: O(n^4*log(n)^2) since the appearing numbers have O(n*log(n)) digits

import java.io.*;
import java.math.*;

public class wizards {

  // p := p mod q, scaled to integer coefficients; return new degree of p
  public static int mod(BigInteger[] p, int dp, BigInteger[] q, int dq) {
    assert dp >= dq && dq >= 0;
    while (dp >= dq) {
      // p := p * q[dq] - q * p[dp] * x^(dp-dq)
      BigInteger f = p[dp];
      for (int i=0 ; i<=dp ; i++)
        p[i] = p[i].multiply(q[dq]);
      for (int i=0 ; i<=dq ; i++)
        p[dp-dq+i] = p[dp-dq+i].subtract(q[i].multiply(f));
      // degree of p has been reduced by at least 1
      assert p[dp].signum() == 0;
      while (dp >= 0 && p[dp].signum() == 0)
        --dp;
    }
    // divide coefficients of p by their gcd to keep them small
    BigInteger d = BigInteger.ZERO;
    for (int i=0 ; i<=dp ; i++)
      d = d.gcd(p[i]);
    for (int i=0 ; i<=dp ; i++)
      p[i] = p[i].divide(d);
    return dp;
  }

  // are the polynomials p and q relatively prime?
  public static boolean relprime(BigInteger[] p, int dp, BigInteger[] q, int dq) {
    // dp,dq = degrees of p,q (-1 for zero polynomial)
    while (dp >= 0 && dq >= 0)
      // replace the greater of p,q by its remainder when divided by the other
      if (dp >= dq)
        dp = mod(p, dp, q, dq);
      else
        dq = mod(q, dq, p, dp);
    // if either of p,q is zero, the other is their gcd which must be constant
    return dp <= 0 && dq <= 0;
  }

  public static void main(String[] arg) throws Exception {
    StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    st.nextToken();
    for (int t = (int) st.nval ; t > 0 ; t--) {
      st.nextToken();
      int n = (int) st.nval;
      // a[i] is coefficient of x^i
      BigInteger[] a = new BigInteger[n+1];
      for (int i=0 ; i<=n ; i++) {
        st.nextToken();
        a[n-i] = BigInteger.valueOf((int) st.nval);
      }
      // d is derivative of polynomial a
      BigInteger[] d = new BigInteger[n];
      for (int i=0 ; i<n ; i++)
        d[i] = a[i+1].multiply(BigInteger.valueOf(i+1));
      // check a and d for common factors
      System.out.println(relprime(a, n, d, n-1) ? "Yes!" : "No!");
    }
  }

}
