#include <stdio.h>

void nhapMang(int arr[10][10], int *n) {
    printf("Nhap kich co mang (n x n): ");
    scanf("%d", n);
    printf("Nhap gia tri cac phan tu cua mang:\n");
    int i,j;
    for (i = 0; i < *n; i++) {
        for (j = 0; j < *n; j++) {
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void inMang(int arr[10][10], int n) {
    printf("Gia tri cac phan tu cua mang:\n");
    int i;
    for (i = 0; i < n; i++) {
    	int j;
        for (j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void inLeTinhTong(int arr[10][10], int n) {
    int tong = 0;
    printf("Cac phan tu le trong mang: ");
    int i;
    for (i = 0; i < n; i++) {
    	int j;
        for (j = 0; j < n; j++) {
            if (arr[i][j] % 2 != 0) {
                printf("%d ", arr[i][j]);
                tong += arr[i][j];
            }
        }
    }
    printf("\nTong cac phan tu le: %d\n", tong);
}

void inDuongBienTinhTich(int arr[10][10], int n) {
    int tich = 1;
    printf("Cac phan tu tren duong bien: ");
    int i;
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[0][i]); 
        tich *= arr[0][i];
        printf("%d ", arr[n-1][i]); 
        tich *= arr[n-1][i];
    }
    for (i = 1; i < n-1; i++) {
        printf("%d ", arr[i][0]); 
        tich *= arr[i][0];
        printf("%d ", arr[i][n-1]); 
        tich *= arr[i][n-1];
    }
    printf("\nTich cac phan tu duong bien: %d\n", tich);
}

void inDuongCheoChinh(int arr[10][10], int n) {
    printf("Cac phan tu tren duong cheo chinh: ");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i][i]);
    }
    printf("\n");
}

void inDuongCheoPhu(int arr[10][10], int n) {
    printf("Cac phan tu tren duong cheo phu: ");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i][n-i-1]);
    }
    printf("\n");
}

void inDauDaiMax(int arr[10][10], int n) {
    int maxTong = -1;
    int index = -1;
    int i;
    for (i = 0; i < n; i++) {
        int tong = 0;
        int j;
        for (j = 0; j < n; j++) {
            tong += arr[i][j];
        }
        if (tong > maxTong) {
            maxTong = tong;
            index = i;
        }
    }
    printf("Dòng có t?ng l?n nh?t là dòng %d v?i t?ng = %d\n", index+1, maxTong);
}

int main() {
    int arr[10][10], n;
    int choice;
    
    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In gia tri cac phan tu le va tinh tong\n");
        printf("4. In ra cac phan tu tren duong bien va tinh tich\n");
        printf("5. In ra cac phan tu tren duong cheo chinh\n");
        printf("6. In ra cac phan tu tren duong cheo phu\n");
        printf("7. In ra dòng có t?ng giá tr? các ph?n t? là l?n nh?t\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                inMang(arr, n);
                break;
            case 3:
                inLeTinhTong(arr, n);
                break;
            case 4:
                inDuongBienTinhTich(arr, n);
                break;
            case 5:
                inDuongCheoChinh(arr, n);
                break;
            case 6:
                inDuongCheoPhu(arr, n);
                break;
            case 7:
                inDauDaiMax(arr, n);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
    
    return 0;
}
