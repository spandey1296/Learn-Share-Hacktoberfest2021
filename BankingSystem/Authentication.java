public class Authentication {
	private String _username;
	private String _password;
	private boolean flag;
	
	public Authentication() {
		this._username = "shajoffcl";
		this._password = "admin@321";
		this.flag = false;
	}
	
	public boolean isLoggedIn() {
		return this.flag;
	}
	
	public boolean doLogIn(String uname, String pass) {
		if(uname.equals(this._username) && pass.equals(this._password)) {	
			this.flag = true;
			return true;
		}
		return false;
	}
	
	public boolean doLogOut() {
		if(isLoggedIn()) {
			this.flag = false;
			return true;
		}
		return false;
	}
}
		