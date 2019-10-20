import java.util.Scanner;

import javax.swing.JOptionPane;

public class KeyboardScreen {
static String MESSAGE = "Insert a text";

	public static void main(String[] args)
	{
		System.out.println(MESSAGE);
		Scanner inpDev = new Scanner(System.in);
		String text1 = inpDev.nextLine();
		System.out.println(text1);
		inpDev.close();
		
		String text2 = JOptionPane.showInputDialog(null,MESSAGE);
		JOptionPane.showMessageDialog(null, text2);
	}

}
