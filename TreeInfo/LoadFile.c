#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structure.h"


Tree** loadfile(char *path)
{
	FILE *file;
	int keys[100];
	char strings[100][100];
	int count_keys = 0, count_strings = 0;
	char buf[100] = "";

	file = fopen("C:\\Users\\Vlad\\Desktop\\data.txt", "r"); //���� ���� �� ������ ������� (path ������ ������� ����)
	for (int i = 0; i < strlen(strings[0]); i++)
	{
		strcpy(strings[i], "");
	}

	while (!feof(file))
	{
		fscanf(file, "%s\n%s", buf, strings[count_strings++]);
		keys[count_keys++] = atoi(buf);


	}

	return Tree_repository(keys, strings, count_keys);
}