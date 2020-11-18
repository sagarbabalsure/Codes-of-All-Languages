import java.sql.*;
import java.util.*;

public class jdbc{
	public static void main(String[] args) {
		try{
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/hospital","root","sagar");
			Statement st = con.createStatement();
			// Scanner s = new Scanner(System.in);
			// String uname = s.nextLine(); 
			// String name = s.nextLine(); 
			// String pass = s.nextLine();
			String sql = "INSERT INTO hospital_register "+ "VALUES('sagarbb3b','sagar311','111423')";
			st.executeUpdate(sql); 
			System.out.println("UserName"+"     "+"Name"+"     "+"Password");
			ResultSet re = st.executeQuery("select * from hospital_register");
			while(re.next()){
				System.out.println(re.getString(1)+"     "+re.getString(2)+"     "+re.getString(3));
			}

		}catch(Exception e){
			System.out.println(e);
		}
	}
}