import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import java.util.*;

class SchoolManSys extends Frame
{
    TextField srNo,fname,lname,rollNo,email;
    Button b1,b2;
    int x,y;
    String a,b,c,d,f;
    SchoolManSys()
    {
        setLayout(new FlowLayout());
        this.setLayout(null);
        Label n1=new Label("Sr No:",Label.CENTER);
        Label n2=new Label("First Name:",Label.CENTER);
        Label n3=new Label("Last Name:",Label.CENTER);
        Label n4=new Label("Roll No:",Label.CENTER);
        Label n5=new Label("Email:",Label.CENTER);
        srNo =new TextField(20);
        fname=new TextField(30);
        lname=new TextField(30);
        rollNo=new TextField(10);
        email=new TextField(50);
        // pass.setEchoChar('#');
        b1=new Button("submit");
        b2=new Button("Show");
        this.add(n1);
        this.add(n2);
        this.add(n3);
        this.add(n4);
        this.add(n5);
        this.add(srNo);
        this.add(fname);
        this.add(lname);
        this.add(rollNo);
        this.add(email);
       
        this.add(b1);
        this.add(b2);

        n1.setBounds(70,90,90,60);
        n2.setBounds(70,130,90,60);
        n3.setBounds(70,170,90,60);
        n4.setBounds(70,210,90,60);
        n5.setBounds(70,250,90,60);
        srNo.setBounds(200,100,90,20);
        fname.setBounds(200,140,90,20);
        lname.setBounds(200,180,90,20);
        rollNo.setBounds(200,220,90,20);
        email.setBounds(200,260,90,20);
        b1.setBounds(100,300,70,40);
        b2.setBounds(180,300,70,40);

 b1.addActionListener(new ActionListener() 
    {
        @Override
        public void actionPerformed(ActionEvent e) 
        {
            a = srNo.getText();
            b = fname.getText();
            c = lname.getText();
            d = rollNo.getText();
            f = email.getText();

            x = Integer.parseInt(a);
            y = Integer.parseInt(d);
            // System.out.println(a);
            System.out.println(x+" "+b+" "+c+" "+y+" "+f);

            connection(x,b,c,y,f);
        }
    });

 // Showing the records
 b2.addActionListener(new ActionListener() 
    {
        @Override
        public void actionPerformed(ActionEvent e) 
        {
            
        }
    });
 
    }

    public void connection(int x,String b,String c,int y,String f){
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/school","root","sagar");
            Statement st = con.createStatement();
            String sql = "INSERT INTO SMSystem(srNo,Fname,Lname,RollNo,Email) "+ "VALUES('"+x+ "','"
                +b+ "','"+c+ "','"+y+"','"+f+"')";
            st.executeUpdate(sql); 
            System.out.println("added to database");

        }catch(Exception e){
            System.out.println(e);
        }
    }
    public static void main(String args[])
    {
        SchoolManSys ml=new SchoolManSys();
        ml.setVisible(true);
        ml.setSize(400,400);
        ml.setTitle("my login window");
        
    }
}