#include <stdio.h>
#include <stdint.h>

uint32_t change(uint32_t n){

    return ((n & 0xFF000000)>>24) | ((n & 0x00FF0000)>>8) | ((n & 0x0000FF00)<<8) | ((n & 0x000000FF)<<24);
}


int main(){
    FILE *fp1, *fp2;
    uint32_t n1, n2;

    fp1 = fopen("/home/yeji/temp/qt/pro_add_nbo/fp1.bin","rb");
    fread(&n1,4,1,fp1);

    fp2 = fopen("/home/yeji/temp/qt/pro_add_nbo/fp2.bin","rb");
    fread(&n2,4,1,fp2);

    uint32_t* p1 = &n1;
    uint32_t fp_num1 = change(*p1);

    uint32_t* p2 = &n2;
    uint32_t fp_num2 = change(*p2);
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", fp_num1, fp_num1, fp_num2, fp_num2, fp_num1+fp_num2, fp_num1+fp_num2);

    fclose(fp1);
    fclose(fp2);


}
