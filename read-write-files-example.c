#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *file;
    char name[] = "sort.txt";
	srand(time(NULL));
	
	//WRITE
    if ((file = fopen(name, "w+")) == NULL) {
        printf("err");
        return 1;
    }

	int randNumbersQtd;
    scanf("%d", &randNumbersQtd);

	int i;
    for(i = 0; i < randNumbersQtd; i++) {
        fprintf(file, "%d\n", (rand() % 101));
    }

    fclose(file);
    printf("Done!! %d numbers are generated in file: %s", randNumbersQtd, name);
	
	
	//READ
	if ((file = fopen(name, "r")) == NULL) {
        printf("err");
        return 1;
    }
	
	char text[30];
	while (!feof(file)) {
        fgets(text, 30, file);
		printf("%s", text);
    }
    
    fclose(file);

    return 0;
}
