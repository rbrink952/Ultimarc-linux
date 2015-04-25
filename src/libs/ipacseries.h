/*
 ============================================================================
 Name        : ipacseries.h
 Author      : Katie Snow
 Version     :
 Copyright   : Copyright 2014 Robert Abram, Katie Snow
 Description : Ultimarc 2015 PAC board configuration library
 ============================================================================
*/

#ifndef PACSERIES_H_
#define PACSERIES_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define IPACSERIES_VERSION     2
#define IPACSERIES_VALUE       0x0203
#define IPACSERIES_MESG_LENGTH 5

typedef struct json_object json_object;

enum ipac_boards_t {NO_IPAC_BOARD = -1, PRE_IPAC2_BOARD = 0, PRE_IPAC4_BOARD,
                    ULTIMATE_IO_BOARD, IPAC2_BOARD, MINIPAC_BOARD, IPAC_4_BOARD,
                    JPAC_BOARD, HIDIO_BOARD};

/*
 * Determine if the JSON configuration file is one of the PAC Series (2015 PAC boards)
 */
bool validateIPACSeriesData(json_object* jobj);

/**
 * Encapsulating function for the two convert functions.
 */
unsigned char convertIPACKey (enum ipac_boards_t bid, json_object* jobj);

/**
 * 2015 board and the pre-2015 Ultimate I/O board.  Key value to hex value.
 */
unsigned char convertIPACSeries (json_object* jobj);

/*
 * Convert the JSON keys data into IPAC data
 * This is done one array element at a time
 * NOTE: The IPAC uses scan codes set 2.
 * http://www.quadibloc.com/comp/scan.htm Has the three sets listed out for reference
 */
unsigned char convertIPAC (json_object* jobj);

/**
 * Update one of the PAC Series boards.  These boards are the 2015 boards from Ultimarc.
 */
bool updatePACSeriesBoard(json_object* jobj);

void populateBoardArray (enum ipac_boards_t bid, json_object* jobj, unsigned char* data);

/**
 * Lookup the Lookup Table Key based on the configuration name
 */
int decipherLookupKey (char* key);

#ifdef __cplusplus
}
#endif

#endif /* PACSERIES_H_ */
