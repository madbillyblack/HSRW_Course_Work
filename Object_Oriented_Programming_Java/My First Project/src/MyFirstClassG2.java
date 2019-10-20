import java.util.Scanner;

import javax.swing.JOptionPane;

public class MyFirstClassG2 {

	public static void main(String[] args)
	{
		int thinking = (1 + (int)(Math.random() * 10));
		String guessed = JOptionPane.showInputDialog(null, "I'm thinking of a number between 1 and 10. Can you guess it?");
		int guess = Integer.parseInt(guessed);
		int attempts = 0;
		String outcome = "";
		
		while (guess != thinking)
		{
			attempts++;
			String nextTry = JOptionPane.showInputDialog(null, "Wrong, do it again!");
			guess = Integer.parseInt(nextTry);
		}
		
		attempts++;
		if (attempts < 3)
		{	
			outcome = outcome + ("You guessed correctly! It only took you " + attempts + " attempts.");
			JOptionPane.showMessageDialog(null, "Great! You guessed " + thinking);
		}
		else
		{
			
			outcome = outcome + ("It took you " + attempts + " attempts to guess the right answer! You have brought shame to your family.");
			JOptionPane.showMessageDialog(null, "You FINALLY guessed that the number was " + thinking + ". " + outcome);
			
		}
	}

}
