import java.util.*;
import java.io.*;

class DiamondPattern{
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int i,j,k=1;
for(i=1;i<=n;i++){
for(j=1;j<=k+1;j++){
System.out.print(" ");
}
k--;
for(j=1;j<=2*i-1;j++){
System.out.print("*");
}
System.out.println("");
}
k=1;
for(i=1;i<=n-1;i++){
for(j=1;j<=k;j++){
System.out.print(" ");
}
k++;
for(j=1;j<=2*(n-i)-1;j++){
System.out.print("*");
}
System.out.println("");
}
}
}