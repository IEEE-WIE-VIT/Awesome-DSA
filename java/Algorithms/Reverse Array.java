import java.util.*;
class reverseArray { 

	/* function that reverses array and stores it 
	in another array*/
	public static void reverse(int a[], int n) 
	{ 
		int[] b = new int[n]; 
		int j = n; 
		for (int i = 0; i < n; i++) { 
			b[j - 1] = a[i]; 
			j = j - 1; 
		} 

		/*printing the reversed array*/
		System.out.println("Reversed array is:"); 
		for (int k = 0; k < n; k++) { 
			System.out.print(b[k]); 
		} 
	} 

	public static void main(String[] args) 
	{ 
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter no. of array element :");
        int n=sc.nextInt();
		int ar[]=new int[n];
        System.out.println("Enter array elements: ");
        for(int i=0;i<n;i++)
        {
              ar[i]=sc.nextInt();
        } 
		reverse(ar, n); 
	} 
} 
