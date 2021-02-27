#include <stdio.h>
#include <windows.h>
#define N 255 
struct date {
	int year;
	int month;
	int day;
};
struct time {
	int hour;
	int minutes;
};
struct flights {
	int number;
	char destination[N];
	time time;
	date date;
	int cost;
};
void menu(flights*, int);
void creator(flights**, int&);
void printDatabase(flights*, int);
void sorting(flights**, int); 
void sortingNumb(flights**, int);
void sortingDestination(flights**, int);
void raplace(flights**, int, int);
int choosSortMet();
void sortingTime(flights**, int);
void sortingDate(flights**, int);
void correctDatabase(flights**, int);
void deleteStruct(flights**, int);

int main()
{ 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	flights* p = nullptr;
	int amount = 0;
	p = (flights*)malloc(sizeof(flights) * 1);
	menu(p, amount);
}

void menu(flights* p, int amount) {
	int paragraph;
	printf_s("\nHello! Welcome to the <Flights.inc> - flight editor.\n\nSelect the action you want to take:\n");
	printf_s("1. Make a database.\n2. Print your database.\n3.Correct your database.\n4. ");//дописать
	printf_s("5. Sorting a database by a given parameter.\n6. ");//дописать
	printf_s("Enter the number of the desired action:\n");
	do {
		if (!(scanf_s("%d", &paragraph))) {
			printf_s("\n=======================================================\n\t\t\tОшибка\n");
			printf_s("=======================================================\n\t\t    Введите цифру.\n");
			rewind(stdin);
			continue;
		}
		else break;
	} while (1);
	switch (paragraph) {
	case 1:
		creator(&p, amount);
		return;
	case 2:
		printDatabase(p, amount);
		return;
	case 3:
		correctDatabase(&p, amount);
		return;
	case 5:
		sorting(&p, amount);
		return;
	case 6: 
		deleteStruct(&p, amount);
	}
}
void creator(flights** p, int &сounter) {
	int end;
	system("CLS");
	printf_s("Вы выбрали пункт создать таблицу.\n");
	do {
		end = 1;
		printf_s("Это рейс №%d. Вносите информацию, следуя инструкциям.\nВведите номер вылета:\n", сounter+1);
		do {
			if (!(scanf_s("%d", &(*p)[сounter].number))) {
				printf_s("Номер вылета не может содержать букы, повторите ввод:\n");
				rewind(stdin);
			}
			else break;
		} while (1);
		printf_s("Enter destination:\n");
		rewind(stdin);
		fgets((*p)[сounter].destination, 255, stdin);
		for (int j = 0; (*p)[сounter].destination; j++) {
			if ((*p)[сounter].destination[j] == '\n') {
				(*p)[сounter].destination[j] = '\0';
				break;
			}
		}
		printf_s("Вводите время вылета.\n\tВведите час отправления:\n\t");
		do {
			if (!(scanf_s("%d", &(*p)[сounter].time.hour))) {
				printf_s("Время вылета не может содержать букы, повторите ввод:\n");
				rewind(stdin);
			}
			if ((*p)[сounter].time.hour > 23 || (*p)[сounter].time.hour < 0) {
				printf_s("Ошибка ввода.\n");//дописать
			}
			else break;
		} while (1);
		printf_s("\tВведите минуты вылета:\n\t");
		do {
			if (!(scanf_s("%d", &(*p)[сounter].time.minutes))) {
				printf_s("Время вылета не может содержать букы, повторите ввод:\n");
            rewind(stdin);
			}
			if ((*p)[сounter].time.minutes > 59 || (*p)[сounter].time.minutes < 0) {
				printf_s("Ошибка ввода.\n");//дописать
			}
			else break;
		} while (1);
		/*if (((*p)[сounter].time.minutes / 10) == 0);*/
		printf_s("Вводите дату вылета.\n\t Введите год отправления:\n\t");
		do {
			if (!(scanf_s("%d", &(*p)[сounter].date.year))) {
				printf_s("Год вылета не может содержать букы, повторите ввод:\n");
				rewind(stdin);
			}
			else break;
		} while (1);
		printf_s("\tВведите месяц отправления:\n\t");
		do {
			if (!(scanf_s("%d", &(*p)[сounter].date.month))) {
				printf_s("Месяц вылета не может содержать букы, повторите ввод:\n");
				rewind(stdin);
			}
			else break;
		} while (1);
		printf_s("\tВведите день отправления:\n\t");
		do {
			if (!(scanf_s("%d", &(*p)[сounter].date.day))) {
				printf_s("День вылета не может содержать букы, повторите ввод:\n");
				rewind(stdin);
			}
			else break;
		} while (1);
		printf_s("Введите стоимость билета:\n\t");
		do {
			if (!(scanf_s("%d", &(*p)[сounter].cost))) {
				printf_s("Время вылета не может содержать букы, повторите ввод:\n");
				rewind(stdin);
			}
			else break;
		} while (1);
		printf_s("Если вы хотите продолжить заполнять базу данных, то введите всё, что угодно, кроме 0.\nИначе же нажмите 0:\n");
		do {
			if (!(scanf_s("%d", &end))) {
				system("CLS");
				printf_s("Всё - это все цифры, числа, но не буквы, повторите ввод.\n");
				rewind(stdin);
				continue;
			}
			else break;
		} while (1);
		system("CLS");
		сounter++;
		if (end == 0) break;
		*p = (flights*)realloc(*p, sizeof(flights) * (сounter + 1));
	} while (1);
	printf_s("=======================================================\n");
	printf_s("\tВозвращаем Вас в меню...\n");
	printf_s("=======================================================\n");
	menu(*p, сounter);
}
void printDatabase(flights* p, int amount) {
	printf_s("=======================================================\n\tВыводим вашу базу данных...\n");
	printf_s("=======================================================\n\n");
	for (int i = 0; i < amount; i++) {
		printf_s("\t\tРейс №%d\n\tНомер рейса:\t\t%d\n\tПункт назначения:\t%s ", i + 1, p[i].number, p[i].destination);
		printf_s("\n\tВремя вылета:\t\t%d:%d\n\t", p[i].time.hour, p[i].time.minutes);
		printf_s("Дата вылета:\t\t%d.%d.%d\n\tСтоимость билета:\t%d\n", p[i].date.year, p[i].date.month, p[i].date.day, p[i].cost);
		printf_s("--------------------------------------------------------\n");
	}
	menu(p, amount);
}
void sorting(flights** p, int amount) {
	int choose;
	system("CLS");
	printf_s("Вы выбрали пункт сортировка. Далее вам следует выбрать принципы сортировки:\n");
	printf_s("Введите цифру пункта, который Вы бы хотели отсортировать:\n1.По номеру.\n2.По назначению.\n3.По времени полета.\n");
	printf_s("4.По дате вылета.\n5.По стоимости билета.");
	scanf_s("%d", &choose);
	switch (choose) {
	case 1:
		sortingNumb(p, amount);
		return;
	case 2:
		sortingDestination(p, amount);
		return;
	case 3:
		sortingTime(p, amount);
		return;
	case 4:
		sortingDate(p, amount);
		return;
	/*case 5:
		sortingCost(p, amount);
		return;*/
	}

}
void sortingNumb(flights** p, int amount) {
	int i = 0;
	int choose = choosSortMet();
	printf_s("%d", choose);
	if (choose == 2) {
		while (i < amount) {
			for (int j = i; j < amount; j++) {
				if ((*p)[i].number > (*p)[j].number) raplace(p, i, j);
			}
			i++;
		}
	}
	else {
		while (i < amount) {
			for (int j = i; j < amount; j++) {
				if ((*p)[i].number < (*p)[j].number) {
					raplace(p, i, j);
				}
			}
			i++;
		}
	}
	system("CLS");
	printDatabase(*p, amount);
	menu(*p, amount);
}
void sortingDestination(flights** p, int amount) {
	int i = 0, j;
	system("cls");
	printf_s("Сортировка по назначению полета:\n");
	if (choosSortMet() == 1) {
		while (i < amount) {
			for (int j = i; j < amount; j++)
			if (strcmp((*p)[i].destination, (*p)[j].destination) < 0) raplace(p, i, j);
			i++;
		}
	}
	else while (i < amount) {
		for (int j = i; j < amount; j++)
			if (strcmp((*p)[i].destination, (*p)[j].destination) > 0) raplace(p, i, j);
		i++;
	}
	printDatabase(*p, amount);
	menu(*p, amount);
}
void raplace(flights**p, int i, int j) {
	flights *zam;
	zam = (flights*)malloc(sizeof(flights) * 1);
	*zam = (*p)[i];
	(*p)[i] = (*p)[j];
	(*p)[j] = *zam;
}
int choosSortMet() {
	printf_s("\n\tВыберите метод сортировки:\n1.По убыванию.\n2.По возрастанию.\n");
	int choose;
	do {
		if (!(scanf_s("%d", &choose))) {
			printf_s("Вводите только цифры.");
			rewind(stdin);
			continue;
		}
		else break;
	} while (1);
	if (choose == 1) return 1;
	else return 2;
}
void sortingTime(flights** p, int amount) {
	system("CLS");
	int i = 0;
	if (choosSortMet() == 1) {
		while (i < amount) {
			for (int j = i+1; j < amount; j++) {
				if ((*p)[i].time.hour < (*p)[j].time.hour) raplace(p, i, j);
				else if ((*p)[i].time.hour == (*p)[j].time.hour) {
					/*if ((*p)[i].time.minutes/10 == 0 && (*p)[j].time.minutes/10 > 0) raplace(p, i, j);*/
					if ((*p)[i].time.minutes < (*p)[j].time.minutes) raplace(p, i, j);
				}

			}
			i++;
		}
	}
	else 
		while (i < amount) {
			for (int j = i + 1; j > amount; j++) {
				if ((*p)[i].time.hour > (*p)[j].time.hour) raplace(p, i, j);
				else if ((*p)[i].time.hour == (*p)[j].time.hour) {
					if ((*p)[i].time.minutes > (*p)[j].time.minutes) raplace(p, i, j);
				}

			}
			i++;
		}
	printDatabase(*p, amount);
	menu(*p, amount);
}
void sortingDate(flights** p, int amount) {
	system("CLS");
	int i = 0;
	if (choosSortMet() == 1) {
		while (i < amount) {
			for (int j = i + 1; j < amount; j++) {
				if ((*p)[i].date.year < (*p)[j].date.year) raplace(p, i, j);
				else if ((*p)[i].date.year == (*p)[j].date.year) {
					if ((*p)[i].date.month < (*p)[j].date.month) raplace(p, i, j);
					else if ((*p)[i].date.month == (*p)[j].date.month)
						if ((*p)[i].date.day < (*p)[j].date.day) raplace(p, i, j);
				}

			}
			i++;
		}
	}
	else 
		while (i < amount) {
			for (int j = i + 1; j < amount; j++) {
				if ((*p)[i].date.year > (*p)[j].date.year) raplace(p, i, j);
				else if ((*p)[i].date.year == (*p)[j].date.year) {
					if ((*p)[i].date.month > (*p)[j].date.month) raplace(p, i, j);
					else if ((*p)[i].date.month == (*p)[j].date.month)
						if ((*p)[i].date.day > (*p)[j].date.day) raplace(p, i, j);
				}

			}
			i++;
		}
	printDatabase(*p, amount);
	menu(*p, amount);
}
void correctDatabase(flights** p, int amount) {
	int number, counter;
	system("CLS");
	printf_s("Введите номер рейса, в котором вы хотите внести изменения:\n");
	scanf_s("%d", &number);//интересная проверку сделай через сайзоф
	for(counter = 0; counter < amount; counter++) 
		if ((*p)[counter].number == number) break;
	if (counter == amount) {
		printf_s("Такого номера нету. Проверьте правильность введенных данных и повторите еще.");
		menu(*p, amount);
	}
	printf_s("=======================================================\n\t\tРейс №%d...\n",number);
	printf_s("=======================================================\n\n");
	printf_s("\tНомер рейса:\t\t%d\n\tПункт назначения:\t%s ", (*p)[counter].number, (*p)[counter].destination);
	printf_s("\n\tВремя вылета:\t\t%d:%d\n\t", (*p)[counter].time.hour, (*p)[counter].time.minutes);
	printf_s("Дата вылета:\t\t%d.%d.%d\n\tСтоимость билета:\t%d\n", (*p)[counter].date.year, (*p)[counter].date.month, (*p)[counter].date.day, (*p)[counter].cost);
	do {
		printf_s("--------------------------------------------------------\n");
		printf_s("Что вы хотите изменить?\n1.Номер рейса\n2.Место прибывания\n3.Время полета\n4.Дату вылета\n5.Цену билета\n");
		scanf_s("%d", &number);
		switch (number) {
		case 1:
			printf_s("\n--------------------------------------------------------\n");
			printf_s("Введите новый номер рейса:\n");
			scanf_s("%d", &(*p)[counter].number);
			break;
		case 2:
			printf_s("\n--------------------------------------------------------\n");
			printf_s("Введите новый пункт назначения:\n");
			rewind(stdin);
			fgets((*p)[counter].destination, 255, stdin);
			for (int j = 0; (*p)[counter].destination; j++) {
				if ((*p)[counter].destination[j] == '\n') {
					(*p)[counter].destination[j] = '\0';
					break;
				}
			}
			break;
		case 3:printf_s("\n--------------------------------------------------------\n");
			printf_s("Введите новое время:\nВведите часы полета:\n");
			do {
				if (!(scanf_s("%d", &(*p)[counter].time.hour))) {
					printf_s("Время вылета не может содержать букы, повторите ввод:\n");
					rewind(stdin);
				}
				if ((*p)[counter].time.hour > 23 || (*p)[counter].time.hour < 0) {
					printf_s("Ошибка ввода.\n");
				}
				else break;
			} while (1);
			printf_s("\tВведите минуты вылета:\n\t");
			do {
				if (!(scanf_s("%d", &(*p)[counter].time.minutes))) {
					printf_s("Время вылета не может содержать букы, повторите ввод:\n");
					rewind(stdin);
				}
				if ((*p)[counter].time.minutes > 59 || (*p)[counter].time.minutes < 0) {
					printf_s("Ошибка ввода.\n");
				}
				else break;
			} while (1);
			break;
		case 4:printf_s("\n--------------------------------------------------------\n");
			printf_s("Введите новую дату вылета:\nВведите год:\n");
			do {
				if (!(scanf_s("%d", &(*p)[counter].date.year))) {
					printf_s("Год вылета не может содержать букы, повторите ввод:\n");
					rewind(stdin);
				}
				else break;
			} while (1);
			printf_s("\tВведите месяц отправления:\n\t");
			do {
				if (!(scanf_s("%d", &(*p)[counter].date.month))) {
					printf_s("Месяц вылета не может содержать букы, повторите ввод:\n");
					rewind(stdin);
				}
				else break;
			} while (1);
			printf_s("\tВведите день отправления:\n\t");
			do {
				if (!(scanf_s("%d", &(*p)[counter].date.day))) {
					printf_s("День вылета не может содержать букы, повторите ввод:\n");
					rewind(stdin);
				}
				else break;
			} while (1);
			break;
		case 5:printf_s("\n--------------------------------------------------------\n");
			printf_s("Введите новую цену билета:\n");
			do {
				if (!(scanf_s("%d", &(*p)[counter].cost))) {
					printf_s("Время вылета не может содержать букы, повторите ввод:\n");
					rewind(stdin);
				}
				else break;
			} while (1);
		}
		printf_s("Нажмите любую клавишу, кроме нуля, если Вы хотите продолжить. Иначе нажмите 0(ноль) для завершения.\n");
		scanf_s("%d", &number);
	} while (number!=0);
	menu(*p, amount);
}
void deleteStruct(flights** p, int amount) {
	int number, counter;
	system("CLS");
	printf_s("Введите номер рейса, который хотите удалить:\n");
	scanf_s("%d", &number);//интересная проверку сделай через сайзоф
	for (counter = 0; counter < amount; counter++)
		if ((*p)[counter].number == number) break;
	if (counter == amount) {
		printf_s("Такого номера нету. Проверьте правильность введенных данных и повторите еще.");
		menu(*p, amount);
	}
	printf_s("=======================================================\n\t\tРейс №%d...\n", number);
	printf_s("=======================================================\n\n");
	printf_s("\tНомер рейса:\t\t%d\n\tПункт назначения:\t%s ", (*p)[counter].number, (*p)[counter].destination);
	printf_s("\n\tВремя вылета:\t\t%d:%d\n\t", (*p)[counter].time.hour, (*p)[counter].time.minutes);
	printf_s("Дата вылета:\t\t%d.%d.%d\n\tСтоимость билета:\t%d\n", (*p)[counter].date.year, (*p)[counter].date.month, (*p)[counter].date.day, (*p)[counter].cost);
	printf_s("%d", counter);
	for (counter; counter < amount; counter++, amount--) {
		if (amount == 1) {
			printf_s("Это единственный элемент, Вы действительно хотите его удалить и начать заного?\n1.Да\n2.Нет.\n");
			if (scanf_s("%d", &number) == 2) menu(*p, amount);
			else {
				free(*p);
				*p = (flights*)malloc(sizeof(flights) * 1);
				amount = 0;
				menu(*p, amount);
			}
		}
		else raplace(p, counter, counter + 1);
	}
	*p = (flights*)realloc(*p,sizeof(flights) * amount);
	menu(*p, amount);
}




//Структуру дата и через три инта++
//Еще надо сделать чтобы не было 67 минут и тд.; Заморочиться по поводу 02 (красивого времени) деление на 10;++
