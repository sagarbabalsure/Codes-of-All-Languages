	import java.util.*;

class Armstrong{
	int sum=0;
	void armstg(int a){
		int x=a;
		while(x!=0){
			int rem = x%10;
			sum = sum + (rem*rem*rem);

			x=x/10;
		}
		if(sum==a){
			System.out.println("The given number in Armstrong number");
		}else{
			System.out.println("The given number in not Armstrong number");
		}
		
	}
}
class Fibonacci{
	int n1=0;
	int n2=1;
	int n3;
	void fib(int x){
		System.out.print(n1+ " " + n2);
		for (int i=0;i<x ;i++ ) {
			n3=n1+n2;
			System.out.print(" "+n3);
			n1=n2;
			n2=n3;
		}
	}
}

class Reverse{
	void rev(int r){
		int rem,sum=0;
		while(r!=0){
			rem = r%10;
			sum=rem+(sum*10);
			r=r/10;
		}
		System.out.println(sum);
	}
}

class Perfect{
	int p=0;
	void perfect(int n){
		for (int j=1;j<n ;j++ ) {
			if(n%j==0){
				p = p+j;
			}
		}
		if (p==n) {
				System.out.println("The given number is perfect");
		}else{
			System.out.println("The given number is not perfect");
		}
	}
}

class Factorial{
	static int fact(int f){
		int facto=0;
			if(f==1){
				return 1;
			}
			else{
				facto=facto+(f*fact(f-1));
			}
			return facto;
}
}
public class Demo{
	public static void main(String[] args) {
	int p=0;
	Scanner s = new Scanner(System.in);
	int n= s.nextInt(); 
	Perfect p1 = new Perfect();
	p1.perfect(n);
	Reverse r1 = new Reverse();
	int r=s.nextInt();
	r1.rev(r);
	Fibonacci f1 = new Fibonacci();
	int x=s.nextInt();
	f1.fib(x);
	Armstrong a1 = new Armstrong();
	int a=s.nextInt();
	a1.armstg(a);
	Factorial f1 = new Factorial();
	int f=s.nextInt();
	int ff;
	ff=f1.fact(f);
	System.out.println(ff);
	}

}
