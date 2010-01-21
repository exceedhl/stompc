#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include "stomp_frame.h"


static int is_valid_frame(int frame_end, int header_end, int verb_end);
	
stomp_frame stomp_frame_create(uint8_t *buf, int size)
{   
	int frame_end = -1;   
	int header_end = -1;
	int verb_end = -1; 
	int line_end = -1;
	int line_count = 0;
	int i = 0;
	uint8_t next_char;
	while (i < size) {
		next_char = buf[i];
		if (next_char == '\0') {
			frame_end = i;
			break;
		}
		if (next_char == '\n') {   
			if (line_end >= 0 && i - line_end == 1) {
				header_end = i;
			}
			line_end = i;
			line_count++;
		}                
		if (line_count == 1) {
			verb_end = line_end;
		}
		i++;
	} 

	if (!is_valid_frame(frame_end, header_end, verb_end)) {
		return NULL;
	}
	     
	stomp_frame f = malloc(sizeof(*f));
	f->verb = malloc((verb_end + 1) * sizeof(char));
	memcpy(f->verb, buf, verb_end);
	f->verb[verb_end] = 0;
	                              
	int body_start = (header_end + 1);
	int body_len = frame_end - body_start;
	f->body = malloc((body_len + 1) * sizeof(char));
	memcpy(f->body, buf + body_start, body_len);
	f->body[body_len] = 0;
	
	return f;
}         

static int is_valid_frame(int frame_end, int header_end, int verb_end) {
	return frame_end >= 0 && header_end >= 0 && verb_end >= 0;
}     

uint8_t *stomp_frame_serialize(stomp_frame f, int *size)
{
	return NULL;
}

void stomp_frame_destroy(stomp_frame f) 
{                                   
	free(f->verb);
	free(f->body);
	free(f);
}