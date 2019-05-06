#pragma once

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

Tree** Tree_repository(int *keys, char** strings, int count);
Tree* Tree_create(int index, int* temp_keys, char** strings);
int maxindex(int *keys);
Tree** loadfile(char *path);
