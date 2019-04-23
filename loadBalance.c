/* Andre Augusto Giannotti Scota (a2gs)
 * andre.scota@gmail.com
 *
 * PAINEL
 *
 * MIT License
 *
 */


/* serv.c
 * Server creation.
 *
 *  Who     | When       | What
 *  --------+------------+----------------------------
 *   a2gs   | 23/04/2019 | Creation
 *          |            |
 */


/* *** INCLUDES ************************************************************************ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/* *** DEFINES AND LOCAL DATA TYPE DEFINATION ****************************************** */
typedef struct _range_t{
	unsigned long closedStart;
	unsigned long openedEnd;
}range_t;


/* *** FUNCTIONS *********************************************************************** */
int loadBalance(range_t *segs, unsigned int segments, unsigned long range, float offset)
{
	register unsigned int i = 0;
	float fDiv = 0.0;
	float fRange = 0.0;
	float fixedFloatRange = 0.0;

	fRange = 0.0;
	fixedFloatRange = (float)range;

	for(i = 0; i < segments - 1; i++){

		segs[i].closedStart = (unsigned long)trunc(fRange);

		fDiv = trunc(fixedFloatRange - fRange) / 2.0 * offset;

		segs[i].openedEnd = (unsigned long) (fDiv + fRange);

		fRange += fDiv;
	}

	segs[i].closedStart = (unsigned long)trunc(fRange);
	segs[i].openedEnd   = range;

	return(0);
}

int main(int argc, char *argv[])
{
	range_t *segs = NULL;
	unsigned int i = 0;
	unsigned int segments = 0;
	unsigned long range = 0;
	unsigned long grandTot = 0;
	float offset = 0;

	if(argc != 4){
		printf("Usage:\n%s <N_RANGES> [0 - <OPENED_END>[ <OFFSET ( [0.0 - 2.0] where 1.0=50%% )>\n", argv[0]);
		return(-1);
	}

	segments = (unsigned int) atoi(argv[1]);
	range    = (unsigned int) atol(argv[2]);
	offset   = atof(argv[3]);

	segs = (range_t *)malloc(sizeof(range_t) * segments);
	if(segs == NULL){
		printf("erro malloc()\n");
		return(-1);
	}

	memset(segs, 0, sizeof(range_t) * segments);

	if(loadBalance(segs, segments, range, offset) == -1){
		printf("erro loadBalance()\n");
		return(-1);
	}

	for(i = 0, grandTot = 0; i < segments; i++){
		printf("%u range: [%lu - %lu[\t\t\t(total of elements: %lu)\n", (i + 1), segs[i].closedStart, segs[i].openedEnd, (segs[i].openedEnd - segs[i].closedStart));
		grandTot += segs[i].openedEnd - segs[i].closedStart;
	}

	printf("\nGrand total: %lu\n", grandTot);

	free(segs);

	return(0);
}
