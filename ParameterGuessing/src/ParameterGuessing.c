#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

typedef struct aStruct {
	int a;
	int b;
} aStruct;

void ov1(int x, aStruct a);
void ov2(int x, aStruct* aPtr);
int funWith2ATypeObjectParams(aStruct a, aStruct b);

void foo() {
	int intA, intB;
	aStruct* axPtr;
	aStruct ax;
	funWith2ATypeObjectParams(*axPtr, *axPtr);
	ov1(intB, *axPtr);
	ov2(intA, &ax);
}
