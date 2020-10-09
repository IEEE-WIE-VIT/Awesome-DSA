import java.util.*;
class Selection_Sort
{
   public static void main(String args[])
   {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the no. of cells of the array:");
        int len=sc.nextInt();
        int select[]=new int[len];
        
        //Inputting data in the array
        
        for(int i=0;i<len;++i)
        {
            System.out.println("Enter a no.:");
            select[i]=sc.nextInt();
        }
        
        //Selection Sort Implementation
        
        for(int i=0;i<len;++i)
        {
            int minimum=i;
            for(int j=i+1;j<len;++j)
            {
                if(select[j]<select[minimum])
                    minimum=j;
            }
            int temp=select[minimum];
            select[minimum]=select[i];
            select[i]=temp;
        }
        
        //Printing the sorted array
        
        System.out.println("The sorted array is:\n");
        for(int i=0;i<len;++i)
            System.out.println(select[i]+"\t");
    }
}
        