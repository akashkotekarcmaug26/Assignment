import java.util.Scanner;

public class P2{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Number");
        int num= sc.nextInt();
        for(int i =0; i<=num-3;)
            System.out.print((i+=3)+" " );
            
    }
}