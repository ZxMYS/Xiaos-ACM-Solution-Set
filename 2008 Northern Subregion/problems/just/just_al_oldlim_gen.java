public class just_al_gen {
  public static void main (String args []) {
    int cnt = 0;
    for (Long i = 1L; i <= (long)1e10; i++) {
      String s = i.toString ();
      int z = 0;
      for (int j = 0; j < s.length (); j++)
        z += s.charAt (j) - '0';
      if (i % z == 0) ++cnt;
      if (i % (int)2e6 == 0) {
        System.out.println (cnt + ",");
        cnt = 0;
      };
    };
  };
};