package humanbeinz;

public class Human {

	private int idno;
	private int age;
	boolean isMale;
	private String firstName;
	private String name;
	private static int intSum = 0;
	
	Human(int hAge, boolean gender, String first_name, String family_name)
	{
		age = hAge;
		isMale = gender;
		firstName = first_name;
		name = family_name;
		intSum++;
		idno = intSum;
	}
	
	public void setAge(int newAge)
	{
		this.age = newAge;
	}
	
	public int getAge()
	{
		return this.age;
	}
	
	public boolean getIsMale()
	{
		return this.isMale;
	}
	
	public boolean olderThan(Human h)
	{
		return (age > h.age);
	}
	
	
	public static void main(String[] args)
	{	
	
	}

}
