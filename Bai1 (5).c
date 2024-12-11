#include <stdio.h>

void taoMaTran(int soHang, int soCot, int maTran[soHang][soCot]) {
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("Nh?p gi� tr? cho ma tr?n t?i v? tr� [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &maTran[i][j]);
        }
    }
}

void inMaTran(int soHang, int soCot, int maTran[soHang][soCot]) {
    printf("Ma tr?n �? nh?p l�:\n");
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int soHang, soCot;

    printf("Nh?p s? h�ng c?a ma tr?n: ");
    scanf("%d", &soHang);
    printf("Nh?p s? c?t c?a ma tr?n: ");
    scanf("%d", &soCot);

    int maTran[soHang][soCot];

    taoMaTran(soHang, soCot, maTran);
    inMaTran(soHang, soCot, maTran);

    return 0;
}
