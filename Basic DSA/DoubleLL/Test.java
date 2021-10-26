class Test {
	public static void main(String[] args) {
		
		DoubleLL dl = new DoubleLL();
		
		dl.addFirst(1);
		dl.addFirst(2);
		dl.addFirst(3);
		System.out.println(dl.length());
		dl.addLast(4);
		dl.addLast(5);
		dl.displayNodes();
		System.out.println(dl.getFirst());
		System.out.println(dl.getLast());
		dl.reverse();
		System.out.println(dl.getLast());
		dl.removeFirst();
		dl.reverse();
		dl.removeLast();
		dl.reverse();
		
		dl.displayNodes();
		
		
		
	}
}