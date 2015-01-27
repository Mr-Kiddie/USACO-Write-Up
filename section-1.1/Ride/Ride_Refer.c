#include <stdio.h>
#include <ctype.h>

int
hash(char *s)
{
	int i, h;

	h = 1;
	for(i=0; s[i] && isalpha(s[i]); i++)
		h = ((s[i] - 'A' + 1)*h) % 47;

	return h;
}

int
main(void)
{
	FILE *in, *out;
	char comet[10], group[10];

	in = fopen("ride.in", "r");
	out = fopen("ride.out", "w");

	fgets(comet, sizeof(comet), in);
	fgets(group, sizeof(group), in);

	if(hash(comet) == hash(group))
		fprintf(out, "GO\n");
	else
		fprintf(out, "STAY\n");

	return 0;
}

