// including stdio gives us access to printf
#include <stdio.h>
// including assert gives us access to the assert function
#include <assert.h>
// including stdlib gives access to malloc and free functions
#include <stdlib.h>
// including string gives us access to strdup function
#include <string.h>

// define a structure named Person
struct Person {
	// which contains a pointer to a string
	char *name;
	// among other things
	int age;
	int height;
	int weight;
};

// define a function that will, upon passing it desired initial values for a
// person, will allocate memory for the struct, initialize values, and return a
// pointer to this newly-created struct.
struct Person *Person_create (char *name, int age, int height, int weight) {
	// allocate the required memory for a Person struct
	struct Person *who = malloc(sizeof(struct Person));
	// if the memory that mallow gives us is bad, crash the program
	assert(who != NULL);

	// using the pointer to struct member notation, initalize all values
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	// return pointer to this struct
	return who;
}

// because the struct was created by malloc, and does not get destroyed when it
// leaves its scope, it must be manually free'd, as well as any memory within
// it that was malloc'd (strdup works a bit like malloc, must be free'd)
void Person_destroy (struct Person *who) {
	// if the pointer we are about to free is bad, crash the program
	assert(who != NULL);

	// manually release the memory that was allocated earlier
	free(who->name);
	free(who);
}

void Person_print (struct Person *who) {
	// function to define a format by which the struct person will be printed.
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main (int argc, char *argv[]) {
	// make two people structures
	struct Person *joe = Person_create(
			"Joe Alex", 32, 64, 140);
	struct Person *frank = Person_create(
			"Frank Blank", 20, 72, 180);

	// print them out and where they are in memory
	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);

	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);

	// make everyone age 20 years and print them again
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	// destroy them both so we clean up
	Person_destroy(joe);
	Person_destroy(frank);


	Person_destroy(NULL);
	return 0;
}
