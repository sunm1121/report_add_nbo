#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *file1, *file2;
    uint32_t num1, num2, sum;

    file1 = fopen(argv[1], "rb");
    if (file1 == NULL) {
        perror("can't open.");
        return 1;
    }

    file2 = fopen(argv[2], "rb");
    if (file2 == NULL) {
        perror("can't open.");
        fclose(file1); 
        return 1;
    }

    size_t items_read1 = fread(&num1, sizeof(uint32_t), 1, file1);
    if (items_read1 != 1) {
        perror("can't open");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    size_t items_read2 = fread(&num2, sizeof(uint32_t), 1, file2);
    if (items_read2 != 1) {
        perror("can't open");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    fclose(file1);
    fclose(file2);

    sum = ntohl(num1) + ntohl(num2);

    printf("%u(0x%08x) + %u(0x%08x) = %u(0x%08x)\n", ntohl(num1), ntohl(num1), ntohl(num2), ntohl(num2), sum, sum);

    return 0;
}
