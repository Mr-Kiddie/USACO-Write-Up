/*
Auther: naix
LANG: C
PROG: gift1
*/
#include <stdio.h>
#include <string.h>

#define NAME_LEN 	20
#define NP_SIZE		15
	
typedef struct _member{
	char memberName[NAME_LEN];
	int cash;
}member;

void initial(member *mem, char *name, int cash, int num); 
void transaction(member *mem, char *name, int cash, int num); 

int
main(void)
{
	FILE *fin, *fout;

	int NP, i, j, cash, num;
	char name[NAME_LEN];	
	member Grp[NP_SIZE];

	//get the file pointer
	fin = fopen("gift1.in", "r");
	fout = fopen("gift1.out", "w");

	fscanf(fin, "%d", &NP);
	
	//initial the group info
	for(i=0; i<NP; i++) {
		fscanf(fin, "%s", Grp[i].memberName);
		Grp[i].cash = 0;
	}

	//main processing part
	for(i=0; i<NP; i++) {
		fscanf(fin, "%s", name);	
		fscanf(fin, "%d%d", &cash, &num);
	
		initial(Grp, name, cash, num);	
		
		//transaction part
		for(j=0; j<num; j++) {
			fscanf(fin, "%s", name);
			transaction(Grp, name, cash, num);	
		}
	}

	for(i=0; i<NP; i++) {
		fprintf(fout, "%s %d\n", Grp[i].memberName, Grp[i].cash);
	}

	return 0;
}

void
initial(member *mem, char *name, int cash, int num) {
	int i;

	for(i=0; i<NP_SIZE; i++) {
		if(strcmp(mem[i].memberName, name) == 0) {
			if(num != 0 && cash != 0) {	
				mem[i].cash = mem[i].cash - cash + (cash%num);
			}

			break;
		}
	}
			 
	return;
}

void 
transaction(member *mem, char *name, int cash, int num) {
	int i;
	
	for(i=0; i<NP_SIZE; i++) {
		if(strcmp(mem[i].memberName, name) == 0 && cash != 0 && num != 0) {
			mem[i].cash += (int)(cash/num);
			break;
		}
	}
}
	
