/*
* Tyler Jones
* Professor Murtz
* CS 38 Java Progamming 
* December 4 2016
*/

import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;

class CarPlate
{
int carPlateNumber;
String state;
String color;
static int numobjects;
CarPlate(int carPlateNumber,String state,String color)
{
this.carPlateNumber=carPlateNumber;
this.state=state;
this.color=color;
numobjects++;
}
@Override
public String toString()
{
return carPlateNumber+","+state+","+color;
}
}
public class CarPlateTest
{
public static void main(String[] args)
{
//Instantiating the car plate objects
CarPlate cp1=new CarPlate(1111, "Earth", "blue");
CarPlate cp2=new CarPlate(2222, "Wind", "blue");
CarPlate cp3=new CarPlate(3333, "Fire", "blue");
System.out.println("Number of objects Created :" + CarPlate.numobjects);
  
//Writing objects into a file
try
{
System.out.println("Writing objects to a file");
System.out.println("------------------");

File outputFile=new File("D:\\samples.txt");
if (!outputFile.exists()) {
System.out.println("Creating New file output doesnot exist RECREATING FILE");
outputFile.createNewFile();
}
FileOutputStream f = new FileOutputStream(outputFile);
ObjectOutput s = new ObjectOutputStream(f);
s.writeObject(cp1.toString());
s.writeObject(cp2.toString());
s.writeObject(cp3.toString());
s.flush();
//fetching the objects from file and EOFEception is thrown
System.out.println("Reading objects from file");
System.out.println("------------------");
FileInputStream fis = new FileInputStream("D:\\samples.txt");
ObjectInputStream ois = new ObjectInputStream(fis);
int i=1;
while(true)
{
System.out.println(ois.readObject().toString()+" object"+i++);
}

}
catch(FileNotFoundException e)
{
System.out.println("File Not Found Exception");
}
catch(EOFException e)
{
System.out.println("Reached End of File");
}
catch(IOException e)
{
System.out.println("IO Exception");
}
catch(ClassNotFoundException e)
{
System.out.println("c");
}
  
}
}

