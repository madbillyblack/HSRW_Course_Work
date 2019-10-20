package bmi19927;

import java.awt.GridLayout;
import javax.swing.*;

public class TestFrame {

	public static void main(String[] args)
	{
		JFrame.setDefaultLookAndFeelDecorated(true);
		JFrame frame = new JFrame("Grid Test Layout");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(new GridLayout(3,2));
		frame.pack();
		frame.setVisible(true);
	}

}
