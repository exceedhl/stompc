#ifndef STOMP_FRAME_H
#define STOMP_FRAME_H

#ifdef __cplusplus 
extern "C" { 
#endif

typedef struct _stomp_frame {
	char *verb;
	char *body;
} stomp_frame;

stomp_frame *stomp_frame_create(char *buf, int size);
void stomp_frame_free(stomp_frame *f);
char *stomp_frame_serialize(stomp_frame *f, int *size);


#ifdef __cplusplus 
} 
#endif

#endif /* end of include guard: STOMP_FRAME_H */
