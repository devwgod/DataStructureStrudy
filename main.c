#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num;
	scanf_s("%d", &num);
	int *arr = (int*)malloc(num * sizeof(int));

	int n;
	for (n = 0; n < num; n++) {
		scanf_s("%d", &arr[n]);
	}

	int i, j;
	int temp;
	for (int i = 0; i < num - 1; i++) {
		for (j =i+1 ;j<num;j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (n = 0; n < num; n++) {
		printf("%d ", arr[n]);
	}
}