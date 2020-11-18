import mypack.*;
class B{
	void msg(){
		System.out.println("hi i am $$$$$");
	}
}

interface Printable{
	void print();
}
class A2 implements Printable{
	public void print(){
		System.out.println("hello");
	}
}

class Emp{
	String s;
	int age;
	void insert(String s1,int a){
		s=s1;
		age=a;
	}
	
}
class Emp2 extends Emp{
	String add;
	int age=22;
	void insert2(String s){
		add=s;
	}
	void display(){
		System.out.println(s+ " and " + age + " and " + add );
		System.out.println(super.age);
	}

}
public class Employee{
	public static void main(String args[]){
		Emp2 e2 = new Emp2();
		A a2 = new A();
		B b2 = new B();
		a2.print();
		b2.msg();
		Printable obj = new A2();
		obj.print();
		e2.insert("sss",21);
		e2.insert2("pune");
		e2.display();
	}
}