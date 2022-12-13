#ifndef _FLOW_H_INCLUDED_
#define _FLOW_H_INCLUDED_

#include <stdint.h>

#include <stdbool.h>
#include "libvig/verified/boilerplate-util.h"

struct flow {
  uint16_t src_port;
  uint16_t dst_port;
  uint32_t src_ip;
  uint32_t dst_ip;
  uint8_t protocol;
};

unsigned flow_hash(void *obj);
bool flow_eq(void *a, void *b);
void flow_allocate(void *obj);

#define LOG_FLOW(obj, p)                                                       \
  ;                                                                            \
  p("{");                                                                      \
  p("src_port: %d", (obj)->src_port);                                          \
  p("dst_port: %d", (obj)->dst_port);                                          \
  p("src_ip: %d", (obj)->src_ip);                                              \
  p("dst_ip: %d", (obj)->dst_ip);                                              \
  p("protocol: %d", (obj)->protocol);                                          \
  p("}");

#ifdef KLEE_VERIFICATION
#include <klee/klee.h>
#include "libvig/models/str-descr.h"

extern struct str_field_descr flow_descrs[5];
extern struct nested_field_descr flow_nests[0];
#endif // KLEE_VERIFICATION

#endif //_FLOW_H_INCLUDED_