import java.util.Scanner;

public class View {
	private BankBalance _api;
	private Authentication _auth;
	private Scanner _scan;
	
	public View(BankBalance api, Authentication auth, Scanner scan) {
		this._api = api;
		this._auth = auth;
		this._scan = scan;
	}
	
	public void display() {
		
		System.out.println("BANKING SERVICES");
			System.out.println("-----------------");
			System.out.println(" ");
			System.out.println("0. LOGIN");
			System.out.println("1. CREDIT");
			System.out.println("2. DEBIT");
			System.out.println("3. BALANCE");
			System.out.println("4. LOGOUT");
			System.out.println("5. EXIT");
			System.out.println("-----------------");
			System.out.println(" ");
			System.out.println("Choose your option:");
			int choice = this._scan.nextInt();
			System.out.println(" ");
			
			switch(choice) {
				case 0:
				    if(this._auth.isLoggedIn()) {
						System.out.println("Already LoggedIn.");
						break;
					}
					System.out.println("Enter username/password: ");
					String input[] = this._scan.next().split("/");
					boolean login = this._auth.doLogIn(input[0], input[1]);
					if(login)
						System.out.println("Successfully LogIn!");
					else 
						System.out.println("Wrong credentials!");
					break;
					
				case 1:
				    if(!this._auth.isLoggedIn()) {
						System.out.println("Please login first!");
						break;
					}
				    System.out.println("Enter Amount: ");
					int creditAmount = this._scan.nextInt();
					boolean creditStatus = this._api.creditBalance(creditAmount);
					if(creditStatus)
						System.out.println("Amount credited successfully!");
					else
						System.out.println("Something went wrong!");
					break;
					
				case 2:
				    if(!this._auth.isLoggedIn()) {
						System.out.println("Please login first!");
						break;
					}
				    System.out.println("Enter Amount: ");
					int debitAmount = this._scan.nextInt();
					boolean debitStatus = this._api.debitBalance(debitAmount);
					if(debitStatus)
						System.out.println("Amount debited successfully!");
					else
						System.out.println("Sorry! Balance is low.");
					break;
					
				case 3:
				    if(!this._auth.isLoggedIn()) {
						System.out.println("Please login first!");
						break;
					}
				    int balance = this._api.getBalance();
					System.out.println("Current Balance: "+balance);
					break;
					
				case 4:
				    boolean logout = this._auth.doLogOut();
					if(logout)
						System.out.println("Successfully LogOut!");
					else
						System.out.println("Already LoggedOut!");
					break;
					
				case 5: 
				    System.exit(1);
				    break;
					
				default:
				    System.out.println("Wrong choice!");
			}
	}
}


