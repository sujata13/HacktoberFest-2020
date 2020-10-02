package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// TO FIND THE AREA OR PERIMETER OF THE CIRCLE

        Scanner scan = new Scanner(System.in);
        System.out.println("ENTER 1 FOR AREA OF CIRCLE AND 2 FOR CIRCUMFERENCE OF CIRCLE : ");
        int input = scan.nextInt();

        if (input == 1) {
            System.out.println("ENTER RADIUS OF THE CIRCLE : ");
            float r = scan.nextFloat();
            float a = (float)(3.14*r*r);
            System.out.println("AREA OF CIRCLE IS "+a);
        }else{
            System.out.println("ENTER RADIUS OF THE CIRCLE : ");
            float r = scan.nextFloat();
            float a = (float)(2*3.14*r);
            System.out.println("CIRCUMFERENCE OF CIRCLE IS "+a);}
    }
}
