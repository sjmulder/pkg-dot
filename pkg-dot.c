/* pkg-dot.c - Copyright (c) 2018, Sijmen J. Mulder (see LICENSE) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char **argv)
{
	char	*curpkg	= NULL;
	char	*line	= NULL;
	size_t	 linecap;
	ssize_t	 len;

	puts("digraph {");

	while ((len = getline(&line, &linecap, stdin)) != -1) {
		if (*line != '\t') {
			/* "package-1.2:" */
			free(curpkg);
			curpkg = line;
			curpkg[len-2] = '\0';
			line = NULL;
			printf("\t \"%s\"\n", curpkg);
		} else if (curpkg) {
			/* "\tdependency-2.3" */
			printf("\t \"%s\" -> \"%.*s\"\n", curpkg,
			    (int)(len-2), line+1);
		}
	}

	if (!feof(stdin)) {
		perror(NULL);
		return 1;
	}

	puts("}");
	return 0;
}
