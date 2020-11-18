import java.util.*;
class Duplicate{
	void duplicate(int a[]){
		int b[]=new int[5];
		int x=0,count=0;
		for (int i=0;i<a.length ;i++ ) {
			for (int j=0;j<b.length;j++ ) {
				if (a[i]==b[j]) {
					count++;
				}
			}
			if (count==0){
				b = add(b.length,b,a[i]);
			}
		}
		for (int i=0;i<b.length ;i++ ) {
			System.out.print(" "+ b[i]);
		}
	}
	static int[] add(int n, int arr[], int x) 
    { 
        int i; 
  
        // create a new array of size n+1 
        int newarr[] = new int[n + 1]; 
        for (i = 0; i < n; i++) 
            newarr[i] = arr[i]; 
  
        newarr[n] = x; 
  
        return newarr; 
    } 
}

public class Arrayop{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int a[] = new int[5];
		for(int i=0;i<5;i++){
			a[i]=s.nextInt();
		}
		Duplicate d = new Duplicate();
		d.duplicate(a);
		for (int i=0;i<5 ;i++ ) {
			if(i%2==0){
				System.out.print(" "+ a[i]);
			}
		}
	}
}