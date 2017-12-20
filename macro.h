/* Simple Educational Collection of Macros for learning C Language */

#ifndef MACRO_H
#define MACRO_H

#include <stdio.h>  /* serve per la perror */
#include <stdlib.h> /* serve per la exit   */
#include <string.h> /* serve per strlen    */
#include <errno.h>  /* serve per errno     */
#include <unistd.h> /* serve per la write  */


#define STDIN  0
#define STDOUT 1
#define STDERR 2

#define IFERROR(s,m) if((s)==-1) {perror(m); exit(errno);}
#define IFERROR2(s,m,c) if((s)==-1) {perror(m); c;}

#define WRITE(m) IFERROR(write(STDOUT,m,strlen(m)), m);
#define WRITELN(m) WRITE(m);WRITE("\n");

/* WHENERROR serve a stampare errori che non richiedono la chiusura dell'applicazione */
#define WHENERROR(c) do{ if((c)<0){ printf("Errore in [ %s : %d]\n",__FILE__,__LINE__); }} while(0)

/* SIGERROR serve a stampare errori critici relativi alla gestione dei segnali */
#define SIGERROR(c, a) do{ if((c)<0){ printf("Errore in [%s : %d] gestendo ",__FILE__,__LINE__); printf(a);\
kill(0,SIGKILL);}}while(0)

/* Stampa gli errori durate una chiamata a Fork() */
#define WHENFORK(c) do{ if((c)<0){ printf("Errore in [%s : %d] tentando una fork ",__FILE__,__LINE__);\
kill(0,SIGKILL);}}while(0)

/* TRACE si comporta come SIGERROR, ma relativi ad errori critici generici */
#define TRACE(a) do{printf ("TRACE : %s - %u\n", __FILE__, __LINE__); printf (a); fflush (stdout);\
kill(0, SIGKILL);}while(0)

/* Tre esempi con diverse implementazioni */
#define ArrayLen(array) (sizeof(array)/sizeof(array[0]))
#define ArrayLength(array) (sizeof(array) / sizeof (array[0]))
#define ArrayL(array) (sizeof(array) / sizeof(*array))

/* Accesso diretto alla memoria - Esempio per indirizzo $122: addr(0x0122) = 1; 
#define SetAddr(_ind) (*(unsigned char*) (_ind))

#define MoveTo(i, n) for((i) = 0; (i) < (n); (i)++)

#define PI 3.14

/* Autoesplicative */
#define MIN(a, b)   ((a)>(b)?(b):(a))
#define MAX(a, b)   ((a)>(b)?(a):(b))

#define Square(x) ((x)*(x))
 
/* a->b <-> !(a Or B) */
#define ARROW(a, b) (!(a) || (b))

#define COMPARE(x, y) (((x) > (y)) - ((x) < (y)))
#define SIGN(x) COMPARE(x, 0)

/* Swap parametrico nel tipo Esempio: SWAP(a,b int) */
#define SCAMBIA(a, b, Type) do { Type temp = (a); (a) = (b); (b) = temp; } while(0)

/* Sort parametrico nel tipo */
#define SORTYPE(a, b, T) do { if ((a) > (b)) SCAMBIA((a), (b), T); } while (0)

#define SET_TO(a, b, c) do{ size_t i_, b_; for (b_ = (b), i_ = 0; b_ > 0; --b_, ++i_) (a)[i_] = (c); } while(0)
#define SET_TO_ZERO(a, b) SET_TO(a, b, 0)

#endif
