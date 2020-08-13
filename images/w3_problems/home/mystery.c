#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE *fp;

    fp = fopen("/tmp/data.txt", "w+");
    fputs("Hello darkness my old friend...\n", fp);
    fclose(fp);
}
