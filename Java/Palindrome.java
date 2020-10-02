import java.util.*;
public class Palindrome{
    public static void main(String args[]){
          int i,j;
         String word=new String();
        System.out.println("Enter the string");
        Scanner name= new Scanner(System.in);
        word=name.next();
        char array[]=new char[word.length()];
        boolean flag=false;
        for(int a=0;a<word.length();a++){
            array[a]=word.charAt(a);
        }
        for(i=0,j=array.length-1;i<j;i++,j--)
        {
            if(array[i]!=array[j]){
                flag=false;
                System.out.println(word+ " is not palindrome");
                break;
                
            }
            else{
                flag=true;
            }
        }

      if(flag==true){
        System.out.println(word+ " is  palindrome");
      }
    }
}