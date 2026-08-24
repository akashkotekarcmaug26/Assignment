import java.util.Scanner;

public class Problem_2 {

    String checkAgeacategory(int age){
        if(age >= 75)
            return "Senior Citizen";
        else if (age >= 18 && age < 75)
            return "Adult";
        else 
            return "Minor";
    }

    public static void main(String args[]){
        Scanner sc =new Scanner(System.in);
        System.out.println("Enter Age:");
        int age =sc.nextInt();

        Problem_2 obj =new Problem_2();

        System.out.println("You are "+obj.checkAgeacategory(age));
    }
    
}
