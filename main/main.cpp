
#include <iostream>
#include <dlfcn.h>
#include <string>
//#include "Composant1.h"
//#include "Composant2.h"

int main(int argc, char ** argv)
{
	int data1=3;
	int data2=5;

	int valeur;
	int (*component_value)(int, int);
	
	void *handle;
	char *error;
	std::string arg = argv[1];
	
	std::cout << "argv[1] = '" << arg << "'" << std::endl;

	// Choose component
	if (arg == "Composant1") {
		handle = dlopen("../Composant1/libComposant1.so", RTLD_NOW);
		//int (*component_value)(int,int) = (int (*)(int,int)) dlsym(handle, "composant1");
		//*(void **) (&component_value) = dlsym(handle, "composant1");
	} else if (arg == "Composant2") {
		handle = dlopen("../Composant2/libComposant2.so", RTLD_NOW);
		//int (*component_value)(int,int) = (int (*)(int,int)) dlsym(handle, "composant2");
		//*(void **) (&component_value) = dlsym(handle, "composant2");
	}
	
	// Failure
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	/*
	if (!component_value) {
		// no such symbol
		fprintf(stderr, "Error: %s\n", dlerror());
		dlclose(handle);
		return EXIT_FAILURE;
	}*/

	dlerror();    // Clear any existing error
	
	if (arg == "Composant1") {
		component_value = (int (*)(int,int)) dlsym(handle, "composant1");
		std::cout << "ok" << std::endl;
		valeur = component_value(data1,data2);
		//std::cout << getComposant1Version() << std::endl;
		std::cout << "valeur 1 :" << valeur << std::endl;
	} else if (arg == "Composant2") {
		component_value = (int (*)(int,int)) dlsym(handle, "composant2");
		std::cout << "ok" << std::endl;
		valeur = component_value(data1,data2);
		std::cout << "valeur 2 :" << valeur << std::endl;
	}

	dlclose(handle);
	return EXIT_SUCCESS;
}
