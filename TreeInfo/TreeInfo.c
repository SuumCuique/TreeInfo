// TreeInfo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "Structure.h"

FileInfo* load()
{
	FileInfo* fileinfo;
	printf("Введите путь к файлу: \n");
	char path[100];
	scanf("%s", path);
	
	clock_t ttime;
	srand(time(NULL));
	ttime = clock();

	fileinfo = loadfile(path);

	Tree** mas = Tree_repository(fileinfo);
	printf("time: %d\n", ttime/1000);
	return fileinfo;
}

int count(FileInfo* fileinfo)
{
	int size = fileinfo->count-1;
	int *mas;
	mas = malloc(size);
	int count = 0;
	bool b = false;
	for (int i = 0; i <= size; i++)
	{
		mas[i] = 0;
	}
	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j <= size; j++)
		{
			if (fileinfo->keys[i] == mas[j])
			{
				b=true;
				break;
			}
		}
		if (b==false)
		{
			mas[count++] = fileinfo->keys[i];
		}
		b = false;
	}
	return count;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	FileInfo* fileinfo = load();
	for (;;)
	{
		//////////////Меню///////////////////////////////
		int x = 0;
		printf("	\n			Выберите действие:\n1.Добавить новый элемент в очередь\n");
		printf("2.Выборка из очереди наиболее приоритетного запроса\n");
		printf("3.Вывод всех запросов с заданным приоритетом\n");
		printf("4.Вывод всего содержимого очереди без учета приоритетов\n");
		printf("5.Подсчет количества групп запросов по приоритетам\n");
		printf("6.Загрузка других данных\n");
		printf("7.Просмотр бинарного дерева\n");
		printf("8.Выход\n");

		scanf("%i", &x);
		int key, index;
		switch (x) {
		case 1:
			key = 0;
			char* str;
			str = malloc(sizeof(char) * 100);
			printf("Введите приоритет:");
			scanf("%i", &key);
			printf("Введите запрос:");
			scanf("%s", str);
			fileinfo->keys[fileinfo->count] = key;
			fileinfo->strings[fileinfo->count++] = _strdup(str);
			break;
		case 2:
			index = maxindex(fileinfo->keys, fileinfo->count);
			printf("%i\t-\t%s", fileinfo->keys[index], fileinfo->strings[index]);
			break;
		case 3:
			printf("Введите приоритет: ");
			int prior;
			scanf("%i", &prior);
			for (int i = 0; i <= fileinfo->count; i++)
			{
				if (prior == fileinfo->keys[i])
				{
					printf("%i\t-\t%s\n",fileinfo->keys[i],fileinfo->strings[i]);
				}
			}
			break;
		case 4:
			printf("Приоритет\t\t\tЗапрос\n");
			for (int i = 0; i < fileinfo->count;i++)
			{
				printf("%i\t\t-\t\t%s\n", fileinfo->keys[i], fileinfo->strings[i]);
			}
			break;
		case 5:
			printf("Кол-во групп:%i\n", count(fileinfo));
			break;
		case 6:
			fileinfo = load();
			break;
		case 7:
			clock_t ttime;
			srand(time(NULL));
			ttime = clock();
			int size = fileinfo->count;
			Tree** mas = Tree_repository(fileinfo);
			int i = 0, prev_min=0, prev_max=0;
			printf("%i\n", mas[0]->key);
			do	{
				i++;
				for (int j = prev_min = prev_min + pow(2, i-1); j <= pow(2, i) + prev_max && j<size; j++)
				{
					printf("%i\t", mas[j]->key);
				}
				printf("\n");
				prev_max = pow(2, i);
			} while (pow(2, i) + 1 <= size);
			printf("time: %d\n",ttime/1000);
			break;
		case 8:
			exit(0);
		}
		////////////////Конец меню/////////////////////////
	}

	return 0;
}
