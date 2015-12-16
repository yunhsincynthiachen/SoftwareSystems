#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv) {
	gchar *text;
	GError *err = NULL;

	//Initialize new ghashtable with string key and value
	GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);

	//Get the alice in wonderland text
	g_file_get_contents ("alicewonderland.txt", &text, NULL, &err);

	//split all of the words in the file into individual gchars
	gchar **words;

	words = g_strsplit(text, " ", 0);

	for (int i=0; i<27000; i++) {

		//lookup the hashtable for whether or not the word is already in the hashtable
		gint *val = (gint *) g_hash_table_lookup (hash, words[i]);

		//if value is null, put it into the hashtable, else increment value
		if (val == NULL){ 
			gint *val1 = g_new (gint, 1);
			*val1 = 1;
			g_hash_table_insert(hash, words[i], val1);
		}
		else { 
			*val += 1;
		}

	}

	//Print out everything in the hashtable
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