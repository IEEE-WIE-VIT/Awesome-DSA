import java.util.*;
class Bubble_Sort
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the no. of cells of the array:");
        int len=sc.nextInt();
        int bubble[]=new int[len];
        //Initializing the array
        for(int i=0;i<len;++i)
        {
            System.out.println("Enter a no.:");
            bubble[i]=sc.nextInt();
        }
        //Bubble Sort
        for (int i = 0; i < len-1; i++)
        {
            for (int j = 0; j < len-i-1; j++)
            {
                if (bubble[j] > bubble[j+1])
                {
                    int t = bubble[j];
                    bubble[j] = bubble[j+1];
                    bubble[j+1] = t;
                }
            }
        }
        //Printing the sorted array
        for(int i=0;i<len;++i)
            System.out.println(bubble[i]+"\t");
    }
}