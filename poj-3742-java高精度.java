import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n,t;
        BigInteger[][] C=new BigInteger[210][210];
        for(int i=0;i<210;i++)
        	for(int j=0;j<=i;j++){
        		if(j==0||i==j){
        			C[i][j]=new BigInteger("1");
        			continue;
        		}
        		C[i][j]=C[i-1][j-1].add(C[i-1][j]);
        	}
        BigInteger matrix[][]=new BigInteger[210][210];
        int[] a=new int[210];
        BigInteger b[]=new BigInteger[210];
        while(in.hasNextInt()){
        	n=in.nextInt();
        	t=in.nextInt();
        	t=-t;
            BigInteger T=new BigInteger(Integer.toString(t));
        	for(int i=0;i<=n;i++){
        		a[i]=in.nextInt();
        	}
            for(int k=0;k<=n;k++){
            	int j=0;
            	for(int i=k;i>=0;i--,j++){
            		matrix[k][i]=C[k][j].multiply(T.pow(j));
            	}
            }
            for(int k=n;k>=0;k--){
            	b[k]=new BigInteger(Integer.toString(a[k]));
            	for(int j=k+1;j<=n;j++){
            		b[k]=b[k].subtract(matrix[j][k]);
            	}
            	for(int j=k;j>=0;j--){
            		matrix[k][j]=matrix[k][j].multiply(b[k]);
            	}
            }
            System.out.print(b[0]);
            for(int k=1;k<=n;k++)
            	System.out.print(" "+b[k]);
            System.out.println();
        }
    }
}