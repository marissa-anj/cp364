void t1();
void t2();
void t3();

main() {
	t1();
	printf("\n");
	t2();
	printf("\n");
	t3();
	return 0;
}

void t1() {
		int tall, shortt;
		int total;
		char symbol = 84;
		const int val = 43;
		double average;

		printf("Enter number of tall trees: ");
		scanf("%d", &tall);
		printf("Enter number of short trees: ");
		scanf("%d", &shortt);
		total = tall + shortt;
		average = (double) val / total;
		//printing report

		printf("Number of %c trees = %d\n", symbol, tall);
		printf("Number of %c trees = %d\n", symbol-1, shortt);
		printf("Average height = %.2lf", average);
	    return;
}

void t2(){
    unsigned int year;
	short month;
	int day;
	char university[30];

	printf("Enter year: ");
	scanf("%u", &year);

	printf("Enter month: ");
	scanf("%hi", &month);

	printf("Enter day: ");
	scanf("%d", &day);

	printf("Enter University: ");
	scanf("%s", university);

	printf("This is %s University\n", university);
	printf("Today is: %d/%d/%d", day, month, year);
	return;
}

void t3(){
	//
	printf("Hints for C Language:\n");
	printf("Insert \\n at end of printf for newline.\n");
	printf("Use \"double quote\" not \'single quotes\' for strings.\nUse %%d for integer, %%f for float and %%lf for double.\n");
	return;
}