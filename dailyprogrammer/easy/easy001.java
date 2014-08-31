import java.util.Scanner;

public class easy001 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.println("What is your name?");
		String name = scan.nextLine();

		System.out.println("What is your age?");
		int age = scan.nextInt();

		System.out.println("What is your username?");
		String username = scan.nextLine();

		System.out.format("Your name is %s, you are %d years old, and your username is %s.",
				name, age, username);
	}
}
