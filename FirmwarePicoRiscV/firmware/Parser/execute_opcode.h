#ifndef EXECUTE_OPCODE_H_
#define EXECUTE_OPCODE_H_

#include "LMS7002M.h"
#include "parser.h"
#include "parser_typedefs.h"

int executeOpcode(LMS7002M_t *lms, uint32_t opcode, Geric_Parameter* buffer, size_t buffer_size);

#endif // EXECUTE_OPCODE_H_

