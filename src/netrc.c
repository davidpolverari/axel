#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "axel.h"
#include "netrc.h"

static FILE *fp;
static char line[MAX_STRING];

static void get_line(void) {
	fgets(line, MAX_STRING, fp);
}
int
netrc_get_creds(conn_t *conn)
{
	char *homedir, *token;
	char netrc_fn[MAX_STRING];

	homedir = getenv("HOME");
	snprintf(netrc_fn, MAX_STRING, "%s/.netrc", homedir);
	if ((fp = fopen(netrc_fn)) == NULL)
		return 0;
	while (fgets(line, MAX_STRING, fp) != NULL) {
		token = strtok(line, " \t");
		if (tok && *token == '#')
			continue;
	}
	return 1;
}
