#include <stdio.h>
#include <windows.h>
#define N 10
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
flights* creator(flights*, int&);
void printDatabase(flights*, int);
void sorting(flights*, int);
void sortingNumb(flights*, int);
void sortingDestination(flights*, int);
void raplace(flights*, int, int);
int choosSortMet();
void sortingTime(flights*, int);
void sortingDate(flights*, int);
void correctDatabase(flights*, int);
void deleteStruct(flights*&, int&);
void search(flights*, int);
void scanfMod(int&);
//void partialMatchSearch(p, amount);

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
	do {
		printf_s("\nHello! Welcome to the <Flights.inc> - flight editor.\n\nSelect the action you want to take:\n");
		printf_s("1. Make a database.\n2. Print your database.\n3. Correct your database.\n4. Search by the specified parameter.\n");
		printf_s("5. Sorting a database by a given parameter.\n6. Deleting the selected database.\n0. Exit.");
		printf_s("Enter the number of the desired action:\n");
		do {
			if (!(scanf_s("%d", &paragraph))) {
				printf_s("\n=======================================================\n\t\t\tError!\n");
				printf_s("=======================================================\n\t\t    Enter number.\n");
				rewind(stdin);
				continue;
			}
			else break;
		} while (1);
		switch (paragraph) {
		case 1:
			p = creator(p, amount);
			break;
		case 2:
			printDatabase(p, amount);
			break;
		case 3:
			correctDatabase(p, amount);
			break;
		case 4:
			search(p, amount);
			break;
		case 5:
			sorting(p, amount);
			break;
		case 6:
			deleteStruct(p, amount);
			break;
			/*case 7:
				partialMatchSearch(p, amount);
				break;*/
		case 0:
			system("CLS");
			printf_s("Good bye. Have a nice day!");
			free(p);
			return;
		}
	} while (1);
}
flights* creator(flights* p, int& сounter) {
	int end = 1;
	system("CLS");
	printf_s("Hello. It's creator:\n");
	for (; end != 0; сounter++) {
		p = (flights*)realloc(p, sizeof(flights) * (сounter + 1));
		printf_s("It's a flight №%d. Enter information, following instructions.\nEnter nomber of flight:\n", сounter + 1);
		scanfMod(p[сounter].number);
		printf_s("Enter destination:\n");
		rewind(stdin);
		fgets(p[сounter].destination, 10, stdin);
		for (int j = 0; p[сounter].destination; j++) {
			if (p[сounter].destination[j] == '\n') {
				p[сounter].destination[j] = '\0';
				break;
			}
		}
		printf_s("Enter flight time.\n\tEnter hour:\n\t");
		do {
			scanfMod(p[сounter].time.hour);
			if (p[сounter].time.hour > 23 || p[сounter].time.hour < 0) {
				printf_s("Error.\n");//дописать
			}
			else break;
		} while (1);
		printf_s("\tEnter minutes:\n\t");
		do {
			scanfMod(p[сounter].time.minutes);
			if (p[сounter].time.minutes > 59 || p[сounter].time.minutes < 0) {
				printf_s("Error.\n");//дописать
			}
			else break;
		} while (1);
		/*if (((*p)[сounter].time.minutes / 10) == 0);*/
		printf_s("Enter date of flight.\n\t Enter year:\n\t");
		scanfMod(p[сounter].date.year);
		printf_s("\tEnter month:\n\t");
		do {
			if (!(scanf_s("%d", &p[сounter].date.month))) {
				printf_s("Error! Try again:\n");
				rewind(stdin);
			}
			else break;
		} while (1);
		printf_s("\tEnter day:\n\t");
		do {
			if (!(scanf_s("%d", &p[сounter].date.day))) {
				printf_s("Error! Try again:\n");
				rewind(stdin);
			}
			else break;
		} while (1);
		printf_s("Enter cost:\n\t");
		do {
			if (!(scanf_s("%d", &p[сounter].cost))) {
				printf_s("Error! Try again:\n");
				rewind(stdin);
			}
			else break;
		} while (1);
		printf_s("If you want to continue filling in the database, then enter anything other than 0.\nElse press 0\n");
		scanfMod(end);
		system("cls");
		//p = (flights*)realloc(p, sizeof(flights) * (сounter);
	}
	system("cls");
	printf_s("=======================================================\n");
	printf_s("\tRetun you to menu...\n");
	printf_s("=======================================================\n");
	return p;
}
void printDatabase(flights* p, int amount) {
	system("CLS");
	printf_s("=======================================================\n\tPrint your database...\n");
	printf_s("=======================================================\n\n");
	for (int i = 0; i < amount; i++) {
		printf_s("\t\tFlight №%d\n\tFlight number:\t%d\n\tDestination:\t%s ", i + 1, p[i].number, p[i].destination);
		printf_s("\n\tTime:\t\t%d:%d\n\t", p[i].time.hour, p[i].time.minutes);
		printf_s("Date:\t\t%d.%d.%d\n\tCost:\t\t%d\n", p[i].date.year, p[i].date.month, p[i].date.day, p[i].cost);
		printf_s("--------------------------------------------------------\n");
	}
}
void sorting(flights* p, int amount) {
	int choose;
	system("CLS");
	printf_s("You have selected sort.Next, you should choose the sorting principles:\n");
	printf_s("Enter the number of the item you would like to sort :\n1.By number of flight.\n2.By destination.\n3.By flight time.\n");
	printf_s("4.By departure date.\n5.By ticket price.");
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
void sortingNumb(flights* p, int amount) {
	int i = 0;
	int choose = choosSortMet();
	system("CLS");
	printf_s("%d", choose);
	if (choose == 2) {
		while (i < amount) {
			for (int j = i; j < amount; j++) {
				if (p[i].number > p[j].number) raplace(p, i, j);
			}
			i++;
		}
	}
	else {
		while (i < amount) {
			for (int j = i; j < amount; j++) {
				if (p[i].number < p[j].number) {
					raplace(p, i, j);
				}
			}
			i++;
		}
	}
	system("CLS");
	printDatabase(p, amount);
}
void sortingDestination(flights* p, int amount) {
	int i = 0, j;
	system("cls");
	printf_s("Sort by flight destination:\n");
	if (choosSortMet() == 1) {
		while (i < amount) {
			for (int j = i; j < amount; j++)
				if (strcmp(p[i].destination, p[j].destination) < 0) raplace(p, i, j);
			i++;
		}
	}
	else while (i < amount) {
		for (int j = i; j < amount; j++)
			if (strcmp(p[i].destination, p[j].destination) > 0) raplace(p, i, j);
		i++;
	}
	printDatabase(p, amount);
}
void raplace(flights* p, int i, int j) {
	flights* zam;
	zam = (flights*)malloc(sizeof(flights) * 1);
	*zam = p[i];
	p[i] = p[j];
	p[j] = *zam;
	free(zam);
}
int choosSortMet() {
	system("CLS");
	printf_s("\n\tSelect the sorting method:\n1.Descending order.\n2.Ascending order.\n");
	int choose;
	do {
		if (!(scanf_s("%d", &choose))) {
			printf_s("Enter only numbers.");
			rewind(stdin);
			continue;
		}
		else break;
	} while (1);
	if (choose == 1) return 1;
	else return 2;
}
void sortingTime(flights* p, int amount) {
	system("CLS");
	int i = 0;
	if (choosSortMet() == 1) {
		while (i < amount) {
			for (int j = i + 1; j < amount; j++) {
				if (p[i].time.hour < p[j].time.hour) raplace(p, i, j);
				else if (p[i].time.hour == p[j].time.hour) {
					/*if ((*p)[i].time.minutes/10 == 0 && (*p)[j].time.minutes/10 > 0) raplace(p, i, j);*/
					if (p[i].time.minutes < p[j].time.minutes) raplace(p, i, j);
				}

			}
			i++;
		}
	}
	else
		while (i < amount) {
			for (int j = i + 1; j < amount; j++) {
				if (p[i].time.hour > p[j].time.hour) raplace(p, i, j);
				else if (p[i].time.hour == p[j].time.hour) {
					if (p[i].time.minutes > p[j].time.minutes) raplace(p, i, j);
				}

			}
			i++;
		}
	printDatabase(p, amount);
	return;
}
void sortingDate(flights* p, int amount) {
	system("CLS");
	int i = 0;
	if (choosSortMet() == 1) {
		while (i < amount) {
			for (int j = i + 1; j < amount; j++) {
				if (p[i].date.year < p[j].date.year) raplace(p, i, j);
				else if (p[i].date.year == p[j].date.year) {
					if (p[i].date.month < p[j].date.month) raplace(p, i, j);
					else if (p[i].date.month == p[j].date.month)
						if (p[i].date.day < p[j].date.day) raplace(p, i, j);
				}

			}
			i++;
		}
	}
	else
		while (i < amount) {
			for (int j = i + 1; j < amount; j++) {
				if (p[i].date.year > p[j].date.year) raplace(p, i, j);
				else if (p[i].date.year == p[j].date.year) {
					if (p[i].date.month > p[j].date.month) raplace(p, i, j);
					else if (p[i].date.month == p[j].date.month)
						if (p[i].date.day > p[j].date.day) raplace(p, i, j);
				}

			}
			i++;
		}
	printDatabase(p, amount);
	return;
}
void correctDatabase(flights* p, int amount) {
	int number, counter;
	system("CLS");
	printf_s("Enter the flight number you want to make changes to:\n");
	scanf_s("%d", &number);//интересная проверка сделай через сайзоф**
	for (counter = 0; counter < amount; counter++)
		if (p[counter].number == number) break;
	if (counter == amount) {
		printf_s("There is no such number.Check that the data you entered is correct and repeat again.");
	}
	printf_s("=======================================================\n\t\tРейс №%d...\n", number);
	printf_s("=======================================================\n\n");
	printf_s("\tFlight number:\t%d\n\tDestination:\t%s ", p[counter].number, p[counter].destination);
	printf_s("\n\tTime:\t\t%d:%d\n\t", p[counter].time.hour, p[counter].time.minutes);
	printf_s("Date:\t\t%d.%d.%d\n\tCost:\t\t%d\n", p[counter].date.year, p[counter].date.month, p[counter].date.day, p[counter].cost);
	do {
		printf_s("--------------------------------------------------------\n");
		printf_s("What do you want to choose?\n1.Number of flight\n2.Destination\n3.Time\n4.Date\n5.Ticket prise\n");
		scanf_s("%d", &number);
		switch (number) {
		case 1:
			printf_s("\n--------------------------------------------------------\n");
			printf_s("Enter new nomber of flight:\n");
			scanf_s("%d", &p[counter].number);
			break;
		case 2:
			printf_s("\n--------------------------------------------------------\n");
			printf_s("Enter a new destination:\n");
			rewind(stdin);
			fgets(p[counter].destination, 10, stdin);
			for (int j = 0; p[counter].destination; j++) {
				if (p[counter].destination[j] == '\n') {
					p[counter].destination[j] = '\0';
					break;
				}
			}
			break;
		case 3:printf_s("\n--------------------------------------------------------\n");
			printf_s("Enter the new time:\nEnter your flight hours:\n");
			do {
				if (!(scanf_s("%d", &p[counter].time.hour))) {
					printf_s("Error! Try again:\n");
					rewind(stdin);
				}
				if (p[counter].time.hour > 23 || p[counter].time.hour < 0) {
					printf_s("Error.\n");
				}
				else break;
			} while (1);
			printf_s("\tEnter minutes:\n\t");
			do {
				if (!(scanf_s("%d", &p[counter].time.minutes))) {
					printf_s("Error! Try again:\n");
					rewind(stdin);
				}
				if (p[counter].time.minutes > 59 || p[counter].time.minutes < 0) {
					printf_s("Error! Try again.\n");
				}
				else break;
			} while (1);
			break;
		case 4:printf_s("\n--------------------------------------------------------\n");
			printf_s("Enter new date of flight:\nEnter year:\n");
			do {
				if (!(scanf_s("%d", &p[counter].date.year))) {
					printf_s("Error! Try again.\n");
					rewind(stdin);
				}
				else break;
			} while (1);
			printf_s("\tEnter month:\n\t");
			do {
				if (!(scanf_s("%d", &p[counter].date.month))) {
					printf_s("Error! Try again.:\n");
					rewind(stdin);
				}
				else break;
			} while (1);
			printf_s("\tEnter day:\n\t");
			do {
				if (!(scanf_s("%d", &p[counter].date.day))) {
					printf_s("Error! Try again.:\n");
					rewind(stdin);
				}
				else break;
			} while (1);
			break;
		case 5:printf_s("\n--------------------------------------------------------\n");
			printf_s("Enter new ticket price:\n");
			do {
				if (!(scanf_s("%d", &p[counter].cost))) {
					printf_s("Error! Try again.:\n");
					rewind(stdin);
				}
				else break;
			} while (1);
		}
		printf_s("Press any key other than zero if you want to continue. Otherwise, press 0 (zero) to complete.\n");
		scanf_s("%d", &number);
	} while (number != 0);
	return;
}
void deleteStruct(flights* &p, int &amount) {// как 
	int number, counter;
	system("CLS");
	printf_s("Enter the flight number you want to delete:\n");
	scanf_s("%d", &number);//интересная проверку сделай через сайзоф
	for (counter = 0; counter < amount; counter++)
		if (p[counter].number == number) break;
	if (counter == amount) {
		printf_s("There is no such number. Check that the data you entered is correct and repeat again.");
		return;
	}
	printf_s("=======================================================\n\t\tFlight №%d...\n", number);
	printf_s("=======================================================\n\n");
	printf_s("\tFlight number:\t%d\n\tDestination:\t%s ", p[counter].number, p[counter].destination);
	printf_s("\n\tTime of flight:\t\t%d:%d\n\t", p[counter].time.hour, p[counter].time.minutes);
	printf_s("Date:\t\t%d.%d.%d\n\tTicket cost:\t\t%d\n", p[counter].date.year, p[counter].date.month, p[counter].date.day, p[counter].cost);
	printf_s("Are you shure?\n1.Yes\n2.No\n");
	scanf_s("%d", &number);
	if (number == 2)
		return;
	if (amount == 1) {
		printf_s("This is the only flight, are you sure?\n1. Yes\n2. No");
		scanf_s("%d", &number);
		if (number == 2) return;
		amount--;
		p = (flights*)malloc(sizeof(flights) * 1);
		return;
	}
	for (; counter < amount; counter++) {
		p[counter] = p[counter + 1];
	}
	amount--;
	p = (flights*)realloc(p, sizeof(flights) * (amount));
	return;

}
void search(flights* p, int amount) {
	int number;
	system("CLS");
	printf_s("Hi, what area are we looking for?\n1. By flight number.\n2. By destination.\n3. By flight time.\n4. By flight date.\n5. By ticket cost.\n");
	do {
		printf_s("Enter number: ");
		if (!(scanf_s("%d", &number))) {
			printf_s("Try again\n");
			rewind(stdin);
		}
		else break;
	} while (1);
	switch (number) {
	case 1:
		system("CLS");
		do {
			printf_s("Enter the flight number: ");
			if (!(scanf_s("%d", &number))) {
				printf_s("Eroro! Try again:\n");
				rewind(stdin);
			}
			else break;
		} while (1);
		for (int count = 0; count < amount; count++) {
			if ((p)[count].number == number) {
				printf_s("=======================================================\n\t\tРейс №%d...\n", number);
				printf_s("=======================================================\n\n");
				printf_s("\tFlight number:\t%d\n\tDestination:\t%s ", p[amount].number, p[amount].destination);
				printf_s("\n\tTime of flight:\t\t%d:%d\n\t", p[amount].time.hour, p[amount].time.minutes);
				printf_s("Date:\t\t%d.%d.%d\n\tTicket cost:\t\t%d\n", p[amount].date.year, p[amount].date.month, p[amount].date.day, p[amount].cost);
			}
		}
		printf_s("=======================================================\n");
		return;

	case 2:
		char* destination;
		destination = (char*)malloc(sizeof(char) * 100);
		printf_s("Enter destination:\n");
		rewind(stdin);
		fgets(destination, 255, stdin);
		for (int j = 0; *(destination - 1) != '\n'; j++) {
			if (destination[j] == '\n') {
				destination[j] = '\0';
				break;
			}
		}
		number = 0;
		for (int count = 0; count < amount; count++) {
			if ((strcmp(destination, p[count].destination)) == 0) {
				printf_s("=======================================================\n\t\tРейс №%d...\n", count + 1);
				printf_s("=======================================================\n\n");
				printf_s("\tFlight number:\t%d\n\tDestination:\t%s ", p[amount].number, p[amount].destination);
				printf_s("\n\tTime of flight:\t\t%d:%d\n\t", p[amount].time.hour, p[amount].time.minutes);
				printf_s("Date:\t\t%d.%d.%d\n\tTicket cost:\t\t%d\n", p[amount].date.year, p[amount].date.month, p[amount].date.day, p[amount].cost);
				number++;
			}
		}
		if (number == 0) printf_s("There are no matches");
		printf_s("=======================================================\n");
		return;
	case 3:
		int hour, min;
		do {
			printf_s("Enter the hour: ");
			if (!(scanf_s("%d", &hour))) {
				printf_s("Eror! Try again:\n");
				rewind(stdin);
			}
			else break;
		} while (1);
		do {
			printf_s("Enter the minute of departure: ");
			if (!(scanf_s("%d", &min))) {
				printf_s("Error! Try again:\n");
				rewind(stdin);
			}
			else break;
		} while (1);
		for (int count = 0; count < amount; count++) {
			if ((p)[count].time.hour == hour)
				if ((p)[count].time.minutes == min) {
					printf_s("=======================================================\n\t\tFlight №%d...\n", count + 1);
					printf_s("=======================================================\n\n");
					printf_s("\tFlight number:\t%d\n\tDestination:\t%s ", p[amount].number, p[amount].destination);
					printf_s("\n\tTime of flight:\t\t%d:%d\n\t", p[amount].time.hour, p[amount].time.minutes);
					printf_s("Date:\t\t%d.%d.%d\n\tTicket cost:\t\t%d\n", p[amount].date.year, p[amount].date.month, p[amount].date.day, p[amount].cost);
					number++;
				}
			if (number == 0) printf_s("There are no matches");
			printf_s("=======================================================\n");
			return;
		}


	}
}
void scanfMod(int& number) {
	do {
		if (!(scanf_s("%d", &number))) {
			printf_s("\nEror! Number isn't latter\n");
			rewind(stdin);
		}
		else break;
	} while (1);

}
