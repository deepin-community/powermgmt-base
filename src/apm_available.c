/*
Copyright (c) 2002  J. D. Thomas Hood <jdthood@yahoo.co.uk>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
02110-1301, USA.  */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define APM_DEVICE "/dev/apm_bios"
#define APM_PROC "/proc/apm"

int
main (int argc, const char * argv[])
{
	FILE *fp;
	int r;

	if (argc != 1)
	  {
	    fprintf (stderr, "usage: %s\n", (argv[0]));
	    fflush (stderr);
	    exit (2);
	  }

	r = access(APM_PROC, R_OK);
	if (r==0)
		exit(0);

	/*
	 * Try to induce apm module load
	 */
	fp = fopen(APM_DEVICE, "r");
	if (fp) {
		r = fclose(fp);
		if (r)
			exit(errno);
	}

	r = access(APM_PROC, R_OK);
	if (r==0)
		exit(0);

	exit(1);
}
