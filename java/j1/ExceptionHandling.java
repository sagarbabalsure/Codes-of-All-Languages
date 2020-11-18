class ExceptionHandling
{
	static int a=10;
	void sample()
	{
		if(a==10)
			throw new ArithmeticException("not valid");
		else
			System.out.println("welcome to vote");
	}
	public static void main(String[] args) {
		ExceptionHandling e=new ExceptionHandling();
		try{
			e.sample();
		}
		catch(ArithmeticException a){
			System.out.println("Exception occurs at "+a);
		}
	}

}