import java.util.Scanner;

public class Problem_5 {


    void printMultiplicationTable(int num){
         for(int i =1; i<=10;i++){
            System.out.println(num+" x "+i+" = "+num*i);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Number");
        int num = sc.nextInt();

        Problem_5 obj = new Problem_5();
        obj.printMultiplicationTable(num);
      
    }
}
