package allTehMoneyz;

public class Euro extends CurrencyV
{
	private double value;
	private double currencyRate;
		
	public double dollarValue()
	{
		return value*currencyRate;
	}
	
	private void setRate(double exchangeRate)
	{
		this.currencyRate = exchangeRate;
	}
	
	public Euro(double value)
	{
		this.value = value;
	}
	
	public double EuroValue(double dollarz)
	{
		double euroz = dollarz/currencyRate;
		return euroz;
	}
}
