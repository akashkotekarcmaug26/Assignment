import java.util.Scanner;

public class AreaR{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Length:");
        int length= sc.nextInt();

        System.out.println("Enter Width:");
        int Width= sc.nextInt();

        System.out.println("Area of Rectangle: "+(length*Width));
    }
}