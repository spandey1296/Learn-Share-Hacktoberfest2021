// way of object creation in java

class ObjectCreation implements Cloneable {
	
	String _name = null;
	int _age = 0;
	
	public ObjectCreation() {
		super();
	}
	
	public ObjectCreation(String name, int age) {
		this._name = name;
		this._age = age;
	}
	
	public void getWishMessage() {
		String msg = "Hi, "+this._name+"! welcome into coding world.";
		System.out.println(msg);
	}
	
	public void isAdult() {
		if(this._age >= 18) 
			System.out.println("You are Adult now.");
		else
			System.out.println("You are still Minor.");
	}
	
	public static ObjectCreation getNewObject(String name, int age) {
		return new ObjectCreation(name, age);
	}
	
	public static void main(String[] args) throws Exception {
		
		
		// method one ---- using new operator
		ObjectCreation obj1 = new ObjectCreation("shajoffcl", 22);
		obj1.getWishMessage();
	    obj1.isAdult();
		System.out.println(obj1._name);
		
		// method two ---- using clone method
		ObjectCreation obj2 = (ObjectCreation)obj1.clone();
		obj2.getWishMessage();
		
		// method three ---- using factory method
		ObjectCreation obj3 = getNewObject("jafri", 16);
		obj3.getWishMessage();
		obj3.isAdult();
		
	}
	
}
		
		
