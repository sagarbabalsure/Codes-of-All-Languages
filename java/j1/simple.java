class addition{
	void run(){ System.out.println("base class");}
}
class addition1 extends addition implements Cloneable{
	void run()
	{ 
		super.run();
		System.out.println("derived class");
	}
	public Object clone()throws CloneNotSupportedException
	{
		return super.clone();
	}
}
class simple{
	public static void main(String[] args) {
		try{
		addition1 obj=new addition1();
		addition1 obj2=(addition1)obj.clone();
		obj.run();
		obj2.run();
		System.out.println(obj.toString());
		System.out.println(obj.hashCode());
		System.out.println(obj.getClass());
		}catch(CloneNotSupportedException c){ }


	}
}