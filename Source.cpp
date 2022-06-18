#include <iostream>
#include <cstring>
#include "Data_Generator.h"
#include "Algorithm_Mode.h"
#include "Comparison_mode.h"


// ham main chinh
int main(int argc, char** argv) {
	//init pointer variable
	Data* data = nullptr;
	Sorting* sort = nullptr;
	AM* am = nullptr;
	CM* cm = nullptr;

	if (strcmp(argv[1], "-a") == 0) {
		if (argc == 6)
			am->Command_2(argc,argv);
		else if (argc == 5) {
			bool check = 0;
			for (int i = 0; i < strlen(argv[3]); i++)
				if (!(argv[3][i] <= '9' && argv[3][i] >= '0')) {
					check = 1; 
					break;
				}
			if (check)
				am->Command_1(argc,argv);
			else
				am->Command_3(argc, argv);
		}
	}
	else if (strcmp(argv[1], "-c") == 0) {
		if (argc == 5)
			cm->Command_4(argc,argv);
		else if (argc == 6)
			cm->Command_5(argc,argv);
	}
	return 0;
}