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

#define ACPI_PROC "/proc/acpi"

int
main (int argc, const char * argv[])
{
	int r;

	if (argc != 1)
	  {
	    fprintf (stderr, "usage: %s\n", (argv[0]));
	    fflush (stderr);
	    exit (2);
	  }

	r = access(ACPI_PROC, X_OK);
	if (r==0)
		exit(0);

	/* Should try to get the acpi modules loaded here */

	exit(1);
}
