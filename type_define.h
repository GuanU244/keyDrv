#ifndef MYDEF_H
#define MYDEF_H

#define ROOT_BASIC_T 10

typedef   unsigned  char    TD_UB;     /* Unsigned 8bit  */
typedef   unsigned  short   TD_UW;     /* Unsigned 16bit */
typedef   unsigned  long    TD_UDW;    /* Unsigned 32bit */
typedef   char    TD_SB;
typedef   short   TD_SW;
typedef   long    TD_SDW;

#define NULL (void *)0

//uart command struct

#define		UR_BUF_SIZE		32
struct buf_st {
  TD_UW in;                                // Next In Index
  TD_UW out;                               // Next Out Index
  TD_UB buf[UR_BUF_SIZE];                           // Buffer
};

#endif