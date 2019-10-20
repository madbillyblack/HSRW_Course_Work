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
		

	}

}
