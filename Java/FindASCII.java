import java.util.*;
import java.io.*;

class FindASCII{
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
char c = sc.next().charAt(0);
int ascii = c;
System.out.println("ASCII Value of " +c+" = "+ascii);
}
}