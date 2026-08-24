import java.util.Scanner;

public class Problem_6 {
    
    int calculateSum(int num){
        
        int total=0;
        for(int i=0;i<=num;i++){
            total+=i;
        }
        return total;

    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number");
        int num=sc.nextInt();

        Problem_6 obj=new Problem_6();
        System.out.println("Sum of Number from 1 to "+num+" is "+obj.calculateSum(num));
}
}
