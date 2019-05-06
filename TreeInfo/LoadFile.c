#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structure.h"


FileInfo* loadfile(char *path)
{
	FILE *file;
	int keys[100];
	char strings[100][100];
	int count_keys = 0, count_strings = 0;
	char buf[100] = "";

	file = fopen(path, "r"); //сюда путь не забыть вписать (path вместо прямого пути)
	for (int i = 0; i < strlen(strings[0]); i++)
	{
		strcpy(strings[i], "");
	}

	while (!feof(file))
	{
		fscanf(file, "%s\n%s", buf, strings[count_strings++]);
		keys[count_keys++] = atoi(buf);
	}

	FileInfo* fileinfo;
	fileinfo = malloc(sizeof(*fileinfo));
	fileinfo->keys = malloc(sizeof(int)*count_keys);
	fileinfo->strings = malloc(sizeof(char*) * 100);

	for (int i = 0; i <= count_keys; i++)
	{
		fileinfo->strings[i] = _strdup(strings[i]);
		fileinfo->keys[i] = keys[i];
	}
	fileinfo->count = count_keys;
	return fileinfo;
}