
public class Yen extends CurrencyV
{
	private double value;
	private static double currencyRate;
	
	public Yen(double newValue)
	{
		this.value = newValue;
	}
	
	public double dollarValue()
	{
		return value*currencyRate;
	}
	public static void setCurrency(double cRate)
	{
		currencyRate=cRate;
	}
	
}