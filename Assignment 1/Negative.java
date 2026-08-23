import java.util.Scanner;

public class Negative {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");

        int num = sc.nextInt();
        if (num < 0) {
            System.out.println("The number is negative");
        } 
         else {
            System.out.println("The number is not negative");
        }
        
    }
}
