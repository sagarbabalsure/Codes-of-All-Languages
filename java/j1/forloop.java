import java.util.Scanner;
public class forloop
{
  public static void main(String[] args)
  {
  int arr[]={ 10,12,23,34 };
  for(int i:arr){
  	if(i==12){
  		break;
  	}
  	System.out.println(i);
  }
 }
}