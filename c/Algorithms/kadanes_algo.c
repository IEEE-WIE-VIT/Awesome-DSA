#include <stdio.h>
#include <limits.h>

int max_subarray_sum(int* arr, int n) {
	int max_so_far = INT_MIN;
	int current_max = 0;

	for (int i = 0; i < n; i++) {
		current_max += arr[i];

		if (current_max > max_so_far) {
			max_so_far = current_max;
		}

		if (current_max < 0) {
			current_max = 0;
		}
	}

	return max_so_far;
}

int main() {
	int n;
	scanf("%d", &n);

	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	printf("%d \n", max_subarray_sum(arr, n));

	return 0;
}
