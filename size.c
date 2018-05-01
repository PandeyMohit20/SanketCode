#include <stdio.h>
#include <string.h>
int getSize(FILE *ip)
{


    int start=0,end=0;

    fseek(ip,0L,SEEK_END);//goes to end of file to determine size of file
    end=ftell(ip);//stores size of file
    rewind(ip);//resets the offset

    return end-start;//return the size of file


}
