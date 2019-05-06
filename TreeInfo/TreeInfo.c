// TreeInfo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "Structure.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	for (;;)
	{
		//////////////Меню///////////////////////////////
		int x = 0;
		printf("	\n			Выберите действие:\n1.Добавить новый элемент в очередь\n");
		printf("2.Выборка из очереди наиболее приоритетного запроса\n");
		printf("3.Вывод всех запросов с заданным приоритетом\n");
		printf("4.Вывод всего содержимого очереди без учета приоритетов\n");
		printf("5.Подсчет количества групп запросов по приоритетам\n");
		printf("6.Загрузка таблицы очередей из файла\n");

		scanf("%i", &x);

		switch (x) {
		case 1:
			printf("1");
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			printf("Введите путь к файлу: \n");
			char path[100];
			scanf("%s", path);
			FileInfo* fileinfo;
			fileinfo = loadfile(path);
			Tree** mas = Tree_repository(fileinfo, (sizeof(fileinfo->keys)/sizeof(int)));
			Tree* temp = malloc(sizeof(*temp));
			for (int i = 0; i <= (sizeof(fileinfo->keys) / sizeof(int)); i++)
			{
				printf("%i\n%s\n", mas[i]->key, mas[i]->str);
			}
			break;
		}
		////////////////Конец меню/////////////////////////
		//return 0;
	}

	return 0;
}
