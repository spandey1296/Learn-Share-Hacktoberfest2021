import java.util.Scanner;

public class BankingApplication {
	
	public static void main(String[] args) {
		
		Authentication AUTH = new Authentication();
		BankBalance API = new BankBalance();
		Scanner scan = new Scanner(System.in);
		View view = new View(API, AUTH, scan);
			
		while(true) {		
			view.display();
		}
	}
}
						
				