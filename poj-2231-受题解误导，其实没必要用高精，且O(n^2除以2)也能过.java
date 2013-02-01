import java.util.*;
import java.math.BigInteger;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException{
		Scanner in;
		OutputStreamWriter out;
		if(System.getProperty("ONLINE_JUDGE")==null){
			FileInputStream infile=new FileInputStream("f:\\programs\\in.txt");
			InputStreamReader input=new InputStreamReader(infile);
			in=new Scanner(input);
			FileOutputStream outfile=new FileOutputStream("f:\\programs\\out");
			out=new OutputStreamWriter(outfile);
		}else{
			in=new Scanner(System.in);
			out=new OutputStreamWriter(System.out);
		}
		int n=in.nextInt();
		BigInteger[] cows=new BigInteger[n];
		for(int i=0;i<n;i++){
			cows[i]=new BigInteger(in.next());
		}
		Arrays.sort(cows);
		BigInteger ans=BigInteger.ZERO,now;
		for(int i=1;i<n;i++){
			ans=ans.add(cows[i].subtract(cows[0]));
		}
		now=ans;
		for(int i=1;i<n;i++){
			now=now.add((cows[i].subtract(cows[i-1])).multiply(new BigInteger(Integer.toString(i*2-n))));
			ans=ans.add(now);
		}
		out.write(ans.toString());
		out.flush();
	}
}
