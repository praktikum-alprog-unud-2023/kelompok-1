#include <stdio.h>

void hanoi_iteratif(int n, char sumber, char bantu, char tujuan) {
    int stack[n * n][4];
    int top = -1;
    int langkah = 0;
    stack[++top][0] = n;
    stack[top][1] = sumber;
    stack[top][2] = bantu;
    stack[top][3] = tujuan;

    while (top >= 0) {
        int n = stack[top][0];
        char sumber = stack[top][1];
        char bantu = stack[top][2];
        char tujuan = stack[top][3];
        top--;

        if (n == 1) {
            printf("Pindahkan cakram 1 dari %c ke %c\n", sumber, tujuan);
            langkah++;
        } else {
            stack[++top][0] = n - 1;
            stack[top][1] = bantu;
            stack[top][2] = sumber;
            stack[top][3] = tujuan;

            stack[++top][0] = 1;
            stack[top][1] = sumber;
            stack[top][2] = bantu;
            stack[top][3] = tujuan;

            stack[++top][0] = n - 1;
            stack[top][1] = sumber;
            stack[top][2] = tujuan;
            stack[top][3] = bantu;
        }
    }

    printf("Jumlah langkah minimum: %d\n", langkah);
}

int main() {
    int n;
    printf("Masukkan jumlah cakram: ");
    scanf("%d", &n);

    hanoi_iteratif(n, 'A', 'B', 'C');
    return 0;
}