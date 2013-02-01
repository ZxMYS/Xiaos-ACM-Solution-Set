import java.util.*;
import java.math.BigInteger;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException {
		/*FileInputStream infile=new FileInputStream("F:\\programs\\in.txt");
		InputStreamReader input=new InputStreamReader(infile);
		FileOutputStream outfile=new FileOutputStream("F:\\programs\\out");
		OutputStreamWriter output=new OutputStreamWriter(outfile);
		Scanner in = new Scanner(input);*/
		Scanner in = new Scanner(System.in);
		OutputStreamWriter output=new OutputStreamWriter(System.out);
		BigInteger[] fib=new BigInteger[481];
		fib[0]=new BigInteger("-1");
		fib[1]=new BigInteger("1");
		fib[2]=new BigInteger("2");
		BigInteger max=new BigInteger("10");
		max=max.pow(100);
		int i=0;
		for(i=3;fib[i-1].compareTo(max)<=0;i++){
			fib[i]=fib[i-1].add(fib[i-2]);
		}
		while(true){
			String a=new String(in.next());
			String b=new String(in.next());
			if(a.equals("0")&&b.equals("0")){
				break;
			}
			BigInteger beg=new BigInteger(a);
			BigInteger end=new BigInteger(b);
			int s=java.util.Arrays.binarySearch(fib, beg);
			int e=java.util.Arrays.binarySearch(fib, end);
			if(e<0)e+=2;
			if(s<0)s++;
			output.write(Math.abs(e)-Math.abs(s)+1+"\n");
			output.flush();
		}
	}
}
