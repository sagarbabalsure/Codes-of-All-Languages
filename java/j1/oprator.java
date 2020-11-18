import java.util.Scanner;
public class oprator
{
	public static void main(String[] args)
	{
		int a,i;
		Scanner sc=new Scanner(System.in);
		a=sc.nextInt();
		int fact=factorial(a);
		System.out.println("Facorial of given no is: "+fact);
	}
	static int factorial(int n)
	{
		if(n==1)
			return 1;
		else
			return (n*factorial(n-1));
	}
}
