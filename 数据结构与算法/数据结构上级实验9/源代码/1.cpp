#include <stdio.h>

int findMaxInArray(int arr[], int n) {
	if (n == 1) {
		return arr[0];
	}
	int maxNubmer = findMaxInArray(arr, n - 1);
	return (arr[n - 1] > maxNubmer) ? arr[n - 1] : maxNubmer;
}

int main() {
	int n;
	printf("请输入数组的长度: ");
	scanf("%d", &n);
	
	int arr[n];
	printf("请输入 %d 个整数: ", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	int max = findMaxInArray(arr, n);
	printf("最大的元素是: %d\n", max);
	
	return 0;
}
