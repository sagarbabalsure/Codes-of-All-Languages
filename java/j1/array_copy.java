import java.util.*;
class array_copy{
	public static void main(String[] args) {
		int a[]=new int[5];
		int b[]=new int[5];
		Scanner s=new Scanner(System.in);
		for(int i=0;i<a.length;i++){
			a[i]=s.nextInt();
		}
		for(int i=0;i<a.length;i++){
			b[i]=a[i];
		}
		for(int i=0;i<b.length;i++){
			System.out.println(b[i]);
		}	
	}
}