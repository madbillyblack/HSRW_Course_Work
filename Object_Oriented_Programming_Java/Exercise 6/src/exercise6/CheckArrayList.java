package exercise6;

import java.util.ArrayList;

public class CheckArrayList {

	public static void main(String[] args)
	{
		ArrayList<String> listE = new ArrayList<String>();
		listE.add("Apple");
		listE.add("Peach");
		listE.add("Table");
		listE.add("Banana");
		listE.add("Lemon");

		System.out.println(listE);
		
		if (listE.contains("Table"))
			listE.remove("Table");
		
		System.out.println(listE);
		
		if (listE.contains("Table"))
			System.out.println("How'd this Table get in here?!");
		else
			System.out.println("We sure showed that table who's boss!");
		
		if (listE.contains("Apple"))
			System.out.println("It's time to kick ass and eat apples, and I'm all out of asses to kick!");
		else
			System.out.println("Damn table stole my apple!");
		
		System.out.println("And then there were " + listE.size() + ".");
		
		System.out.println("Well, aren't you just a little Georgia " + listE.get(1) + "!");
	}

}
