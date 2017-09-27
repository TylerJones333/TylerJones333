//Tyler Jones
//Chemistry Course: Lab percentage is based on 4 labs worth up to 100 points each,
//and the classroom percentage is based on 2 problem sets worth up to 50 points each,
//and 2 exams worth up to 200 points each.

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


class Classes {
public:
    Classes(const char *, const char *);
    ~Classes();
    virtual float calcLab() const = 0;
    virtual float calcClassroom() const = 0;
    virtual float gradeAverage() const = 0;
    virtual void print() const;
    
private:
    char *firstName;
    char *lastName;  // dynamically allocated string
};

Classes::Classes(const char *first, const char *last) {
    firstName = new char[strlen(first) + 1];
    strcpy(firstName, first);
    lastName = new char[strlen(last) + 1];
    strcpy(lastName, last);
}

Classes::~Classes() {
    delete[] firstName;
    delete[] lastName;
}

void Classes::print() const {
    cout << firstName << ' ' << lastName;
}

void Classes::gradeAverage() const {
    float average = (calcLab + calcClassroom) / 2
    cout << average;
}



class chemistry : public Classes {};
class Physics : public Classes {};
class ComputerScience : public Classes {};
class Math : public Classes {};


class Chemistry: public Classes
{
public:
    Chemistry (const char*, float = 0.0)
    float calcPercentage const;
    void print() const;
private:
    float LabOne, LabTwo, LabThree, LabFour;
    float ProblemOne, ProblemTwo;
    float ExamOne, ExamTwo;
    float sumLab;
    float sumProb;
    float sumExam;
    float labGrade, classGrade, average;
};

Chemistry:: Chemistry (const char *f, const char *l, float s, float LOne, float LTwo, float LThree, float LFour, float POne, float PTwo, float EOne, float ETwo, )
    :Classes(f, l, c, cname)
{
    LabOne = LOne;
    LabTwo = LTwo;
    LabThree = LThree;
    LabFour = LFour;
    
    ProblemOne = POne;
    ProblemTwo = PTwo;
    
    ExamOne = EOne;
    ExamTwo = ETwo;
    

    sumLab = LabOne + LabTwo + LabThree + LabFour;
    sumProb = ProblemOne + ProblemTwo;
    sumExam = ExamOne + ExamTwo;
}

void Chemistry:: calcLab()
{
    labGrade = sumLab / 400 * 100;
}

void Chemistry:: calcClassroom()
{
    
    classGrade = (sumProb + sumExam) / 500 * 100;
    
}

void Chemistry:: calcAverage()
{
    average = (labgrade + classgrade) / 2;
    
}

int main()
{
    chemistry*
    ptr = new LabScore("Lenny". "Lilly", 400);
    ptr->print();
    cout << " Earned Grade" << ptr -> calcScore();
    delete ptr;
}
{
    ptr = new ProblemScore ("Paul", "Paloma", 100);
    ptr -> print();
    cout << "Earned Grade" << ptr -> calcScore();
    delete ptr;
{

    ptr = new ExamScores("Eric", "Erica",400);
    ptr -> print();
    cout << "Earned Grade" << ptr -> calcScore();
    delete ptr;
}
    ptr = new / TotalScores("Tod", "Tiffany", new / 400 + 100 + 400);
    ptr -> print();
    cout << "Earned Grade" << ptr -> calcScore();
    delete ptr;
    return 0;

/*
 
float Chemistry::calcScore() const
{ if (lab <= 100)
        return scores;
    return (
            }
            
            float average :: calcScore() const
                { if (problems <= 50)
                return score;
            return(
                   float average :: calcScore() const
    { if (exams <= 200)
        return scores;
    return(

class Test {
protected:
    int Lab, Exam;
public:
    chemistry ( int a=0, int b=0, int c=0, int d=0,)
    {
        Lab = a,b;
        Exam = c,d;
    }
    int area()
    {
        cout << "Enter Test Scores :" <<endl;
        return 0;
    }
};
class Lab: public Test{
public:
    Lab( int a=0, int b=0):Percent (a, b) { }
    int area ()
    {
        cout << "Enter Test 1 Score :" <<endl;
        return (width * height);
    }
};
class Exam: public Test{
public:
    Exam( int a=0, int b=0):Percent(a, b) { }
    int area ()
    {
        cout << "Score of Test two :" <<endl;
        return (width * height / 2);
    }
};
// Main function for the program
class Percentage: public Test{
public:
    Percentage( int a=0, int b=0):Shape(a, b) { }
    int area ()
    {
        cout << "Score of Test three :" <<endl;
        return (width * height / 2);
    }
};
class Percent: public Test{
public:
    Percent( int a=0, int b=0):Shape(a, b) { }
    int area ()
    {
        cout << "Score of Test four :" <<endl;
        return (width * height / 2);
    }
};*/

int main( )
{
    chemistry*
    ptr = new score("Jan". "Juilie",);
    ptr->print();
    cout << " Earned Grade" << ptr -> calcScore();
    delete ptr;
    ptr = new Score ("Jack", "Jill", 50, 200);
    ptr -> print();
    cout << "Earned Grade" << ptr -> calcScore();
    delete ptr;
    ptr = new / Student("Jake", "Jannet", 50, 200);
    ptr -> prit();
    cout << "Earned Grade" << ptr -> calcScore();
    delete ptr;
    return 0;
}
    /*
    Percentage *Percentage;
    ScoreOne one(50);
    ScoreTwo two(200);
    ScoreThree three(50);
    ScoreFour four(200);
    
    // store the address of Test1
    Percent = TestOnec;
    // call average percentage of Test1.
    Percent->average();
    
    // store the address of Test2
    percent = Test2;
    // call average percentage of Test2.
    percent->areage();
    
    // store the address of Test3
    percent = Test3;
    // call average percentage of Test3.
    percent->areage();
   
    // store the address of Test4
    percent = Test4;
    // call average percentage of Test4.
    percent->areage();
    return 0;*/









