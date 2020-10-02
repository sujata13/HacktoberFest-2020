/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package revesralof.sentence;

/**
 *
 * @author shubhendu
 */
import java.util.Scanner;
public class RevesralofSentence {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
         
       Scanner read=new Scanner(System.in);
        String s="",s1="",s2="";
        
        char ch;
        int i,l,k;
        System.out.println("enter a sentence");
        s=read.nextLine();
        s=s+" ";
        l=s.length();
        int j=0;
        for(i=0;i<=l-1;i++)
        {
            ch=s.charAt(i);
            if(ch==' ')
            {
                k=i;
                s1=s.substring(j,k+1);
                j=k;
                s2=s1+s2;
            }
            }
         System.out.println(s2);
    }
}
        
    