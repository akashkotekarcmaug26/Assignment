import java.util.Scanner;

public class Problem_1{
    public static void main(String args[])
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
}