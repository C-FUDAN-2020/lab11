#include <stdio.h>
#define N 9

void print_matrix(int matrix[][N]) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

int main () {
	int a[N][N];
	int top = 0, bottom = N - 1, left = 0, right = N - 1;
	
	int num = 1;
	
	while (left <= right && top <= bottom) {
		if (left == right && top == bottom) {
			a[top][left] = num++;
		} else if (left == right) {
			for (int i = top; i < bottom; i++) {
				a[i][right] = num++;
			}
		} else if (top == bottom) {
			for (int i = left; i < right; i++) {
				a[top][i] = num++;
			}
		} else {
			for (int i = left; i < right; i++) {
				a[top][i] = num++;
			}
			for (int i = top; i < bottom; i++) {
				a[i][right] = num++;
			}
			for (int i = right; i > left; i--) {
				a[bottom][i] = num++;
			}
			for (int i = bottom; i > top; i--) {
				a[i][left] = num++;
			}
		}
		left++;
		right--;
		top++;
		bottom--;
	}
	
	print_matrix(a);
	return 0;
}
