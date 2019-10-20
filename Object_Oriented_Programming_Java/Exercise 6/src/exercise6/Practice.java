package exercise6;

import java.util.ArrayList;

public class Practice
{
	String name;
	ArrayList<Student> students;
	
	public Practice(String aName)
	{
		this.name = aName;
		this.students = new ArrayList<Student>();
	}
	
	void addStudent(Student aStudent)
	{
		students.add(aStudent);
	}
	
	public double getAverageGrade()
	{
		double average = 0;
		int nOS = students.size();
		
		if(nOS > 0)
		{
			
		}
	}
	
}
