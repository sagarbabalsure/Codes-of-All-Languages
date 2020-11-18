class Mthread extends Thread{
	public void run(){
		System.out.println("thtreadsrf is running");
		for (int i=0;i<5 ;i++ ) {
			System.out.println(i);
		}
	}
	public static void main(String[] args) {
		Mthread t1 = new Mthread();
		Mthread t2 = new Mthread();
		t1.start();
		t2.start();
	}
}