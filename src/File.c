#include<stdio.h>
#include<errno.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    {
        int a = 0xffff;
        //写入.
        FILE *fp = fopen("out\\test.txt", "wb");
        if (fp==NULL)
        {
            printf("%s\n", strerror(errno));
            return 0;
        }
        
        fwrite(&a, 4, 1, fp);
        int b = 0;
        fclose(fp);
        fp = NULL;
        //读取.
        fp = fopen("out\\test.txt", "rb");
        fread(&b, 4, 1, fp);
        fclose(fp);
        fp = NULL;
        printf("%x\n", b);
    }
    {
/*         //屏幕流
        int a=fgetc(stdin);
        //读取掉\n
        fgetc(stdin);
        fputc(a,stdout);
        char b[1024];
        fgets(b, 1024, stdin);
        fputs(b, stdout); */
    }
    {
        //fpirntf,fscanf
        printf("fprintf,fscanf:\n");
        struct S{
            int no;
            float score;
            char arr[10];
        }s={100,3.14f,"hello"},s2;
        FILE *pf = fopen("out\\test.txt", "w+");
        fprintf(pf, "%d %f %s\n", s.no, s.score, s.arr);
        fseek(pf, 0, SEEK_SET);
        fscanf(pf, "%d %f %s\n", &s2.no, &s2.score, s2.arr);
        printf("%d %f %s\n", s2.no, s2.score, s2.arr);
        printf("文件指针偏移量:%d\n", ftell(pf));
        //重置文件指针为起始位置
        rewind(pf);
        printf("文件指针偏移量:%d\n", ftell(pf));
    }
    {
        //sprintf,sscanf
        printf("spritf,sscanf:\n");
        struct S
        {
            int no;
            float score;
            char arr[10];
        } s = {100, 3.14f, "hello"}, s2;
        char a[255] = {0};
        sprintf(a, "%d %f %s\n", s.no, s.score, s.arr);
        sscanf(a, "%d %f %s\n", &s2.no, &s2.score, s2.arr);
        printf("%d %f %s\n", s2.no, s2.score, s2.arr);
    }
    return 0;
}
