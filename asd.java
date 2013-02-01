import java.util.*;
public class asd {
	public static void main(String[] args){
		Date start=new Date();
		String a="foo";
		for(int i=0;i<100000000;i++){
			a+="bar";
			a=a.substring(0,3);
		}
		System.out.println(new Date().getTime()-start.getTime());

		start=new Date();
		StringBuffer strBuf=new StringBuffer("foo");
		for(int i=0;i<100000000;i++){
			strBuf.append("bar");
			strBuf.delete(3,7);
		}
		System.out.println(new Date().getTime()-start.getTime());
		
		start=new Date();
		StringBuilder strBid=new StringBuilder("foo");
		for(int i=0;i<100000000;i++){
			strBid.append("bar");
			strBid.delete(3,7);
		}
		System.out.println(new Date().getTime()-start.getTime());
	}
}
