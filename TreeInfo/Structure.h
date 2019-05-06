#pragma once

typedef struct Tree Tree;

typedef struct FileInfo FileInfo;

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

struct FileInfo
{
	int* keys;
	char** strings;
	int count;
};

Tree** Tree_repository(FileInfo* fileinfo);
Tree* Tree_create(int index, int* temp_keys, char** strings);
int maxindex(int *keys);
FileInfo* loadfile(char *path);
