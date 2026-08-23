import java.util.Scanner;

public class Bonus{


void grade()
    {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Marks");

        System.out.println("Marks for Maths:");
        int maths=sc.nextInt();

        System.out.println("Marks for Science:");
        int sci=sc.nextInt();

        System.out.println("Marks for History:");
        int hist=sc.nextInt();

        int avg=(maths+sci+hist)/3;
        System.out.println("Average Marks: "+avg);

        if(avg >= 90)
            System.out.println("Grade: A");
        else if(avg >= 70 && avg <= 89 )
            System.out.println("Grade: B");
        else if(avg >= 50 && avg <= 69)
            System.out.println("Grade: C");
        else if(avg >= 30 && avg <= 49)
            System.out.println("Grade: D");
        else
            System.out.println("Grade: F");

    }



void leapYear()       
{ Scanner sc=new Scanner(System.in);
        System.out.println("Enter years:");
        int year= sc.nextInt();
        if((year%4==0 && year%100!=0) || year%400==0)
            System.out.println(year+" is a Leap Year");
        else
            System.out.println(year+" is not a Leap Year");
    }

void dayWeek() {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Day Number");
        int day_number= sc.nextInt();

        switch (day_number) {
            case 1:
                System.out.println("The Day is Monday");
                break;
            case 2:
                System.out.println("The Day is Tuesday");
                break;
            case 3:
                System.out.println("The Day is Wednesday");
                break;
            case 4:
                System.out.println("The Day is Thursday");
                break;
            case 5:
                System.out.println("The Day is Friday");
                break;
            case 6:
                System.out.println("The Day is Saturday");
                break;
            case 7:
                System.out.println("The Day is Sunday");
                break;
            default:
                System.out.println("Invalid Day NUmber");
                break;
        }
    }
    
void def() {
       byte a = 0;
        short b = 0;
        int c = 0;
        long d = 0L;
        float e = 0.0f;
        double f = 0.0;
        char g = '\u0000';
        boolean h = false;

        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        System.out.println(d);
        System.out.println(e);
        System.out.println(f);
        System.out.println(g);
        System.out.println(h);
    }

    
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter you Option: \n Option 1:Grade Evaluation System \n Option 2:Leap Year Check \n Option 3:Day of the Week \n Option 4:Identify default values of variables");
        int opt= sc.nextInt();

        Bonus obj = new Bonus();

        switch (opt) {
            case 1:
                obj.grade();
                break;
            case 2:
                obj.leapYear();
                break;
            case 3:
                obj.dayWeek();
                break;
            case 4:
                obj.def();
                break;
        
            default:
                System.out.println("Inavlid Option");
                break;
        }
    }
}