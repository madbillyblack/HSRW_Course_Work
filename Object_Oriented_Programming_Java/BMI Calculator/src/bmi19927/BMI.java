package bmi19927;
import java.awt.*;
import java.text.DecimalFormat;

import javax.swing.*;
import javax.swing.event.*;

public class BMI
{
	public static void messageColor(JLabel label, int alertState)
	{
		switch(alertState)
		{
		case 0:
			label.setBackground(new Color(255,255,255));
			break;
		case 1:
			label.setBackground(new Color(255,255,0));
			break;
		case 2:
			label.setBackground(new Color(0,255,0));
			break;
		case 3:
			label.setBackground(new Color(255,255,0));
			break;
		case 4:
			label.setBackground(new Color(255,0,0));
			break;
		}
	}
	
	public static void main(String[] args)
	{
		BMICalculator calculator = new BMICalculator();
		JFrame.setDefaultLookAndFeelDecorated(true);
		JFrame testGrid = new JFrame("BMI Calculator");
		testGrid.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		testGrid.setLayout(new GridLayout(2,2));
		JPanel panel_1 = new JPanel();
		panel_1.setLayout(new GridLayout(3,3,3,3));
		JPanel panel_2 = new JPanel();
		panel_2.setLayout(new GridLayout(2,3));
		


		JLabel heightLabel = new JLabel("Height (cm)", SwingConstants.RIGHT);
		JLabel heightValue = new JLabel("" + calculator.getHeight());
		JLabel weightLabel = new JLabel("Weight (kg)", SwingConstants.RIGHT);
		JLabel weightValue = new JLabel("" + calculator.getWeight());
		JLabel ageLabel = new JLabel("Age", SwingConstants.RIGHT);
		JLabel ageValue = new JLabel("" + calculator.getAge());
		JLabel bmiLabel = new JLabel("0.0", SwingConstants.CENTER);
		JLabel messageLabel = new JLabel(calculator.bmiMessage(), SwingConstants.CENTER);
		messageLabel.setOpaque(true);
		messageLabel.setBackground(Color.white);
		bmiLabel.setOpaque(true);
		
		DecimalFormat df = new DecimalFormat("0.0");
		
		//Sets slider to adjust height.
		//Maximum value corresponds to tallest recorded human in history.
		JSlider heightSlider = new JSlider(JSlider.HORIZONTAL,50, 272, 50);
		heightSlider.addChangeListener(new ChangeListener()
		{
			public void stateChanged(ChangeEvent e)
			{
				JSlider source = (JSlider) e.getSource();
				calculator.setHeight(source.getValue());
				calculator.setBmi();

				heightValue.setText("" + calculator.getHeight());
				bmiLabel.setText(df.format(calculator.getBmi()));
				messageLabel.setText(calculator.bmiMessage());
//				calculator.setAlertState();
				BMI.messageColor(messageLabel, calculator.getAlertState());
			}	
		});
		heightSlider.setPaintLabels(true);
		heightSlider.createStandardLabels(1);
		
		
		//Sets slider to adjust weight.
		//Maximum value corresponds to heaviest recorded human in history.
		JSlider weightSlider = new JSlider(JSlider.HORIZONTAL,20, 442, 20);
		weightSlider.addChangeListener(new ChangeListener()
		{
			public void stateChanged(ChangeEvent e)
			{
				JSlider source = (JSlider) e.getSource();
				calculator.setWeight(source.getValue());
				calculator.setBmi();
//				calculator.setAlertState();
				weightValue.setText("" + calculator.getWeight());
				bmiLabel.setText(df.format(calculator.getBmi()));
				messageLabel.setText(calculator.bmiMessage());
				BMI.messageColor(messageLabel, calculator.getAlertState());
			}	
		});
		
		
		//Sets slider to adjust age.
		//Maximum value corresponds with oldest recorded human in history.
		JSlider ageSlider = new JSlider(JSlider.HORIZONTAL,10, 122, 10);
		ageSlider.addChangeListener(new ChangeListener()
		{
			public void stateChanged(ChangeEvent e)
			{
				JSlider source = (JSlider) e.getSource();
				calculator.setAge(source.getValue());
				calculator.setBmi();
//				calculator.setAlertState();
				ageValue.setText("" + calculator.getAge());
				bmiLabel.setText(df.format(calculator.getBmi()));
				messageLabel.setText(calculator.bmiMessage());
				BMI.messageColor(messageLabel, calculator.getAlertState());
			}	
		});
		

		
		panel_1.add(heightLabel);
		panel_1.add(heightSlider);
		panel_1.add(heightValue);
		panel_1.add(weightLabel);
		panel_1.add(weightSlider);
		panel_1.add(weightValue);
		panel_1.add(ageLabel);
		panel_1.add(ageSlider);
		panel_1.add(ageValue);
		
		panel_2.add(bmiLabel);
		panel_2.add(messageLabel);
		
		testGrid.add(panel_1);
		testGrid.add(panel_2);
		testGrid.pack();
		testGrid.setVisible(true);
	}
}

