import java.util.*;
class Palindrome
{
    public static void main(String[] args)

    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Type a text: ");
        String text = sc.nextLine();

        char[] textreverse = text.toCharArray();

        for (int i = 0, j = text.length() - 1; i < text.length(); i++, j--)
        {
            textreverse[i] = text.charAt(j);
        }

        String reversed = new String(textreverse);

        if (text.equals(reversed))
        {
          System.out.print("Text is palindrome.");
        }
        else
        {
            System.out.print("Text is not palindrome.");
        }

        sc.close();
    }
}