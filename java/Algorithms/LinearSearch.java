import java.util.*;
class Linear_Search
{
   public static void main(String args[])
   {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the no. of cells of the array:");
        int len=sc.nextInt();
        int linear[]=new int[len];
        System.out.println("Enter the no. to be searched:");
        int n=sc.nextInt();
        boolean flag=false;
        
        //Inputting data in the array
        
        for(int i=0;i<len;++i)
        {
            System.out.println("Enter a no.:");
            linear[i]=sc.nextInt();
        }
        
        //Linear Search Implementation
        
        Linear_Search obj=new Linear_Search();
        for(int i=0;i<len;++i)
        {
            if(linear[i]==n)
            {
                obj.display(n,i);
                System.exit(0);
            }
        }
        System.out.println("Search unsuccessful");
    }
        
    public void display(int n,int i)
    {
        System.out.println("Search successful as "+n+" was found at position "+(i+1));
    }
}