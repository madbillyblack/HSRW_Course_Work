package allTehMoneyz;

public class USDollar extends CurrencyV
{
	private double value;
	
	public USDollar(double value)
	{
		this.value = value;
	}
	
	public double dollarValue()
	{
		return value;
	}
}
