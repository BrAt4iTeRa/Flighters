#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define SIZE 15
#define SIZE_DATE 10
union unions {
	char date[SIZE_DATE];
	int number;
};
struct tvSerias {
	int flg;
	int quantitySerias;
	char* title;
	unions unIon;
};

void menu(tvSerias*, int);
tvSerias* creator(tvSerias*, int&);
void scanfMod(int&);
void printDatabase(tvSerias*, int);

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	tvSerias* p = nullptr;
	p = (tvSerias*)malloc(sizeof(tvSerias) * 1);
	if (p == nullptr) {
		printf("No memory.");
		return;
	}
	int counter = 0;
	menu(p, counter);
	free(p);
	return;
}

void menu(tvSerias* p, int counter) {
	int number;
	do {
		printf_s("Hello, welcome...\n Select the action you want to perform\n1.Create a database.\n");
		scanf_s("%d", &number);
		switch (number) {
		case 1:
			p = creator(p, counter);
			break;
		case 2:
			printDatabase(p, counter);
			break;
		case 0:
			printf("Goodbye.See you later!");
			return;
		}
	} while (1);

}
tvSerias* creator(tvSerias* p, int& counter) {
	int end = 1, number;
	system("CLS");
	printf("Hello! It's creator:\n");
	for (; end != 0; counter++) {
		p = (tvSerias*)realloc(p, sizeof(tvSerias) * (counter + 1));
		printf_s("\tThis is a TV serial ¹%d.\nEnter the information by following the instructions.\nEnter the number of episodes:\n", counter + 1);
		scanfMod(p[counter].quantitySerias);
		printf("Enter the name of the series:\n");
		p[counter].title = (char*)malloc(sizeof(char) * SIZE);
		rewind(stdin);
		fgets(p[counter].title, SIZE, stdin);
		for (int j = 0; p[counter].title; j++) {
			if (p[counter].title[j] == '\n') {
				p[counter].title[j] = '\0';
				break;
			}
		}
		printf("What do you want to do?\n1. Release date.\n2. The number of seasons.\n");
		scanfMod(number);
		if (number == 1) {
			printf("Enter release date in form of yyyymmdd, where dd is day, mm is month.\n");
			rewind(stdin);
			fgets(p[counter].unIon.date, SIZE_DATE, stdin);
			for (int j = 0; ; j++) {/////////////////////////////////////////////////
				if (p[counter].unIon.date[j] == '\n') {
					p[counter].unIon.date[j] = '\0';
					break;
				}
			}
			p[counter].flg = 1;
		}
		else if (number == 2) {
			printf("Enter the number of seasons:\n");
			scanfMod(p[counter].unIon.number);
			p[counter].flg = 2;
		}
		number = 0;
		printf("If you want to continue, enter all but 0:\n");
		scanfMod(end);
		system("cls");

	}
	return p;
}
void printDatabase(tvSerias* p, int counter) {
	system("CLS");
	printf_s("=======================================================\n\t\tYour database\n");
	printf_s("=======================================================\n||   TV series   ||   Number of series   ||   Title   ||   Release date   ||   Number of seasons   ||");
	for (int i = 0; i < counter; i++) {
		                                                       printf("\n||---------------||----------------------||-----------||------------------||-----------------------||\n");
		printf_s("||\t%d\t ||\t%d\t||\t%s\t||", i + 1, p[i].quantitySerias, p[i].title);
		if (p[i].flg == 1) {
			printf("\t%s\t||", p[i].unIon.date);
			printf("\t-\t||");
		}
		else if (p[i].flg == 2) {
			printf("\t-\t||");
			printf("\t%d\t||", p[i].unIon.number);
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

//int end = 1, number, trigle = 0;
//system("CLS");
//printf("Hello, its creator.\n");
//for (; end != 0; counter++) {
//	p = (tvSerias*)realloc(p, sizeof(tvSerias) * (counter + 1));
//	printf_s("\tThis is a TV serial ¹%d.\nEnter the information by following the instructions.\nEnter the number of episodes:\n", counter + 1);
//	scanfMod(p[counter].quantitySerias);
//	printf("Enter the name of the series:\n");
//	p[counter].title = (char*)malloc(sizeof(char) * SIZE);
//	rewind(stdin);
//	fgets(p[counter].title, SIZE, stdin);
//	for (int j = 0; p[counter].title; j++) {
//		if (p[counter].title[j] == '\n') {
//			p[counter].title[j] = '\0';
//			break;
//		}
//	}
//	printf("Choose, what you want to write?\n1. Release date.\n2. The number of seasons.\n");
//	scanfMod(number);
//	if (number == 1) {
//		do {
//			printf("Enter release date in form of yyyymmdd, where dd is day, mm is month.\n");//dopisat
//			rewind(stdin);
//			gets_s(p[counter].date);
//
//		} while (trigle == 1);
//		p[counter].flg = 1;
//	}
//	else {
//		printf("Enter the number of seasons:\n");
//		scanfMod(p[counter].number);
//		p[counter].flg = 2;
//	}
//	printf("If you want to continue, enter all but 0:\n");
//	scanfMod(end);
//	system("cls");
//}
//system("cls");
//printf_s("=======================================================\n");
//printf_s("\tReturn you in menu...\n");
//printf_s("=======================================================\n");
//return;
//