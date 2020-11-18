import java.io.*;
public class Files{
	public static void main(String[] args) {
		File f = new File("demo.txt");
		try{
			if (f.createNewFile()){
			System.out.println("file is created");
		}else{
			System.out.println("file is already exists");
		}
	}catch(IOException e){
		System.out.println("An error occured");
		e.printStackTrace();
	}

	try{
		FileWriter fw = new FileWriter("demo.txt");
	fw.write("Hi,I am sagar babalsure");
	fw.close();
}catch(IOException e){
	System.out.println("An error occured");
		e.printStackTrace();
}

	}
}