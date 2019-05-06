#pragma once

typedef struct Tree Tree;

struct Tree
{
	int key;
	Tree* left;
	Tree* right;
	//���������� ������. 0- ������� �� ����, 1 - ������ �����, 2- ������ ������. ������� ����� �������
	//�������������� ������ ������� - ���������
	int prohod;
	char *str;
};

Tree** Tree_repository(int *keys, char** strings, int count);
Tree* Tree_create(int index, int* temp_keys, char** strings);
int maxindex(int *keys);
Tree** loadfile(char *path);
