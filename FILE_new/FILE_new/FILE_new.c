#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

//�ı��ļ��Ͷ������ļ�
//�ļ���ȡ�������ж�
//ע�����ļ���ȡ�����У�����ʹ��feof��������ֱֵ�������ж��ļ��Ƿ����������Ӧ���ڵ��ļ���ȡ������ʱ���ж��Ƿ��ȡʧ�ܽ��������������ļ�ĩβ����
//�ı��ļ���ȡ�Ƿ�������жϷ���ֵ�Ƿ�ΪEOF(fgetc)������NULL(fgets)
//�������ļ��Ķ�ȡ�������жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ�����fread�жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ���
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
        printf("��ȡ�ɹ�");
    }
    else
    {
        if (ferror(pf))   //����ʱ������������
        {
            printf("error reading : unexpected end of file");
        }
        else if (feof(pf))  //�����ļ�ĩβ�ˡ���Ϊ������9�����ݵ����ÿ�ζ�5���Ļ����ڶ��ξ�ֻ�ܶ���4�����ݲ�Ϊ5����Ҳ�Ƕ����ļ�ĩβ��
        {
            printf("error reading");
        }
    }
    return 0;
}

            //�ļ�������
//�ļ���ָ�洢���ⲿ�洢�����ϵġ����ļ�����ʶ��һ�������Ϣ�ļ��ϡ�����CPU �� I/O �豸���ٶȲ�ƥ�䡣Ϊ�˻��� CPU �� I/O �豸֮���ٶȲ�ƥ��ì�ܡ��ļ���������������ʱ��Ŷ�д�ڼ���ļ����ݶ����ڴ���Ԥ����һ���ռ䡣ʹ���ļ��������ɼ��ٶ�ȡӲ�̵Ĵ���