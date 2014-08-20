#ifndef _SBF_KEY_VALUE_H_
#define _SBF_KEY_VALUE_H_

#include "sbfCommon.h"

SBF_BEGIN_DECLS

typedef struct sbfKeyValueImpl* sbfKeyValue;

sbfKeyValue sbfKeyValue_create (void);
void sbfKeyValue_destroy (sbfKeyValue table);
sbfKeyValue sbfKeyValue_copy (sbfKeyValue table);

const char* sbfKeyValue_get (sbfKeyValue table, const char* key);
const char* sbfKeyValue_getV (sbfKeyValue table, const char* fmt, ...) SBF_PRINTFLIKE(2, 3);
void sbfKeyValue_put (sbfKeyValue table, const char* key, const char* value);
void sbfKeyValue_remove (sbfKeyValue table, const char* key);

/* Calling remove invalidates first/next. */
const char* sbfKeyValue_first (sbfKeyValue table, void** cookie);
const char* sbfKeyValue_next (sbfKeyValue table, void** cookie);

SBF_END_DECLS

#endif /* _SBF_KEY_VALUE_H_ */
