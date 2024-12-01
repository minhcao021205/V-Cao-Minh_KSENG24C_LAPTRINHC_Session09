#include <stdio.h>

int main() {
    int arr[100];
    int n, index, currentLength;
    int i;
    printf("Nhap so phan tu muon nhap (toi da 100): ");
    scanf("%d", &n);

    if (n > 100 || n <= 0) {
        printf("So phan tu khong hop le!\n");
        return 1;
    }

    currentLength = n;

    printf("Nhap cac phan tu cua mang:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhap vi tri can xoa (0-%d): ", currentLength - 1);
    scanf("%d", &index);

    if (index < 0 || index >= currentLength) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }

    for (i = index; i < currentLength - 1; i++) {
        arr[i] = arr[i + 1];
    }

    currentLength--;

    printf("Mang sau khi xoa:\n");
    for (i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
