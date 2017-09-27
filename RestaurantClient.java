/*
 * @author Tyler Jones #388889
 * Professor Murtz
 * CS38 Java Programming 
 * October 20th 2016
 */
package resturantclient;

/**
 * Restaurant Client Application Class and Service Classes
 */

public class RestaurantClient{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
     
        
class Store
{
    String name;
    double taxrate = 1.0;
    Store (String n)
    {
        name = n;
    }
    public void setName(String n)
    {
        name = n;
    }
    public void setTaxRate(double t)
    {
        taxrate = t;
    }
    public String getName()
    {
        return name;
    }
    public double getTaxRate()
    {
        return taxrate;
    }
    public String toString()
    {
        return "Name: " + getName();
    }
    public boolean equals(Store s)
    {
        if(s.getName() == this.getName())
            return true;
        else
            return false;
    }
}
    
class Restaurant extends Store
{
    int noOfPeople;
    double avgCost;
    Restaurant(String nm,int n,double a)
    {
        super(nm);
        noOfPeople = n;
        avgCost    = a;
    }
    public void setNoOfPeople(int n)
    {
        noOfPeople = n;
    }
    public void setAvgCost(double a)
    {
        avgCost = a;
    }
    public int getNoOfPeople()
    {
        return noOfPeople;
    }
    public double getAvgCost()
    {
        return avgCost;
    }
    public double getAnnualTaxes()
    {
        return noOfPeople * avgCost * taxrate;
    }
    public String toString()
    {
        return "Name: " + super.getName() + "\nNo Of People: " + getNoOfPeople() + "\nAvg Cost of each person: " + getAvgCost();
    }
     public boolean equals(Restaurant r)
    {
        if(r.getName() == super.getName() && r.getNoOfPeople() == this.getNoOfPeople()&& r.getAvgCost() == this.getAvgCost())
        return true;
        else
        return false;
    }
}

        Restaurant res1 = new Restaurant ("Tasty",21,210);
        Restaurant res2 = new Restaurant ("Classy",11,111);
            res1.toString();
                res2.toString();
                res2.setAvgCost(210);
                res2.setNoOfPeople(21);
                
        if(res1.equals(res2))
            System.out.println("Both the restaurants are equal");
        else
            System.out.println("Both the restaurants aren't equal");
        
        res2.setName(res1.getName());
        
        if(res1.equals(res2))
            System.out.println("Both the restaurants are equal");
        else
            System.out.println("Both the restaurants aren't equal");
            System.out.println("The totat Annual Taxes: " + res1.getAnnualTaxes());
     }
}

