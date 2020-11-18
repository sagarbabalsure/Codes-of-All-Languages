import java.util.regex.*;
public class Regex{
	public static void main(String[] args) {
		Pattern p = Pattern.compile(".s");
		Matcher m = p.matcher("asa");
		boolean b = m.matches();
		System.out.println(b);
		boolean b2 = Pattern.matches(".b","ab");
		System.out.println(b2);
		System.out.println(Pattern.matches("[^abc]","s"));
		System.out.println(Pattern.matches("[a-zA-Z0-9]{5}","Saga1"));
		System.out.println(Pattern.matches("[a-zA-Z0-9]{5}","Saga1"));

	}
}