#ifndef APP_DEBUG_H
#define APP_DEBUG_H

#ifdef	DEBUG_MODE
	#if	(DEBUG_MODE	== 1)

		#include <stdlib.h>
		#include <stdio.h>

		#define	DEBUG_STR(str)						printf(str)
		#define	DEBUG_1_ARG(str, val1)				printf(str, val1)
		#define	DEBUG_2_ARG(str, val1, val2)		printf(str, val1, val2)
	#else

		#define	DEBUG_STR(str)
		#define	DEBUG_1_ARG(str, val1)
		#define	DEBUG_2_ARG(str, val1, val2)

	#endif
#else
	#define	DEBUG_STR(str)
	#define	DEBUG_1_ARG(str, val1)
	#define	DEBUG_2_ARG(str, val1, val2)

#endif

#endif
