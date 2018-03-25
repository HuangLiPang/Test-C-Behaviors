#include <stdio.h>
#include <stdlib.h>

void initialize(int *array) {
	for (int i = 0; i < 5; i++) {
		array[i] = i + 1;
	}
}

void printArray(int *array) {
	printf("array[] = {");
	for(int i = 0; i < 4; i++) {
		printf("%d, ", array[i]);
	}
	printf("%d}", array[4]);
	printf("\n-----\n");
}

int main(int argc, char *argv[])
{
	int i = 0;
	int array[] = {1, 2, 3, 4, 5};

	printf("Test C Behaviors:\n");
	printf("i = 0\n");
	printf("array[] = {1, 2, 3, 4, 5}\n\n");

	/* type 1. */
	printf("1. array[i] = i\n");
	printArray(array);
	/* array[] = {1, 2, 3, 4, 5} */

	/* type 2. */
	initialize(array);
	i = 0;
	printf("2. array[i] = i++\n");
	array[i] = i++;

	printArray(array);
	/* array[] = {1, 0, 3, 4, 5} */
	printf("i = %d\n\n", i);

	/* type 3. */
	initialize(array);
	i = 0;
	printf("3. array[i] = ++i\n");
	array[i] = ++i;

	printArray(array);
	/* array[] = {1, 1, 3, 4, 5} */
	printf("i = %d\n\n", i);

	/* type 4. */
	initialize(array);
	i = 0;
	printf("4. array[i++] = i\n");
	array[i++] = i;

	printArray(array);
	/* array[] = {1, 2, 3, 4, 5} */
	printf("i = %d\n\n", i);
	
	/* type 5. */
	initialize(array);
	i = 0;
	printf("5. array[++i] = i\n");
	array[++i] = i;

	printArray(array);
	/* array[] = {1, 1, 3, 4, 5} */
	printf("i = %d\n\n", i);
	
	/* type 6. */
	initialize(array);
	i = 0;
	printf("6. array[i++] = i++\n");
	array[i++] = i++;

	printArray(array);
	/* array[] = {1, 2, 3, 4, 5} */
	printf("i = %d\n\n", i);
	
	/* type 7. */
	initialize(array);
	i = 0;
	printf("7. array[i++] = ++i\n");
	array[i++] = ++i;

	printArray(array);
	/* array[] = {2, 2, 3, 4, 5} */
	printf("i = %d\n\n", i);
	
	/* type 8. */
	initialize(array);
	i = 0;
	printf("8. array[++i] = i++\n");
	array[++i] = i++;

	printArray(array);
	/* array[] = {1, 2, 1, 4, 5} */
	printf("i = %d\n\n", i);
	
	/* type 9. */
	initialize(array);
	i = 0;
	printf("9. array[++i] = ++i\n");
	array[++i] = ++i;
	
	printArray(array);
	/* array[] = {1, 2, 2, 4, 5} */
	printf("i = %d\n\n", i);
	
	return 0;
}
