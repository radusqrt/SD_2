#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "backend.h"

using namespace std;

int main(int argc, char** argv) {
	if (argc != 3) {
		fprintf(stderr, "usage: %s input_file output_file\n", argv[0]);
		return -1;
	}

	// Open input file
	FILE *inputFile = fopen(argv[1], "r");
	if (inputFile == NULL) {
		fprintf(stderr, "Error opening input file %s\n", argv[1]);
		return -1;
	}

	// Open output file
	FILE *outputFile = fopen(argv[2], "w");
	if (outputFile == NULL) {
		fprintf(stderr, "Error opening output file %s\n", argv[2]);
		return -1;
	}

	// Test
	Backend b;
	char command[10];
	char word[50];
	char * pChar = NULL;
	int index, start, stop;	

	while((fscanf(inputFile, "%s", command)) == 1) {
		if (strcmp(command, "CUT") == 0) {
			fscanf(inputFile, "%d", &start);
			fscanf(inputFile, "%d", &stop);
			b.Cut(start, stop);
		}

		else if (strcmp(command, "COPY") == 0) {
			fscanf(inputFile, "%d", &start);
			fscanf(inputFile, "%d", &stop);
			b.Copy(start, stop);
		}

		else if (strcmp(command, "PASTE") == 0) {
			fscanf(inputFile, "%d", &start);
			b.Paste(start);
		}

		else if (strcmp(command, "UNDO") == 0) {
			b.Undo();
		}

		else if (strcmp(command, "REDO") == 0) {
			b.Redo();
		}

		else if (strcmp(command, "ADD") == 0) {
			fscanf(inputFile, "%d", &index);
			fscanf(inputFile, "%s", word);

			if (strcmp(word, "EMPTY") == 0) {
				word[0] = '\0';
			}

			b.Add(index, word);
		}

		pChar = b.GetText();
		fprintf(outputFile, "%s\n", pChar);
		delete[] pChar;
	}

	fclose(inputFile);
	fclose(outputFile);
	return 0;
}
