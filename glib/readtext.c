#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>

// static void print_data (gchar *key, gchar *value)
// {
// 	printf ("%s:%s\n", key, value);
// }

int main(int argc, char** argv) {
	gchar *text;
	GError *err = NULL;

	GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
	// g_hash_table_insert(hash, "Texas", "Austin");

	g_file_get_contents ("alicewonderland.txt", &text, NULL, &err);

	gchar **words;

	words = g_strsplit(text, " ", 0);

	for (int i=0; i<27000; i++) {

		// gchar *value;
	 //    value = g_hash_table_lookup(hash, words[i]);

		gint *val = (gint *) g_hash_table_lookup (hash, words[i]);

		if (val == NULL){ 
			gint *val1 = g_new (gint, 1);
			*val1 = 1;
			g_hash_table_insert(hash, words[i], val1);
		}
		else { 
			*val += 1;
			// printf("%i. %s, %i\n", i, words[i], *val);
		}

	}

	GList *newhashkeys;
	newhashkeys = g_hash_table_get_keys(hash);	
	for (int j = 0; j < g_list_length(newhashkeys); j++){ 
		gconstpointer key_word = g_list_nth(newhashkeys,j)->data;
		gint *val = (gint *) g_hash_table_lookup (hash, key_word);
		if (*val > 20){
			printf("%i. %s : %i \n", j, key_word, *val);
		}
	}
	return 0;
}