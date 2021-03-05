
#include <iostream>
#include "Composant1.h"
#include "Composant2.h"
#include <dlfcn.h>

int main(int argc, char ** argv)
{
	int data1=3;
	int data2=5;

	int valeur;
	
	void *handle;
	char *error;

	// Choose component
	if (argv[1] == "Composant1")
		handle = dlopen("../lib/libComposant1.so", RTLD_LAZY);
	else if (argv[1] == "Composant2")
		handle = dlopen("../lib/libComposant2.so", RTLD_LAZY);

	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	dlerror();    /* Clear any existing error */
	
	if (argv[1] == "Composant1") {
		valeur=composant1(data1,data2);
		std::cout << getComposant1Version() << std::endl;
		std::cout << "valeur 1 :" << valeur << std::endl;
	} else if (argv[1] == "Composant2") {
		valeur=composant2(data1,data2);
		std::cout << "valeur 2 :" << valeur << std::endl;
	}
}
