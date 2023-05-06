#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    FILE *fp;
    int cnt = 0; 
    if ((fp=fopen(argv[2], "r")) == NULL)
    {
        puts("error!\n");
        return 0;
    }
    if (argv[1][1] == 'c') 
    {
        char c;
        while ((c = fgetc(fp)) != EOF) cnt ++;
        printf("×Ö·ûÊý£º%d", cnt);
    }
	else if (argv[1][1] == 'w')
    {
        char s[2048];
        while (fscanf(fp, "%s", s) != EOF)
        {	int i; 
            cnt ++;
            for ( i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    cnt ++;
        }
        printf("µ¥´ÊÊý£º%d\n", cnt);
    }

    fclose(fp);
    return 0;
}





