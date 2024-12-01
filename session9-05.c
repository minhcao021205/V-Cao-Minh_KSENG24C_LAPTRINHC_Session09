#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n < 2) return false;
    int i;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void printMenu() {
    printf("\nMENU\n");
    printf("1. Nh?p s? ph?n t? c?n nh?p v� gi� tr? c�c ph?n t?\n");
    printf("2. In ra gi� tr? c�c ph?n t? dang qu?n l�\n");
    printf("3. In ra gi� tr? c�c ph?n t? ch?n v� t�nh t?ng\n");
    printf("4. In ra gi� tr? l?n nh?t v� nh? nh?t trong m?ng\n");
    printf("5. In ra c�c ph?n t? l� s? nguy�n t? trong m?ng v� t�nh t?ng\n");
    printf("6. Nh?p v�o m?t s? v� th?ng k� trong m?ng c� bao nhi�u ph?n t? d�\n");
    printf("7. Th�m m?t ph?n t? v�o v? tr� ch? d?nh\n");
    printf("8. Tho�t\n");
    printf("L?a ch?n c?a b?n: ");
}

int main() {
    int *arr = NULL;
    int n = 0;
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Nh?p s? ph?n t?: ");
                scanf("%d", &n);
                arr = (int *)malloc(n * sizeof(int));
                printf("Nh?p gi� tr? c�c ph?n t?:\n");
                int i;
                for (i = 0; i < n; i++) {
                    printf("Ph?n t? %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            }
            case 2: {
                if (arr == NULL) {
                    printf("M?ng chua du?c kh?i t?o!\n");
                } else {
                    printf("C�c ph?n t? trong m?ng: ");
                    int i;
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
                if (arr == NULL) {
                    printf("M?ng chua du?c kh?i t?o!\n");
                } else {
                    int sum = 0;
                    printf("C�c ph?n t? ch?n: ");
                    int i;
                    for (i = 0; i < n; i++) {
                        if (arr[i] % 2 == 0) {
                            printf("%d ", arr[i]);
                            sum += arr[i];
                        }
                    }
                    printf("\nT?ng c�c ph?n t? ch?n: %d\n", sum);
                }
                break;
            }
            case 4: {
                if (arr == NULL) {
                    printf("M?ng chua du?c kh?i t?o!\n");
                } else {
                    int max = arr[0], min = arr[0];
                    int i;
                    for (i = 1; i < n; i++) {
                        if (arr[i] > max) max = arr[i];
                        if (arr[i] < min) min = arr[i];
                    }
                    printf("Gi� tr? l?n nh?t: %d\n", max);
                    printf("Gi� tr? nh? nh?t: %d\n", min);
                }
                break;
            }
            case 5: {
                if (arr == NULL) {
                    printf("M?ng chua du?c kh?i t?o!\n");
                } else {
                    int sum = 0;
                    printf("C�c ph?n t? l� s? nguy�n t?: ");
                    int i;
                    for (i = 0; i < n; i++) {
                        if (isPrime(arr[i])) {
                            printf("%d ", arr[i]);
                            sum += arr[i];
                        }
                    }
                    printf("\nT?ng c�c s? nguy�n t?: %d\n", sum);
                }
                break;
            }
            case 6: {
                if (arr == NULL) {
                    printf("M?ng chua du?c kh?i t?o!\n");
                } else {
                    int x, count = 0;
                    printf("Nh?p gi� tr? c?n th?ng k�: ");
                    scanf("%d", &x);
                    int i;
                    for (i = 0; i < n; i++) {
                        if (arr[i] == x) count++;
                    }
                    printf("S? l?n xu?t hi?n c?a %d: %d\n", x, count);
                }
                break;
            }
            case 7: {
                if (arr == NULL) {
                    printf("M?ng chua du?c kh?i t?o!\n");
                } else {
                    int pos, value;
                    printf("Nh?p v? tr� (0-%d): ", n);
                    scanf("%d", &pos);
                    printf("Nh?p gi� tr? ph?n t?: ");
                    scanf("%d", &value);

                    if (pos < 0 || pos > n) {
                        printf("V? tr� kh�ng h?p l?!\n");
                    } else {
                        arr = (int *)realloc(arr, (n + 1) * sizeof(int));
                        int i;
                        for (i = n; i > pos; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[pos] = value;
                        n++;
                        printf("�� th�m ph?n t?.\n");
                    }
                }
                break;
            }
            case 8: {
                printf("Tho�t chuong tr�nh.\n");
                break;
            }
            default: {
                printf("L?a ch?n kh�ng h?p l?. Vui l�ng th? l?i.\n");
            }
        }
    } while (choice != 8);

    free(arr);
    return 0;
}
