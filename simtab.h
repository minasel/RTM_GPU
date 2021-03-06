/* Simbol Table for parameters. Implemented as a hash table. */
/*
  Copyright (C) 2004 University of Texas at Austin
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef _LARGEFILE_SOURCE
#define _LARGEFILE_SOURCE
#endif
#include <sys/types.h>
//#include <unistd.h>
/*^*/

#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <ctype.h>

#include <stdio.h>
/*^*/

//#include "simtab.h"
//#include "alloc.h"
//#include "error.h"

//#include "_bool.h"
/*^*/

#ifndef _sf_simtab_h

#define SF_EOL '\014'
#define SF_EOT '\004'
/*^*/

typedef struct sf_SimTab *sf_simtab; /* Simbol Table structure */
/*^*/

#endif

#ifdef _POSIX_ARG_MAX
#define LINELEN _POSIX_ARG_MAX
#else
#ifdef ARG_MAX
#define LINELEN ARG_MAX
#else
#define LINELEN 1024
#endif
#endif

struct entry {
    char *key, *val;
    struct entry* next;
};

struct sf_SimTab {
    struct entry **pars;
    int size;
};


static unsigned int hash (const char *key, int size); /* Taken from Kernigan and Pike, "The practice of programming" */

char *sf_simtab_get(sf_simtab table, const char *key); /*< extract a value from the table >*/

bool sf_simtab_getint(sf_simtab table, const char* key,/*@out@*/ int* par); /*< extract an int parameter from the table >*/






