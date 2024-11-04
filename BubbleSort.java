/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bubblesort;


import java.util.Scanner;

/**
 *
 * @author USER
 */
public class BubbleSort {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
    Scanner input = new Scanner(System.in);
        System.out.print("enter how many number you want to sort:");
    int n = input.nextInt();
    int []arr;
        arr = new int[n];
    for(int i=0;i<n;i++){
    arr[i] = input.nextInt();
    }   
    for (int i = 0; i < arr.length-1; i++){
            for (int j=0;j<arr.length-i-1; j++){    
            if(arr[j]> arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            } 
        }
    }for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");
        }
    
}
}