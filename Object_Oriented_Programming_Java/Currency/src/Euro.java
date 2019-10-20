
public class Euro extends CurrencyV
{
	private double value;
	private static double currencyRate;
		
	public Euro(double newValue)
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
