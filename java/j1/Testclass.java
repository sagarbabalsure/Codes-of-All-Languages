class Student{
	int id;
	String name;
	static String clg="Modern";
	void get_info(int i,String n){
		id=i;
		name=n;
	}
	void display(){
		System.out.println(id + " " + name + " " + clg);
	}
}
public class Testclass{
	public static void main(String[] args) {
		Student s1=new Student();
		Student s2=new Student();
		s1.get_info(2,"sagar");
		s2.get_info(2,"amit");
		s1.display();
		s2.display();
		System.out.println(s1.getName());

	}
}