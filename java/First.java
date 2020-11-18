class First{
	public static void main(String args[]){
		System.out.println("Hello world");
		int a=10,b=23;
		System.out.println("addition of " +  a + " and " + b + " is " +  (a+b));
		if(a>b){
			System.out.println("a is greater");
		}
		else{
			System.out.println("b is greater");
		}
		for(int i=0;i<5;i++){
			if (i==3) {
				continue;
			}
			System.out.println(i);
		}
		
	}
}
