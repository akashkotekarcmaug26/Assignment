import java.util.Scanner;

public class Problem_4 {


    void askForpositiveNumber()
    {
        Scanner sc= new Scanner(System.in);
        int num;

        do{
            System.out.println("Enter Number");
            num=sc.nextInt();

        } while(num%2!=0);
        System.out.println("You have entered Positive Number "+num);
    }
 public static void main(String[] args) {
    
    Problem_4 obj= new Problem_4();
    obj.askForpositiveNumber();

 }
}
