package Java;

public class ModularExponentiation {

    static int modulo(int a, int b, int c) {
        long x = 1;
        long y = a;
        while (b > 0) {
            if (b % 2 == 1) {
                x = (x * y) % c;
            }
            y = (y * y) % c; // squaring the base
            b /= 2;
        }
        return (int) x % c;
    }

    // Driver Program to test above functions
    public static void main(String args[]) {
        int x = 5;
        int y = 35;
        int p = 135;
        System.out.println("Power is " + modulo(x, y, p));
    } 
}
