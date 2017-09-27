import java.util.*;


 class Course_Grade
{
    private String Course_Name;
    private char letter_grade;
    public Course_Grade()
    {
	setCourse_Name(" ");
	}
    public Course_Grade(String name,char letter)
	{
	setCourse_Name(name);
	setLetter_grade(letter);
	}
    /**
     * @return the Course_Name
     */
    public String getCourse_Name() {
        return Course_Name;
    }
 
    /**
     * @param Course_Name the Course_Name to set
     */
    public void setCourse_Name(String Course_Name) {
        this.Course_Name = Course_Name;
    }
 
    /**
     * @return the letter_grade
     */
    public char getLetter_grade() {
        return letter_grade;
    }
 
    /**
     * @param letter_grade the letter_grade to set
     */
    public void setLetter_grade(char letter_grade) {
        this.letter_grade = letter_grade;
    }
    public String toString()
    {
        return Course_Name + " Has letter grade " + letter_grade;
    }
    public boolean equals(Course_Grade CG)
    {
        return (CG.letter_grade == letter_grade && Course_Name.equalsIgnoreCase(CG.Course_Name));
    }
}
class test
{
public static void main(String[] args)
{
Course_Grade CG1 = new Course_Grade("Electronics",'A');
Course_Grade CG2 = new Course_Grade("Image Procession",'C');
System.out.println(CG1);
System.out.println(CG2);
System.out.println("is Course 1 is equal to Course 2 ? " + CG1.equals(CG2));
}
}
