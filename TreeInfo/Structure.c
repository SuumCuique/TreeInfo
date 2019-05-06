#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structure.h"


Tree** Tree_repository(FileInfo* fileinfo)
{
	Tree **mas;
	int *branch;
	int count_mas_el = 0;

	mas = malloc(sizeof(*mas)*fileinfo->count);
	branch = malloc(sizeof(int)*fileinfo->count);
	int *temp_keys = malloc(sizeof(int)*fileinfo->count);

	for (int i = 0; i <= fileinfo->count; i++)
	{
		branch[i] = 0;
		temp_keys[i] = fileinfo->keys[i];
	}
	
	for (int i = 0; i <= fileinfo->count; i++)
	{
		int index = 0;
		index = maxindex(temp_keys, fileinfo->count);
		Tree* tree;
		tree = malloc(sizeof(*tree));
		tree = Tree_create(index, temp_keys, fileinfo->strings);
		temp_keys[index] = _CRT_INT_MAX;
		mas[count_mas_el++] = tree;
	}
	branch[0] = 1;
	for (int i = 0; i <= fileinfo->count; i++)
	{
		for (int j = 0; j <= fileinfo->count; j++)
		{
			if (branch[j] == 0)
			{
				if (mas[i]->prohod == 0)
				{
					mas[i]->left = mas[j];
					mas[i]->prohod = 1;
					branch[j] = 1;
				}
				else if(mas[i]->prohod == 1)
				{
					mas[i]->right = mas[j];
					mas[i]->prohod = 2;
					branch[j] = 1;
				}
				else mas[i]->prohod = 2;
			}
		}

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

int maxindex(int *keys, int size)
{
	int max = 0;
	int index_max = -1;
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