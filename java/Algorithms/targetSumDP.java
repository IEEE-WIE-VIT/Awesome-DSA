import java.io.*;
import java.util.*;

//You are given a number n, representing the count of elements. You are given n numbers.
 //You are given a number "tar". You are required to calculate and print true or false, if there is a subset the elements of which add up to "tar" or not.
public class Main {
public static boolean targetsum(int[] arr,int t){
    boolean[][]dp = new boolean[arr.length + 1][t + 1];
    dp[0][0] = true;
    for(int i = 1 ; i < dp.length ; i++){

        for(int j = 0 ; j < dp[0].length ; j++){

            if(dp[i - 1][j] == true){

                dp[i][j] = true;
            }
            else if(j - arr[i-1] >= 0 && dp[i - 1][j - arr[i - 1]] == true){

                dp[i][j] = true;
            }
        }
    }
    return dp[dp.length - 1][dp[0].length - 1];
}
    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();

        int[]arr = new int[n];

        for(int i = 0;i<n;i++){

            arr[i] = scn.nextInt();

        }
        int t = scn.nextInt();

        System.out.print(targetsum(arr,t));
        
        /*  
        Sample Input : 
                        5
                        4
                        2
                        7
                        1
                        3
                        10
        sample outpuy: true
     */
                       
    }
}
