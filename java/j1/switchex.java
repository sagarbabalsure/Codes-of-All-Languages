import java.util.Scanner;
public class switchex
{
 public static void main(String[] args)
 {
 	int i,a,b,c;
 	System.out.println("1.Addition ");
 	System.out.println("2.substraction ");
 	System.out.println("3.multiplication ");
 	System.out.println("4.division ");

 	Scanner sc=new Scanner(System.in);
 	System.out.println("Enter your choice: ");
 	i=sc.nextInt();
 	System.out.println("Enter values of a and b:");
 	a=sc.nextInt();
 	b=sc.nextInt();
 	switch(i)
 	{
 		case 1:
 		c=a+b;
 		System.out.println("Addition is" +c);
 		break;
 		case 2:
 		c=a-b;
 		System.out.println("substraction is" +c);
 		break;
 		case 3:
 		c=a*b;
 		System.out.println("multiplication is" +c);
 		break;
 		case 4:
 		c=a/b;
 		System.out.println("division is" +c);
 		break;
 		default:
 		System.out.println("Error");
 	}
 }
}