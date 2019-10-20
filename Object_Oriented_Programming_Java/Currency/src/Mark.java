
public class Mark extends Euro
{
	private final static double EXCHANGE = 1.95583;
	
	public Mark(double value)
	{
		super(value/EXCHANGE);
	}
	
	public Mark(EURO euro)
	{
		super(euro.euroValue());
	}
	
	public double markValue()
	{
		return (euroValue() * EXCHANGE);
	}
}
