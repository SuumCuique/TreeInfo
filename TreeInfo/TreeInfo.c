// TreeInfo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Structure.h"

FileInfo* load()
{
	FileInfo* fileinfo;
	printf("Введите путь к файлу: \n");
	char path[100];
	scanf("%s", path);

	fileinfo = loadfile(path);
	Tree** mas = Tree_repository(fileinfo);

	return fileinfo;
}

int count(int* keys)
{
	int size = (sizeof(keys) / sizeof(int));
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
			if (keys[i] == mas[j])
			{
				b=true;
				break;
			}
		}
		if (!b)
		{
			mas[count++] = keys[i];
			b=false;
		}
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

		scanf("%i", &x);

		switch (x) {
		case 1:
			printf("1");
			break;
		case 2:
			int index = maxindex(fileinfo->keys);
			printf("%i\t-\t%s", fileinfo->keys[index], fileinfo->strings[index]);
			break;
		case 3:
			printf("Введите приоритет: ");
			int prior;
			scanf("%i", &prior);
			for (int i = 0; i <= (sizeof(fileinfo->keys) / sizeof(int)); i++)
			{
				if (prior == fileinfo->keys[i])
				{
					printf("%i\t-\t%s",fileinfo->keys[i],fileinfo->strings[i]);
				}
			}
			break;
		case 4:
			printf("Приоритет\t\t\tЗапрос\n");
			for (int i = 0; i <= (sizeof(fileinfo->keys) / sizeof(int));i++)
			{
				printf("%i\t\t-\t\t%s\n", fileinfo->keys[i], fileinfo->strings[i]);
			}
			break;
		case 5:
			printf("Кол-во групп:%i\n", count(fileinfo->keys));
			break;
		case 6:
			fileinfo = load();
			break;
		case 7:
			int size = fileinfo->count;
			Tree** mas = Tree_repository(fileinfo);
			int i = 0;
			printf("%i\n", mas[0]->key);
			do	{
				i++;
				for (int j = pow(2, i-1); j <= pow(2, i) && j<=size; j++)
				{
					printf("%i\t", mas[j]->key);
				}
				printf("\n");
				
			} while (pow(2, i) + 1 <= size);
			break;
		}
		////////////////Конец меню/////////////////////////
	}

	return 0;
}
