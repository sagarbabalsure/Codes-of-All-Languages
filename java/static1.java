class stat{
	final int a=10;
	void print(int b){
		System.out.println("This is static method");
		a=b;
		System.out.println(a);
	}
}

public class static1{
	public static void main(String args[]){
		stat s1 = new stat();
		s1.print(22);

	}
}
