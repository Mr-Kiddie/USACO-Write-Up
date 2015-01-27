/*
Auther: naix
LANG: C
PROG: friday
*/
#include <stdio.h>

#define MONTH_NUM 	12
#define WEEK_DAYS	7

int Month[MONTH_NUM] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int WeekDays[WEEK_DAYS] = {0};

int MonthJudge(int days, int month) {
	WeekDays[(days+14)%7]++;
	days += Month[month];

	return days%7;
}

int
main(void)
{
	FILE *fin, *fout;
	
	int n, i, j, days = 0;

	fin = fopen("friday.in", "r");
	fout = fopen("friday.out", "w");

	fscanf(fin, "%d", &n);

	for(i=0; i<n; i++) {
		if((1900+i)%4 != 0 || ((1900+i)%400 != 0 && (1900+i)%100 == 0))
			Month[1] = 28;
		else 
			Month[1] = 29;

		for(j=0; j<MONTH_NUM; j++) {
			days = MonthJudge(days, j);			
		}
	}

	for(i=0; i<WEEK_DAYS-1; i++) {
		fprintf(fout, "%d ", WeekDays[i]);
	}

	fprintf(fout, "%d\n", WeekDays[i]);

	return 0;
}
 
