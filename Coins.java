/*
 * Tyler Jones 
 * Professor Murtz 
 * October 3rd
 * CS 38 Java Programming 
 */

/**
 *
 * @author Tyler
 */

package coins;
import java.util.Scanner;
public class Coins {
  
   public static void main(String[] args) {
     
   int quarters; // Number of quarters, to be input by the user.
   int dimes;    // Number of dimes, to be input by the user.
   int nickels;  // Number of nickels, to be input by the user.
   int pennies;  // Number of pennies, to be input by the user.
  
   //Scanner Object is used to get the input from the user.
   
   Scanner sc = new Scanner( System.in );
  
   double dollars; // Total value of all the coins, in dollars.
  
   /* Ask the user for the number of each type of coin. */
  
   System.out.print("Enter the number of quarters: ");
   quarters = sc.nextInt();
   sc.nextLine();
  
   System.out.print("Enter the number of dimes: ");
   dimes = sc.nextInt();
   sc.nextLine();
   
   System.out.print("Enter the number of nickels: ");
   nickels = sc.nextInt();
   sc.nextLine();
  
   System.out.print("Enter the number of pennies: ");
   pennies = sc.nextInt();
   sc.nextLine();
  
   /* Add up the values of the coins, in dollars. */
  
   dollars = (0.25 * quarters) + (0.10 * dimes)
   + (0.05 * nickels) + (0.01 * pennies);
  
   /* Display the Result */
  
   System.out.println();
   System.out.print( "The total in dollars is =" 
           + " $" + dollars + "\n" );
   }
}
