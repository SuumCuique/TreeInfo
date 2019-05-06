#include <stdio.h>

typedef struct Tree Tree;

struct Tree
{
	int key;
	Tree* left;
	Tree* right;
	//предыдущий проход. 0- прохода не было, 1 - проход влево, 2- проход вправо. проходы слева направо
	//соответственно проход направо - последний
	int prohod;
	char *str;
};

Tree* Tree_create(int *keys, char** strings, int count)
{
	Tree* tree;
	tree = malloc(sizeof(*tree)*count);
	if (tree != NULL)
	{
		for (int i = 0; i < count; i++)
		{
			
		}

	}

}
int max(int *keys)
{
	int max = 0;
	int index_max = -1;
	int size = sizeof(keys) / sizeof(int);
	for (int i = 0; i < size; ++i)
	{
		if (keys[i] > max)
		{
			max = keys[i];
			index_max = i;
		}
	}
	return index_max;
}