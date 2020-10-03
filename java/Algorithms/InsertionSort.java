import java.util.*;
class InsertionSort
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int a[];
        int i=0,j=0,n=0,l=0;
        System.out.println("Enter number of terms to sort");
        l=sc.nextInt();
        a=new int[l];
        System.out.println("Enter "+l+" numbers");
        for(i=0;i<l;i++)
        {
            a[i]=sc.nextInt();
        }
        for(i=1;i<l;i++)
        {
            n=a[i];
            for(j=i-1;j>=0;j--)
            {
                if(n<a[j])
                {
                    a[j+1]=a[j];
                }
            
                       else
                {
                    break;
                
                }
            }
            a[j+1]=n;
        }
        for(i=0;i<l;i++)
        {
            System.out.println(a[i]);
        }
    }
}