import java.util.*;

public class TwoPointersAlgo {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] a= new int[5];
		boolean sum = false;
		for(int i=0; i<5; i++)
		{
			a[i]=sc.nextInt();
		}
		Arrays.sort(a);
		for(int i=0 ; i<3 ; i++)
		{
			if(TwoSum(a, -a[i], i+1))
			{
				sum = true;
			}
		}
		System.out.println(sum);
	}

	public static boolean TwoSum(int a[], int x, int i)
	{
		int j = a.length-1;
		while(i<j)
		{
			if(a[i]+a[j]<x)
			{
				i++;
			}
			else if(a[i]+a[j]>x)
			{
				j--;
			}
			else 
			{
				return true;
			}
		}
		return false;
	}
}