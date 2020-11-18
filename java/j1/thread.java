public class thread extends Thread{
 	public void run(){
 		/*for(int i=0;i<5;i++){
		try{Thread.sleep(500);}catch(InterruptedException e){System.out.println(e);}  
 			System.out.println(i); */
 			System.out.println("name: " + Thread.currentThread().getName());
 	 			System.out.println("priority: " + Thread.currentThread().getPriority());

 					}

	public static void main(String[] args) {
		thread t1=new thread();
		thread t2=new thread();
		/*System.out.println("name of thread one is: "+t1.getName());
		System.out.println("name of thread two is: "+t2.getName());
		t1.setName("1111");
		t2.setName("2222");*/
		t1.setPriority(Thread.MIN_PRIORITY);
		t2.setPriority(Thread.MAX_PRIORITY);
		t1.start();
		t2.start();
	}
}