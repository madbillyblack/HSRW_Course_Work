package euhsrw.S19927.BigPackage;
import java.math.BigInteger;
import java.util.Scanner;


public class BinominalFactorial {

	
	private static BigInteger bincoeffFac(BigInteger m, BigInteger k)
	{
		BigInteger numerator = Bigfactorial.factorial(m);
		BigInteger denom1 = Bigfactorial.factorial(k);
		BigInteger denom2 = m.subtract(k);
		BigInteger denom3 = Bigfactorial.factorial(denom2);
		BigInteger product = denom1.multiply(denom3);
		BigInteger result = numerator.divide(product);
		return result;	
	}
	
	public static void main(String[] args) {
		BigInteger coeff1 = bincoeffFac(
				BigInteger.valueOf(151), BigInteger.valueOf(53));
		System.out.println("Result " + coeff1);
	}
}
