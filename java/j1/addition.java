import java.util.*;
public class addition{

	public static void main(String[] args) {
		Scanner s1 = new Scanner(System.in);
		System.out.println("Enter two numbers: ");
		int a = s1.nextInt();
		int b = s1.nextInt();
		System.out.println("Enter Item ID: ");  
        String itemID = s1.nextLine();  
		int c=a+b;
		 

		System.out.println("Additin of" + a + "and"  +b+ "is " +c);
		
		System.out.println("substraction is " +itemID);
	}
}

/*import java.util.*;    
public class addition {    
     public static void main(String args[]){   
             Scanner scan = new Scanner(System.in);  
             System.out.print("Enter Item ID: ");  
         String itemID = scan.nextLine();  
         System.out.print("Enter Item price: ");  
         String priceStr = scan.nextLine();  
         double price = Double.valueOf(priceStr);         
         System.out.println("Price of Item "+itemID + " is $"+price);  
             scan.close();  
           }    
} */  
