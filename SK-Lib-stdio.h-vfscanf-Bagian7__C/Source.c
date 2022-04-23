#pragma warning(disable:4996)

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <conio.h>

/*
    Source by Microsoft
    Modified For Learn by RK
    I.D.E : VS2019
*/

FILE* stream;

int call_vfscanf_s(FILE* istream, char* format, ...) {
    int result;
    va_list arglist;
    va_start(arglist, format);
    result = vfscanf_s(istream, format, arglist);
    va_end(arglist);
    return result;
}

int main() {
    long l;
    float fp;
    char s[81];
    char c;

    if (fopen_s(&stream, "vfscanf_s.out", "w+") != 0) {
        printf("The file vfscanf_s.out was not opened\n");
    } else {
        fprintf(stream, "%s %ld %f%c", "a-string", 65000, 3.14159, 'x');
        fseek(stream, 0L, SEEK_SET);
        call_vfscanf_s(stream, "%s %ld %f%c", s, _countof(s), &l, &fp, &c, 1);

        // Output data read:
        printf("%s\n", s);
        printf("%ld\n", l);
        printf("%f\n", fp);
        printf("%c\n", c);

        fclose(stream);
    }

    _getch();
    return 0;
}