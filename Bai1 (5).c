#include <stdio.h>

void taoMaTran(int soHang, int soCot, int maTran[soHang][soCot]) {
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("Nh?p giá tr? cho ma tr?n t?i v? trí [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &maTran[i][j]);
        }
    }
}

void inMaTran(int soHang, int soCot, int maTran[soHang][soCot]) {
    printf("Ma tr?n ð? nh?p là:\n");
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int soHang, soCot;

    printf("Nh?p s? hàng c?a ma tr?n: ");
    scanf("%d", &soHang);
    printf("Nh?p s? c?t c?a ma tr?n: ");
    scanf("%d", &soCot);

    int maTran[soHang][soCot];

    taoMaTran(soHang, soCot, maTran);
    inMaTran(soHang, soCot, maTran);

    return 0;
}
