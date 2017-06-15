#if !defined(LOGGING_IDENTIFIER)
#error "Must define LOGGING_IDENTIFIER for module to deduce namespace"
#endif

#define M_CONC(A, B) M_CONC_(A, B)
#define M_CONC_(A, B) A##B
#define NAMESPACE M_CONC(logging, M_CONC(_,LOGGING_IDENTIFIER))

#define xstr(s) str(s)
#define str(s) #s
