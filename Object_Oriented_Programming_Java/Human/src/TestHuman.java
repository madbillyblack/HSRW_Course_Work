
public class TestHuman
{
	public static Human pers1, pers2;
	{
		pers1 = new Human(20, true, "Bill", "Smith");
		pers2 = new Human(30, false, "Linda", "Miller"); 
	}
	
	public String toString()
	{
		String strGender ;
		if(getIsMale())
			strGender = " male";
		else
			strGender = " female";
		
		String strHuman = firstName + " " + name + "," + age + " " + strGender ;
 	}

}
