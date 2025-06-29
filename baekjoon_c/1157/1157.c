#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int alphabet[26] = { 0 };

typedef struct {
	int value;
	int* ref;
} alpha;

int main(int argc, char* argv[]) {
	char* word = (char*)malloc(1000000 * sizeof(char));
	fgets(word, 1000000, stdin);
	
	int idx = 0;
	while (word[idx] != '\0') {
		alphabet[tolower(word[idx]) - 'a']++;
		idx++;
	}

	int* max = NULL;
	bool dup = false;
	// int test = 0;
	int i = 0;
	alpha max_alpha = NULL;
	while (i < (unsigned int)_countof(alphabet)-1) {
		max_alpha.value = alphabet[i];
		max_alpha.ref = alphabet + i;
		if (max_alpha.value > alphabet[i + 1]) {
			continue;
		}
		else if (max_alpha.value == alphabet[i + 1]) {
			dup = true;
		}
		else {
			max_alpha.ref = alphabet + i + 1;
		}
		i++;
	}
	printf("%d\n", i);
	if (dup == true) {
		printf("?");
	}
	printf("%c", toupper((char)(*max + 'a')));
}