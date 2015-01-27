/*
Auther: naix
LANG: C
PROG: beads
*/
#include <stdio.h>

#define BEADS_NUM	700

int 
main(void)
{
	FILE *fin, *fout;
	char NECKLACE[BEADS_NUM], bead;
	int num_of_beads, i, j, flag = 1, cnt = 0, tmp = 0;
	
	fin = fopen("beads.in", "r");
	fout = fopen("beads.out", "w");

	fscanf(fin, "%d\n", &num_of_beads);
	fgets(NECKLACE, num_of_beads + 1, fin);

	for(i=0; i<num_of_beads; i++) {
		NECKLACE[i+num_of_beads] = NECKLACE[i];
	}

	NECKLACE[i+num_of_beads] = '\0';

	for(i=0; i<num_of_beads; i++) {
		j = i;

		while(NECKLACE[j] == 'w'&& tmp < num_of_beads) {
			tmp++;
			j++;
		}
			
		bead = NECKLACE[j];
	
		while(flag != -1 && tmp < num_of_beads) {
			if(NECKLACE[j] == bead || NECKLACE[j] == 'w') {
				tmp++;
			} else {
				if(flag) {
					tmp++;
					flag--;
					
					bead = NECKLACE[j];
				} else {
					flag--;
				}
			}	
			
			j++;
		}

		if(tmp > cnt) {
			cnt = tmp;
		}

		tmp = 0;
		flag = 1;
 	}

	fprintf(fout, "%d\n", cnt);	

	return 0;
}

