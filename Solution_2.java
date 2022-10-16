
/*
Sample Input
java 100
cpp 65
python 50

Your Output
================================
java           100
cpp            065
python         050
================================
*/


import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
            Scanner sc=new Scanner(System.in);
            System.out.println("================================");
            for(int i=0;i<3;i++)
            {
                String s1=sc.next();
                int x=sc.nextInt();
                //Complete this line
                String S1 = String.format("%-15s%03d" , s1 , x);
                System.out.println(S1);
            }
            System.out.println("================================");

    }
}
