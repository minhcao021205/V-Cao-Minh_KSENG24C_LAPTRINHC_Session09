#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int currentLength = 0;
    int n, addIndex, addValue;
    int i;
    printf("Nhap so phan tu ban dau (toi da %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n < 0 || n > MAX_SIZE) {
        printf("So phan tu khong hop le!\n");
        return 1;
    }

    printf("Nhap %d phan tu:\n", n);
    for (i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    currentLength = n;

    printf("Nhap gia tri can them: ");
    scanf("%d", &addValue);
    printf("Nhap vi tri can them (0 den %d): ", MAX_SIZE - 1);
    scanf("%d", &addIndex);

    if (addIndex < 0 || addIndex >= MAX_SIZE) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }

    if (addIndex >= currentLength) {
        arr[addIndex] = addValue;
        currentLength = addIndex + 1;
    } else {
	for (i = currentLength; i > addIndex; i--) {
            arr[i] = arr[i - 1];
        }
        arr[addIndex] = addValue;
        currentLength++;
    }

    printf("Mang sau khi them: ");
    for (i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
