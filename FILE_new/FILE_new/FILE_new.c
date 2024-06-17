#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

//文本文件和二进制文件
//文件读取结束的判断
//注：在文件读取过程中，不能使用feof函数返回值直接用来判断文件是否结束，而是应用于当文件读取结束的时候，判断是否读取失败结束，还是遇到文件末尾结束
//文本文件读取是否结束，判断返回值是否为EOF(fgetc)，或者NULL(fgets)
//二进制文件的读取结束，判断返回值是否小于实际要读的个数，fread判断返回值是否小于实际要读的个数
int main()
{
    double a[5] = { 1,2,3,4,5 };
    FILE* pf = fopen("test.txt", "wb");
    fwrite(&a, sizeof *a, 5, pf);
    fclose(pf);
    double b[5];
    FILE* pf = ("test.txt", "rb");
    size_t ret = fread(&b, sizeof* b, 5, pf);
    if (ret == 5)
    {
        printf("读取成功");
    }
    else
    {
        if (ferror(pf))   //读的时候遇见错误了
        {
            printf("error reading : unexpected end of file");
        }
        else if (feof(pf))  //读到文件末尾了。因为可能有9个数据但如果每次读5个的话，第二次就只能读出4个数据不为5，但也是读到文件末尾了
        {
            printf("error reading");
        }
    }
    return 0;
}

            //文件缓冲区
//文件是指存储在外部存储介质上的、由文件名标识的一组相关信息的集合。由于CPU 与 I/O 设备间速度不匹配。为了缓和 CPU 与 I/O 设备之间速度不匹配矛盾。文件缓冲区是用以暂时存放读写期间的文件数据而在内存区预留的一定空间。使用文件缓冲区可减少读取硬盘的次数