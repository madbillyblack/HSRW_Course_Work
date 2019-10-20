package bmi19927;

public class BMICalculator
{
	//Numeric BMI range constants.
	private static final int MINWEIGHT = 19;
	private static final int MAXWEIGHT_U35 = 25;
	private static final int MAXWEIGHT = 27;
	private static final int WARNWEIGHT = 30;

	
	// String Constants for display messages.
	private static final String UNDERWEIGHT = "Underweight.";
	private static final String OPTIMAL = "Looking Good!";
	private static final String OVERWEIGHT = "Overweight";
	private static final String ALERT = "Significantly overweight.  Please See a doctor!";
	private static final String EMPTY = "Please enter Height, Weight, and Age to calculate your BMI.";
	
	private int weight = 1;
	private int height = 1;
	private double bmi = 1;
	private int age = 1;
	private int alertState = 1;
	
	public int getAlertState()
	{
		return alertState;	
	}

	public void setAlertState(int i)
	{
		this.alertState = i;
	}

	public int getWeight()
	{
		return weight;
	}
	
	public void setWeight(int weight)
	{
		this.weight = weight;
	}
	
	public int getHeight()
	{
		return height;
	}
	
	public void setHeight(int height)
	{
		this.height = height;
	}
	
	public double getBmi()
	{
		return bmi;
	}
	
	public void setBmi()
	{
		bmi = calculateBMI();
	}
	
	public int getAge()
	{
		return age;
	}
	
	public void setAge(int age)
	{
		this.age = age;
	}
	
	
	//Calculates BMI
	public double calculateBMI()
	{
		double bodyMassIndex;
		if (height != 0)
		{
			bodyMassIndex = weight/Math.pow(height/100.0, 2);	
		}
		else
		{
			bodyMassIndex = 0;
		}
		return bodyMassIndex;
		
	}
	
	public String bmiMessage()
	{
		String message;
		
		if(bmi == 0)
		{
			message = EMPTY;
			setAlertState(0);
		}
		else if(age < 35 && bmi > MINWEIGHT && bmi <= MAXWEIGHT_U35)
		{	
			message = OPTIMAL;
			setAlertState(2);
		}
		else
		{
			if (bmi <= MINWEIGHT)
			{
				message = UNDERWEIGHT;
				setAlertState(1);
			}
			else if (bmi <= MAXWEIGHT)
			{
				message = OPTIMAL;
				setAlertState(2);
			}
			else if (bmi <= WARNWEIGHT)
			{
				message = OVERWEIGHT;
				setAlertState(3);
			}
			else
			{
				message = ALERT;
				setAlertState(4);
			}
		}
		return message;
	}
	
	private void printInfo()
	{
		System.out.println(bmi);
		
		if(age < 35 && bmi > MINWEIGHT && bmi <= MAXWEIGHT_U35)
		{	
			System.out.println(OPTIMAL);
		}
		else
		{
			if (bmi <= MINWEIGHT)
			{
				System.out.println(UNDERWEIGHT);
			}
			else if (bmi <= MAXWEIGHT)
			{
				System.out.println(OPTIMAL);
			}
			else if (bmi <= WARNWEIGHT)
			{
				System.out.println(OVERWEIGHT);
			}
			else
			{
				System.out.println(ALERT);
			}
		}	
	}

	public void BMIEval()
	{
		this.setBmi();
		printInfo();
	}		

}
