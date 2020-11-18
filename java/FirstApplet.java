import java.applet.Applet;
import java.awt.*;
import java.awt.event.*; 
public class FirstApplet extends Applet implements ActionListener{
	TextField tf;
	Button bt;
	Image picture;
	public void init(){
		picture=getImage(getDocumentBase(),"image1.png");
		tf=new TextField();
		bt=new Button("click");
		tf.setBounds(30,40,150,20);
		bt.setBounds(80,150,60,50);
		add(tf);add(bt);
		bt.addActionListener(this);
		setLayout(null);
	}
	public void paint(Graphics g){
		g.setColor(Color.red);
		g.drawString("welcome to applet",200,200);
		g.drawRect(70,100,30,30);
		g.fillRect(170,100,30,30); 
		for (int i=0;i<500 ;i++ ) {
			g.drawImage(picture,i,600,this); 
		}
	}
	public void actionPerformed(ActionEvent e){  
  		tf.setText("Hiii");  
 }   
}