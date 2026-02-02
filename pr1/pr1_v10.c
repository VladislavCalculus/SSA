#include <stdio.h>
#include <stdbool.h>

typedef enum {
JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
} month;

typedef enum {GREGORIAN, JULIAN} calendarType;

typedef struct {
	int day;
	month month;
	int year;
} date;

static inline bool is_leap(int year, calendarType cal){
	if(cal == JULIAN) {
		return (year%4 == 0);
	} else {
		return (year%4 == 0 && (year%100 != 0 || year%400 == 0));
	}
}

static inline int days_in_month(month m, int year, calendarType cal) {
		switch(m) {
		case FEB:
			return is_leap(year, cal) ? 29 : 28;
		case APR:
		case JUN:
		case SEP:
		 case NOV:
			return 30;
		default:
			return 31;
		}
}

date get_tomorrow(date d, calendarType cal) {
	date tmrw = d;
	int max_d = days_in_month(d.month, d.year, cal);
	if(d.day < max_d) {
		tmrw.day++;
	} else {
		tmrw.day = 1;
		if(d.month == DEC) {
			tmrw.month = JAN;
			tmrw.year++;
		} else {
			tmrw.month++;
		}
	}
	return tmrw;
}

int main() {
	calendarType clt = 0;
	printf("Select calendar type:\n0 - Gregorian\n1 - Julian: \n");

	int tmp_cal;
	if(scanf("%d", &tmp_cal) != 1) {
		printf("Invalid format\n");
		return 1;
	}
	if(tmp_cal == 1) clt = (calendarType)tmp_cal;

	int d, m, y;

	printf("Enter date in format DD MM YYYY: \n");
	if(scanf("%d %d %d", &d, &m, &y) != 3) {
		printf("Invalid format\n");
		return 1;
	}

	if(m > 12 || d > days_in_month(m, y, clt) || m < 1 || d < 1) {
		printf("Invalid day/month\n");
		return 1;
	}

	date tdy = {d, m, y};
	date tmrw = get_tomorrow(tdy, clt);
	printf("Tommorrow: %02d.%02d.%04d\nCalendar: %s", tmrw.day, tmrw.month, tmrw.year, clt==1 ? "Julian" : "Gregorian");
	return 0;
}

