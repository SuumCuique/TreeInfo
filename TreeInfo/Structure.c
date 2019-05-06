#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structure.h"


Tree** Tree_repository(FileInfo* fileinfo, int count)
{
	Tree **mas;
	mas = malloc(sizeof(*mas)*count);

	int *boool;
	boool = malloc(sizeof(int)*count);


	int *temp_keys = malloc(sizeof(int)*count); 
	for (int i = 0; i <= count; i++)
	{
		boool[i] = 0;
		temp_keys[i] = fileinfo->keys[i];
	}


	int count_mas_el = 0;

	for (int i = 0; i <= count; i++)
	{
		int index = 0;
		index = maxindex(temp_keys);
		Tree* tree;
		tree = malloc(sizeof(*tree));
		tree = Tree_create(index, temp_keys, fileinfo->strings);
		temp_keys[index] = _CRT_INT_MAX;
		mas[count_mas_el++] = tree;

	}
	return mas;
}

Tree* Tree_create(int index, int* temp_keys, char** strings)
{
		Tree* tree;
		tree = malloc(sizeof(*tree));
		if (tree != NULL)
		{
			tree->key = temp_keys[index];
			tree->left = NULL;
			tree->right = NULL;
			tree->prohod = 0;
			tree->str = strings[index];
		}
		return tree;
}

int maxindex(int *keys)
{
	int max = 0;
	int index_max = -1;
	int size = sizeof(keys) / sizeof(int);
	for (int i = 0; i <= size; ++i)
	{
		if (keys[i] > max && keys[i]!=_CRT_INT_MAX)
		{
			max = keys[i];
			index_max = i;
		}
	}
	return index_max;
}