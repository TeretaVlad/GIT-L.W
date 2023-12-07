#include <iostream>

typedef struct {
	char last_name[15];
	char initials[4];
	char birthplace[10];
	char place_of_residence[10];
	int age;
	int work_experiance;
} person;

int func(int a, int b) {
	int c = 0;
	c = a + b;
	return c;
}

/*Функція, що ініціалізує нового працівника і додає його до масиву*/
person *add_inf(person *workers, int *psize) {
	person NewWorker = {NULL, NULL, NULL, NULL, NULL, NULL};
	printf("Enter information about new worker\n\n");
	printf("Enter a last name\n");
	scanf_s("%s", NewWorker.last_name, sizeof(NewWorker.last_name));
	printf("Enter initials\n");
	scanf_s("%s", NewWorker.initials, sizeof(NewWorker.initials));
	printf("Enter a birthplace\n");
	scanf_s("%s", NewWorker.birthplace, sizeof(NewWorker.birthplace));
	printf("Enter a place of residence\n");
	scanf_s("%s", NewWorker.place_of_residence, sizeof(NewWorker.place_of_residence));
	printf("Enter an age\n");
	scanf_s("%d", &NewWorker.age);
	printf("Enter a work expiroance\n");
	scanf_s("%d", &NewWorker.work_experiance);
	workers = (person*)realloc(workers, (*psize + 1) * sizeof(person));
	workers[*psize] = NewWorker;
	(*psize)++;
	return workers;
}

/*Функція, що виводить на екран інформацію про всіх працівників в масиві*/
void output_inf(person *workers, int size) {
	printf("Workers:\n");
	for (int i = 0; i < size; i++) {
		printf("----------------------------\n");
		printf("\tWorker %s %s\n", workers[i].last_name, workers[i].initials);
		printf("Birthplace: %s\n", workers[i].birthplace);
		printf("Place of residence: %s\n", workers[i].place_of_residence);
		printf("Age: %d\n", workers[i].age);
		printf("Work expiroance: %d\n\n", workers[i].work_experiance);
		printf("----------------------------\n");
	}
}

/*Функція, що переставляє 2 структури місцями*/
void replace(person *a, person *b) {
	person k = *a;
	*a = *b;
	*b = k;
}

/*Функція, що сортує працівників за прізвищем (За алфавітом від A до Z)*/
/*Принцип роботи полягає в тому, що функція порівнює ASCII код першого символу прізвища,
чим ближча літера до початку алфавіту тим менше число їй відповідає у коді ASCII*/
void sort_lname(person *workers, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j > i; j--) {
			if (("%d", workers[j].last_name[0]) < ("%d", workers[j-1].last_name[0])) {//порівнює 1 літеру
				replace(&workers[j], &workers[j-1]);
			}
			if (("%d", workers[j].last_name[0]) == ("%d", workers[j-1].last_name[0])) {
				if (("%d", workers[j].last_name[1]) < ("%d", workers[j-1].last_name[1])) {//порівнює 2 літеру, якщо 1 однакова
					replace(&workers[j], &workers[j-1]);
				}
				if (("%d", workers[j].last_name[1]) == ("%d", workers[j-1].last_name[1])) {
					if (("%d", workers[j].last_name[2]) < ("%d", workers[j-1].last_name[2])) {//порівнює 3 літеру, якщо 2 однакова
						replace(&workers[j], &workers[j-1]);
					}
					if (("%d", workers[j].last_name[2]) == ("%d", workers[j-1].last_name[2])) {
						if (("%d", workers[j].last_name[3]) < ("%d", workers[j-1].last_name[3])) {//порівнює 4 літеру, якщо 3 однакова
							replace(&workers[j], &workers[j-1]);
						}
					}
				}
			}
		}
	}
}

/*Функція, що сортує працівників за стажем (від меншого до більшого)*/
void sort_work_exp(person *workers, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j > i; j--) {
			if (workers[j].work_experiance < workers[j-1].work_experiance) {
				replace(&workers[j], &workers[j-1]);
			}
		}
	}
}

int main() {
	person *workers = NULL;//оголошення та ініціалізація масиву
	int size = 0;

	/*Вручну шніціалізовані і занесені до масиву 2 перші структури (як вказано в завданні)*/
	person worker1 = {"Kovalenko", "AV", "Dnipro", "Lviv", 25, 4};
	person worker2 = {"Shevchenko", "VD", "Kherson", "Kuiv", 37, 17};
	workers = (person*)realloc(workers, 2 * sizeof(person));
	workers[0] = worker1;
	workers[1] = worker2;
	size = 2;

	/*Наступний блок забезпечує багаторазове використання програми*/
	int i = 1;
	while (i != 0) {
		printf("-----------------------------------------\n\
|Enter \"1\" to input info about worker   |\n\
|Enter \"2\" to output info about workers |\n\
|Enter \"3\" to sort for last name        |\n\
|Enter \"4\" to sort for work experiance  |\n\
|Enter \"0\" to stop                      |\n\
-----------------------------------------\n");
		scanf_s("%d", &i);
		/*викликає вибрану функцію, або зупиняє код*/
		switch (i) {
		case 1:
			workers = add_inf(workers, &size);
			break;
		case 2:
			output_inf(workers, size);
			break;
		case 3:
			sort_lname(workers, size);
			break;
		case 4:
			sort_work_exp(workers, size);
			break;
		case 0:
			i = 0;
			break;
		default: 
			printf("You have to enter 1, 2, 3, 4 or 0\n");
		}
	}

	return 0;
}