import java.util.*;
class ArrayReverse{
	void arrrev(int c[],int l){
		for (int i=l-1;i>=0 ;i--) {
			System.out.print(" "+ c[i]);
		}
	}
}
public class MatrixAdd{
	public static void main(String[] args) throws Exception{
		// int a[][]=new int[3][3];
		// int b[][]=new int[3][3];
		Scanner s = new Scanner(System.in);
		// for(int i=0;i<3;i++){
		// 	for (int j=0;j<3;j++) {
		// 		a[i][j]=s.nextInt();
		// 	}
		// }
		// for(int i=0;i<3;i++){
		// 	for (int j=0;j<3;j++) {
		// 		b[i][j]=s.nextInt();
		// 	}
		// }
		// for(int i=0;i<3;i++){
		// 	for (int j=0;j<3;j++) {
		// 		a[i][j]=a[i][j]+b[i][j];
		// 	}
		// }

		// for(int i=0;i<3;i++){
		// 	for (int j=0;j<3;j++) {
		// 		System.out.print(a[i][j]+ " ");
		// 	}System.out.println();
		// }
		int c[]=new int[6];//declration
		for (int i=0;i<c.length;i++) {
			c[i]=s.nextInt();
		}
		int l=c.length;
		System.out.println(l);
		ArrayReverse arr = new ArrayReverse();
		arr.arrrev(c,l);
	}
}