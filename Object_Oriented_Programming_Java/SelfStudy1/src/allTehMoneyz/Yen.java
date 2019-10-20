package allTehMoneyz;

public class Yen extends CurrencyV
{
	private double value;
	private static double currencyRate;
	
	Yen(double value)
	{
		this.value = value;
	}
	
	public double dollarValue()
	{
		return value*currencyRate;
	}
	
}
