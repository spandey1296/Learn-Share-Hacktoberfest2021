/* java streams with filter functionality */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.stream.Collectors;

class Car {
	private String name;
	private String brand;
	
	public Car(String a, String b){
		this.name = a;
		this.brand = b;
	}
	
	public String getName(){
		return this.name;	
	}
	
	public String getBrand(){
		return this.brand;	
	}
}

class JavaStreamsExample2
{
	public static void main (String[] args) throws java.lang.Exception
	{
		
		List<Car> list = new ArrayList();
		
		list.add(new Car("beetle", "VW"));
		list.add(new Car("mustang", "Ford"));
		
		List<Car> filteredCars = list.stream().filter(car -> "VW".equals(car.getBrand()) ).collect(Collectors.toList());
		
		for(Car car : filteredCars){
			System.out.println(car.getName());
		}
	}
}



/**
Success	output :

beetle



*/
