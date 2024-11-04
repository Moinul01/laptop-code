/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gradesystem;

import java.util.Scanner;

/**
 *
 * @author user
 */
public class GradeSystem {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.println("Enter marks");
        Scanner input = new Scanner(System.in);
        int n  = input.nextInt();
        if(n>80){
      System.out.println("A");
    }else if(n>60 && n<=80){      
        System.out.println("B");
    }else if(n>50 && n<=60){
        System.out.println("C");
    }else if(n>45 && n<=50){
        System.out.println("D");
    }
    else if(n>=25 && n<=45){
        System.out.println("E");
    }
    else if(n<25){
        System.out.println("F");
    }
    
    
    
}}

