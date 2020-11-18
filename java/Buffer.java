import java.io.*;
import java.util.*;

public class Buffer{
	public static void main(String[] args) throws Exception{
		Scanner s = new Scanner(System.in);
		String s1=s.nextLine();
		System.out.println(s1);
		InputStreamReader r=new InputStreamReader(System.in);    
	    BufferedReader br=new BufferedReader(r);            
	    System.out.println("Enter your name");    
	    String name=br.readLine();    
	    System.out.println("Welcome "+name);    
		}
}