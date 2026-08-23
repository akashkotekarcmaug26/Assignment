import java.util.Scanner;

public class P3{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Number");
        int num= sc.nextInt();
        int total=1;
        for(int i =1; i<=num;i++){
            total*=i;
        }
        System.out.println("Factorial of "+num+" is "+total);
            
    }
}