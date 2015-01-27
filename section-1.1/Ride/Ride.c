/*
Auther: naix
LANG: C
PROG: ride
*/
#include <stdio.h>

#define STR_LEN 10

int encode(char *str);
 
int main()
{
	//definition of file pointer
	FILE* fin = fopen("ride.in", "r");
	FILE* fout = fopen("ride.out", "w");

	//definition of all variables	
	int GrpCode, CmtCode;
	char Grp[STR_LEN] = "", Cmt[STR_LEN] = "";

	//get the input data from ride.in
	fscanf(fin, "%s", Cmt);
	fscanf(fin, "%s", Grp);

/********************Main Parts********************/
	//encode the input string 
	GrpCode = encode(Grp);
	CmtCode = encode(Cmt);

	//judge the conditon
	if((GrpCode % 47) == (CmtCode % 47)) {
		fprintf(fout, "GO\n");
	} else {
		fprintf(fout, "STAY\n");
	}
		
	return 0;
}

/*
definition: 
	int encode(char *str);
argument:
	char *str - get the original string
return value:
	return the code value of the string
*/
int encode(char *str) {
	int i, code = 0;

	for(i=0; str[i] != '\0'; i++) {
		if(code == 0) {
			code = (int)(str[i] - 'A') + 1;
		} else {
			code *= ((int)(str[i] - 'A') + 1);
		}
	}
	
	return code;
}
	
