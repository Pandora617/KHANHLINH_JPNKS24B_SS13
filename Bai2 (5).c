#include <stdio.h>

int timUCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;

    printf("Nhap so a: ");
    scanf("%d", &a);
    printf("Nhap so b: ");
    scanf("%d", &b);

    int ucln = timUCLN(a, b);
    printf("UCLN cua %d va %d la: %d\n", a, b, ucln);

    return 0;
}
