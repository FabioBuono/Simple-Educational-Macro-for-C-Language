/* Simple Educational Collection of Macros for learning C Language */

#ifndef MACRO_H
#define MACRO_H

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <errno.h>  
#include <unistd.h> 


#define STDIN  0
#define STDOUT 1
#define STDERR 2

#define IFERROR(s,m) if((s)==-1) {perror(m); exit(errno);}
#define IFERROR2(s,m,c) if((s)==-1) {perror(m); c;}

#define WRITE(m) IFERROR(write(STDOUT,m,strlen(m)), m);
#define WRITELN(m) WRITE(m);WRITE("\n");

/* WHENERROR for critical error */
#define WHENERROR(c) do{ if((c)<0){ printf("Errore in [ %s : %d]\n",__FILE__,__LINE__); }} while(0)

/* SIGERROR for signal related critical error */
#define SIGERROR(c, a) do{ if((c)<0){ printf("Errore in [%s : %d] gestendo ",__FILE__,__LINE__); printf(a);\
kill(0,SIGKILL);}}while(0)

/* for error in a fork */
#define WHENFORK(c) do{ if((c)<0){ printf("Errore in [%s : %d] tentando una fork ",__FILE__,__LINE__);\
kill(0,SIGKILL);}}while(0)

/* TRACE critical error */
#define TRACE(a) do{printf ("TRACE : %s - %u\n", __FILE__, __LINE__); printf (a); fflush (stdout);\
kill(0, SIGKILL);}while(0)

/* Three Array Lenght example */
#define ArrayLen(array) (sizeof(array)/sizeof(array[0]))
#define ArrayLength(array) (sizeof(array) / sizeof (array[0]))
#define ArrayL(array) (sizeof(array) / sizeof(*array))

/* direct memory access $122: addr(0x0122) = 1; */
#define SetAddr(_ind) (*(unsigned char*) (_ind))

/* move an element */
#define MoveTo(i, n) for((i) = 0; (i) < (n); (i)++)

/* Autoesplicative */
#define MIN(a, b)   ((a)>(b)?(b):(a))
#define MAX(a, b)   ((a)>(b)?(a):(b))

#define Square(x) ((x)*(x))
 
/* a->b <-> !(a Or B) */
#define ARROW(a, b) (!(a) || (b))

#define COMPARE(x, y) (((x) > (y)) - ((x) < (y)))
#define SIGN(x) COMPARE(x, 0)

/* swp parameters SWAP(a,b int) */
#define swap(a, b, Type) do { Type temp = (a); (a) = (b); (b) = temp; } while(0)

/*  parametric Sort */
#define SORTYPE(a, b, T) do { if ((a) > (b)) swap((a), (b), T); } while (0)

#define SET_TO(a, b, c) do{ size_t i_, b_; for (b_ = (b), i_ = 0; b_ > 0; --b_, ++i_) (a)[i_] = (c); } while(0)
#define SET_TO_ZERO(a, b) SET_TO(a, b, 0)

#endif
