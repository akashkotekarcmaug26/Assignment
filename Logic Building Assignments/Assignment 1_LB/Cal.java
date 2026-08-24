import java.util.Scanner;

public class Cal{
    public static void main (String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter  number :");
        int num1 = sc.nextInt();

        System.out.println("Enter Number:");
        int num2 = sc.nextInt();

        System.out.println("Enter operator:");
        String op=sc.next();

        switch (op){
            case "+":
                System.out.println(num1+num2);
                break;
            case "-":
                System.out.println(num1-num2);
                break;
            default:
                System.out.println("Invalid");
                break;
        }
}
}