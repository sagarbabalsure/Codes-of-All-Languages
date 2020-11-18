import java.util.*;

public class MinToYear{
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int min = s.nextInt();
		int d=0,h=0,y=0;
		h=min/60;
		min = min%60;
		if (h>24){
			d = h/24;
			h=h%24;
			if(d>365){
				y=d/365;
				d=d%365;
			}
		}
		System.out.println(y+ " years: " +d+ " days: "+h+" hours: "+min + " minutes");

	}
}