
public class Insect
{
	private static int numLegs = 6;
	private String name;
	private String factoid;
	
	public Insect(String name, String factoid)
	{
		this.name = name;
		this.factoid = factoid;
	}
	
	public String getName()
	{
		return this.name;
	}
	
	public String getFactoid()
	{
		return this.factoid;
	}
	
	public void setName(String newName)
	{
		this.name = newName;
	}
	
	public void setFactoid(String newFact)
	{
		factoid = newFact;
	}
	
	public String whatAmI()
	{
		String bio = ("I am a " + this.name + ". " + this.factoid);
		return bio;
	}

	
	public static void main(String[] args) 
	{
		Insect beetle = new Insect("Beetle", "Some beetles have water tight shells that allow them to breathe for a short time under water."); 
		Insect housefly = new Insect("Flegus-Paynintehasus", "Shoe fly, don't bother me.");
		
		System.out.println(beetle.whatAmI());
		System.out.println(housefly.whatAmI());
		
		housefly.setName("goddamn fly!");
		housefly.setFactoid("How'd that thing get in the house again?!");
		
		System.out.println(housefly.whatAmI());
	}
}
