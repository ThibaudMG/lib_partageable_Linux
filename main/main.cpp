
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
	
	std::cout << "argv = '" << argv[1] << "'" << std::endl;

	// Choose component
	if (argv[1] == "Composant1") {
		std::cout << "1" << std::endl;//handle = dlopen("../Composant1/libComposant1.so", RTLD_LAZY);
	} else if (argv[1] == "Composant2") {
		std::cout << "2" << std::endl;//handle = dlopen("../Composant2/libComposant2.so", RTLD_LAZY);
	}
	/*
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	dlerror();    // Clear any existing error */
	
	if (argv[1] == "Composant1") {
		//valeur=composant1(data1,data2);
		//std::cout << getComposant1Version() << std::endl;
		std::cout << "v1" << std::endl;//std::cout << "valeur 1 :" << valeur << std::endl;
	} else if (argv[1] == "Composant2") {
		//valeur=composant2(data1,data2);
		std::cout << "v2" << std::endl;//std::cout << "valeur 2 :" << valeur << std::endl;
	}
}
