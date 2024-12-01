#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int array[MAX_SIZE];
int size = 0;
int i;
void inputArray() {
    printf("Nh?p s? lu?ng ph?n t? (t?i da %d): ", MAX_SIZE);
    scanf("%d", &size);
    if (size > MAX_SIZE || size < 1) {
        printf("S? lu?ng ph?n t? không h?p l?!\n");
        size = 0;
        return;
    }
    printf("Nh?p các ph?n t?:\n");
    for (i = 0; i < size; i++) {
        printf("Ph?n t? [%d]: ", i);
        scanf("%d", &array[i]);
    }
}

void displayArray() {
    if (size == 0) {
        printf("M?ng tr?ng!\n");
        return;
    }
    printf("M?ng hi?n t?i: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void addElement() {
    if (size >= MAX_SIZE) {
        printf("M?ng dã d?y, không th? thêm ph?n t?!\n");
        return;
    }
    int value;
    printf("Nh?p giá tr? ph?n t? c?n thêm: ");
    scanf("%d", &value);
    array[size++] = value;
    printf("Thêm thành công!\n");
}

void editElement() {
    int index, value;
    printf("Nh?p v? trí ph?n t? c?n s?a (0-%d): ", size - 1);
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("V? trí không h?p l?!\n");
        return;
    }
    printf("Nh?p giá tr? m?i: ");
    scanf("%d", &value);
    array[index] = value;
    printf("S?a thành công!\n");
}

void deleteElement() {
    int index;
    printf("Nh?p v? trí ph?n t? c?n xóa (0-%d): ", size - 1);
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("V? trí không h?p l?!\n");
        return;
    }
    for (i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    printf("Xóa thành công!\n");
}

void menu() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nh?p vào m?ng\n");
        printf("2. Hi?n th? m?ng\n");
        printf("3. Thêm ph?n t?\n");
        printf("4. S?a ph?n t?\n");
        printf("5. Xóa ph?n t?\n");
        printf("6. Thoát\n");
        printf("L?a ch?n c?a b?n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray();
                break;
            case 2:
                displayArray();
                break;
            case 3:
                addElement();
                break;
            case 4:
                editElement();
                break;
            case 5:
                deleteElement();
                break;
            case 6:
                printf("Thoát chuong trình.\n");
                break;
            default:
                printf("L?a ch?n không h?p l?!\n");
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}
