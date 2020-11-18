public class LeftRotate
{
	public static void main(String[] args) {
		int a[]={ 1,3,4,2,6 };
		System.out.print("Array in reverse order: ");
		for(int i=((a.length)-1);i>=0;i--){
			System.out.println(a[i]);
		}
		int n=2;
		int b[]=new int[a.length];
		for(int i=0;i<a.length;i++){
			int j=i-n;
			if(j>=0){
				b[j]=a[i];
			}
			else{
				b[a.length+j]=a[i];
			}
		}
		System.out.println("Left rotate of array by "+ n + "elements");
		for(int i=0;i<a.length;i++){
			System.out.println(b[i]);
		}
	}
}