#include "webview.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

// ---------------------------------------------------------------------------
// callback functions
void run_code(const char *seq, const char *req, void *arg) {
    printf("Params: %s\n", req);
}

void save_code(const char *seq, const char *req, void *arg) {
    printf("Params: %s\n", req);
}


// ---------------------------------------------------------------------------
// utility functions

char *read_file(char *filename) {
    char *buffer = 0;
    long length;
    FILE *f = fopen(filename, "rb");

    if (f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length);
        if (buffer) {
            fread(buffer, 1, length, f);
        }
        fclose(f);
    }

    if (buffer)
    	return buffer; // caller has to free(buffer)
    return NULL;
}


// ---------------------------------------------------------------------------
// main function

int main() {
    webview_t w = webview_create(DEBUG, NULL);
    webview_set_title(w, "code editor");
    // webview_set_size(w, 480, 320, WEBVIEW_HINT_NONE);
    webview_set_size(w, 480, 480, WEBVIEW_HINT_NONE);
    webview_bind(w, "run_code", run_code, NULL);
    webview_bind(w, "save_code", save_code, NULL);
    char* html = read_file("index.html");
    if (html != NULL) {
        webview_set_html(w, html);
        free(html);
    }
    webview_run(w);
    webview_destroy(w);
    return 0;
}
