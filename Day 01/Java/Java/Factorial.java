import java.util.*;
class Factorial
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int num = Integer.parseInt(sc.nextLine());

        if (num < 0)
        {
            System.out.print("Cannot calculate factorial for negative number.");
        }
        else
        {
            int factorial = factorial(num);
            System.out.println("Factorial: " + factorial);
        }

        sc.close();
    }

    public static int factorial(int num)
    {
        int factorial = 1;
        
        int counter = num;
        while(counter > 1)
        {
            factorial = factorial * counter;
            counter--;
        }

        return factorial;
    }
}