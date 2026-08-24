import java.util.Scanner;

public class LargestOf3{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 3 numbers:");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

       System.out.println("Largest of 3 numbers: "+(a>b?(a>c?a:c):(b>c?b:c)));
    }
}