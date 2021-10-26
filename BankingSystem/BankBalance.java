public class BankBalance {
	private int _balance;
	
	public BankBalance() {
		this._balance = 500;
	}
	
	public int getBalance() {
		return this._balance;
	}
	
	public boolean creditBalance(int newBalance) {
		this._balance += newBalance;
		return true;	
	}
	
	public boolean debitBalance(int newBalance) {
		if(newBalance > this._balance)
			return false;
		this._balance -= newBalance;
		return true;
	}
}
		
			
	
		
	