// problem: First Knight
// author : Walter Guttmann
// date   : 2008.07.03
// method : linear equations, Gaussian elimination for band-limited matrices
// runtime: O(m*n^3)

import java.io.*;

public class knight {

  static StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
  static double readd() throws Exception {
    st.nextToken();
    return st.nval;
  }

  // move from (i,j) to (i+di[k-1],j+dj[k-1])
  static final int[] di = {1,0,-1,0};
  static final int[] dj = {0,1,0,-1};

  static final int maxn = 64;
  static final int maxv = maxn*maxn;

  // equation system is matrix * unknowns = vec
  // band[i][j] is matrix[i][i-n+j] ; rest of matrix is 0
  static double[][] band = new double[maxv][2*maxn+1];
  static double[] vec = new double[maxv];

  public static void main(String[] args) throws Exception {
    while (true) {
      int m = (int) readd();
      int n = (int) readd();
      if (m == 0 || n == 0) break;
      // matrix := 1 ; vec := (1,...,1,0)
      for (int i=0 ; i<m*n ; i++)
        for (int j=0 ; j<2*n+1 ; j++)
          band[i][j] = 0.0;
      for (int i=0 ; i<m*n ; i++)
        band[i][n] = vec[i] = 1.0;
      vec[m*n-1] = 0.0;
      // enter probabilities into matrix
      for (int k=0 ; k<4 ; k++)
        for (int i=0 ; i<m ; i++)
          for (int j=0 ; j<n ; j++) {
            double p = readd();
            // moving out of the area?
            if (0 <= i+di[k] && i+di[k] < m &&
                0 <= j+dj[k] && j+dj[k] < n)
              // there are m*m blocks of size n*n
              // index i*n+j is row #j of block #i
              // columns addressed relative to diagonal at index n
              band[i*n+j][n+di[k]*n+dj[k]] = -p;
          }
      // forward elimination
      for (int i=0 ; i<m ; i++)
        for (int j=0 ; j<n ; j++) {
          // pivot is on the diagonal
          double p = band[i*n+j][n];
          // normalise the current row
          vec[i*n+j] /= p;
          for (int q=0 ; q<=n && i*n+j+q<m*n ; q++)
            band[i*n+j][n+q] /= p;
          // eliminate first columns of next n rows
          for (int r=1 ; r<=n && i*n+j+r<m*n ; r++)
            // p = the first entry of row r below the current one
            if ((p = band[i*n+j+r][n-r]) != 0.0) {
              // row operation
              vec[i*n+j+r] -= p * vec[i*n+j];
              for (int q=0 ; q<=n && i*n+j+q<m*n ; q++)
                band[i*n+j+r][n-r+q] -= p * band[i*n+j][n+q];
            }
        }
      // backward elimination
      for (int i=m-1 ; i>=0 ; i--)
        for (int j=n-1 ; j>=0 ; j--)
          // eliminate last columns of previous n rows
          for (int r=1 ; r<=n && i*n+j-r>=0 ; r++) {
            // row operation
            vec[i*n+j-r] -= band[i*n+j-r][n+r] * vec[i*n+j];
            band[i*n+j-r][n+r] = 0.0;
          }
      // solution is in first row of vec
      System.out.println(vec[0]);
    }
  }

}
