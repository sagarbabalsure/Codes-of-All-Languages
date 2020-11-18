import java.util.*;
public class arrayFrequency
{
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int count=0;
		int a[]=new int[n];
		for(int i=0;i<n;i++){
			a[i]=s.nextInt();
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i]==a[j]){
					count++;
				}
			}System.out.println(a[i]+" occured "+ count + "times");
			count=0;

		}
	}
}