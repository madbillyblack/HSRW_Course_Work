package euhsrw.S19927.BigPackage;

import java.math.BigInteger;
import java.util.Scanner;

public class Bigfactorial
{
	private static BigInteger ONE = BigInteger.valueOf(1);
	
	
	public static BigInteger factorial (BigInteger num)
	{
		BigInteger res = ONE;
		while(num.compareTo(ONE) > 0)
		{
			res = res.multiply(num);
			num = num.subtract(ONE);
		}
		return res;
	}
	
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger num = new BigInteger(sc.next());
		BigInteger factorial = factorial(num);
		System.out.println(num + "! = " + factorial);
		sc.close();
	}
}
