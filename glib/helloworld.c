#include <stdio.h>
#include <glib.h>

int main(int argc, char** argv) {
     GList* list = NULL;
     list = g_list_append(list, "Hello Glib!");
     list = g_list_append(list, "Sir");
     char* str = g_list_first(list)->data;
     printf("The first item is '%s'\n", str);
     return 0;
}