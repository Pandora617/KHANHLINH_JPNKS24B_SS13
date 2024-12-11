#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[100]; 
    int n = 0;
    int choice, subChoice, x, viTri;

    void nhapMang(int arr[], int *n) {
        printf("Nhap so phan tu can nhap (toi da 100): ");
        scanf("%d", n);
        if (*n > 100) *n = 100;
        
        for (int i = 0; i < *n; i++) {
            printf("Nhap gia tri cho arr[%d]: ", i + 1);
            scanf("%d", &arr[i]);
        }
    }

    void inMang(int arr[], int n) {
        printf("Cac phan tu trong mang:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    void themPhanTu(int arr[], int *n) {
        if (*n >= 100) {
            printf("Mang da day, khong the them phan tu.\n");
            return;
        }

        int viTri, giaTri;
        printf("Nhap vi tri can them (1 den %d): ", *n + 1);
        scanf("%d", &viTri);
        printf("Nhap gia tri can them: ");
        scanf("%d", &giaTri);

        if (viTri < 1 || viTri > *n + 1) {
            printf("Vi tri khong hop le.\n");
            return;
        }

        for (int i = *n; i >= viTri; i--) {
            arr[i] = arr[i - 1];
        }
        arr[viTri - 1] = giaTri;
        (*n)++;
    }

    void suaPhanTu(int arr[], int n) {
        int viTri, giaTri;
        printf("Nhap vi tri phan tu can sua (1 den %d): ", n);
        scanf("%d", &viTri);
        if (viTri < 1 || viTri > n) {
            printf("Vi tri khong hop le.\n");
            return;
        }

        printf("Nhap gia tri moi: ");
        scanf("%d", &giaTri);
        arr[viTri - 1] = giaTri;
    }

    void xoaPhanTu(int arr[], int *n) {
        int viTri;
        printf("Nhap vi tri phan tu can xoa (1 den %d): ", *n);
        scanf("%d", &viTri);
        
        if (viTri < 1 || viTri > *n) {
            printf("Vi tri khong hop le.\n");
            return;
        }

        for (int i = viTri - 1; i < *n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*n)--;
    }

    void sapXepMang(int arr[], int n, int luaChon) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((luaChon == 1 && arr[i] < arr[j]) || (luaChon == 2 && arr[i] > arr[j])) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    int timKiemTuyenTinh(int arr[], int n, int x) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                return i;
            }
        }
        return -1;
    }

    int timKiemNhiPhan(int arr[], int n, int x) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                return mid;
            } else if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("   a. Giam dan\n");
        printf("   b. Tang dan\n");
        printf("7. Tim kiem phan tu\n");
        printf("   a. Tim kiem tuyen tinh\n");
        printf("   b. Tim kiem nhi phan\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                inMang(arr, n);
                break;
            case 3:
                themPhanTu(arr, &n);
                break;
            case 4:
                suaPhanTu(arr, n);
                break;
            case 5:
                xoaPhanTu(arr, &n);
                break;
            case 6:
                printf("Chon sap xep:\n");
                printf("a. Giam dan\n");
                printf("b. Tang dan\n");
                printf("Nhap lua chon (1: Giam dan, 2: Tang dan): ");
                scanf("%d", &subChoice);
                sapXepMang(arr, n, subChoice);
                break;
            case 7:
                printf("Chon tim kiem:\n");
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                printf("Nhap lua chon (1: Tuyen tinh, 2: Nhi phan): ");
                scanf("%d", &subChoice);
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                if (subChoice == 1) {
                    viTri = timKiemTuyenTinh(arr, n, x);
                } else if (subChoice == 2) {
                    viTri = timKiemNhiPhan(arr, n, x);
                }
                if (viTri != -1) {
                    printf("Phan tu %d duoc tim thay tai vi tri %d\n", x, viTri + 1);
                } else {
                    printf("Phan tu %d khong ton tai trong mang\n", x);
                }
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 8);

    return 0;
}
