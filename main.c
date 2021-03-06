// main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

// free_wargs()
static void free_wargs(
    int wargc, wchar_t** wargs) {
    for (int i = 0; i < wargc; i++) {
        if (wargs[i] != NULL) {
            free(wargs[i]);
            wargs[i] = NULL;
        }
    }
    free(wargs);
    return;
}

// alloc_wargs()
static wchar_t** alloc_wargs(
    int argc, char* args[]) {
    wchar_t** wargs =
        (wchar_t**)calloc(argc, sizeof(wchar_t*));
    for (int i = 0; i < argc; i++) {
        char* ncs = args[i];
        int maxlen = strlen(ncs);
        wargs[i] = (wchar_t*)
            calloc(maxlen+1, sizeof(wchar_t));
        size_t ret =
            mbstowcs(wargs[i], ncs, maxlen);
        if ((int)ret < 0) {
            free_wargs(argc, wargs);
            return NULL;
        }
    }
    return wargs;
}

// main()
extern int wmain(int, wchar_t**);
int main(int argc, char* args[]) {
    setlocale(LC_CTYPE, "");
    wchar_t** wargs = alloc_wargs(argc, args);
    int retval = wmain(argc, wargs);
    free_wargs(argc, wargs);
    return retval;
}

//
// wmain()
//
int wmain(int argc, wchar_t* args[]) {
    //for (int i = 0; i < argc; i++) {
    //  wprintf(L"%ls: %d\n",
    //      args[i], wcslen(args[i]));
    //}
    return 0;
}
