import java.util.Scanner;

public class P5{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Number");
        int num= sc.nextInt();
        int sum=0;
        for(int i =1; i<=num;){
            sum+=i;
            i=i+2;
        }
        System.out.println("Sum of Odd NUmbers "+sum);
    }
    
}