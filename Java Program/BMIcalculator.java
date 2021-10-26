/*Body mass index (BMI) is a value derived from the mass (weight) and height of a person.
 *  The BMI is defined as the body mass divided by the square of the body height, and is expressed in units of kg/m2, resulting from mass in kilograms and height in metres.
 *  The BMI is a convenient rule of thumb used to broadly categorize a person as underweight, normal weight, overweight,
 */

import java.util.Scanner;
public class BMIcalculator{

public static void main(String args[]){
	
Scanner sc=new Scanner(System.in);
System.out.println("Enter your Height(in cm) ");
//taking height input from user
double height=sc.nextInt();
height=height/100;

System.out.println("Enter your Weight(in kg) ");
//taking weight input from user
int weight=sc.nextInt();
//calculating BMI
double bmi=weight/(height*height);

if(bmi<18.5)
{
    System.out.println("Your BMI is "+bmi);
    System.out.println("You are underweight!! ");
}
else if(bmi>=18.5 && bmi<25){

    System.out.println("Your BMI is "+bmi);
    System.out.println("You have normal weight!!....:) ");
}
else if(bmi>=25){
 System.out.println("Your BMI is "+bmi);
 System.out.println("You are overweight!! ");

}

}

}