#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void usage(){
    printf("syntax : add_nbo <file1> <file2>\n");
    printf("sample : add_nbo fp1.bin fp2.bin\n");
}
uint32_t change1(uint32_t n){

    return ((n & 0xFF000000)>>24) | ((n & 0x00FF0000)>>8) | ((n & 0x0000FF00)<<8) | ((n & 0x000000FF)<<24);
}


uint32_t file(char *argv){
    FILE *fp;
    uint32_t n;
    fp=fopen(argv,"rb");
    if(fp==NULL)
    {
        printf("error");
        exit(1);
    }
    fread(&n,4,1,fp);
    uint32_t* p1 = &n;
    uint32_t fp_num1 = change1(*p1);
    fclose(fp);
    return fp_num1;
}


int main(int argc, char *argv[]){
    if (argc != 3) {
        usage();
        exit(1);
    }


    uint32_t a, b;
    a= file(argv[1]);
    b = file(argv[2]);
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, a+b, a+b);
}
