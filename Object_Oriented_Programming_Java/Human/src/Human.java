public class Human
{
	private static int intSum = 0;

	
		private int idno;
		private int age;
		private boolean isMale;
		private String firstName;
		private String name;

		public Human(int age, boolean isMale, String firstName, String name)
		{
			intSum += 1;
			idno = intSum;
		}
		
		public String getName()
		{
			return name;
		}
	
		public int getAge()
		{
			return age;
		}
		
		public void setAge(int newAge)
		{
			age = newAge;
		}
		
		public boolean getIsMale()
		{
			return isMale;
		}
		
		public boolean olderThan(Human h)
		{
			return(age > h.getAge());
		}
}
