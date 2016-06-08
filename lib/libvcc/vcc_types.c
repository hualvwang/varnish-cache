/*-
 * Copyright (c) 2006 Verdens Gang AS
 * Copyright (c) 2006-2011 Varnish Software AS
 * All rights reserved.
 *
 * Author: Poul-Henning Kamp <phk@phk.freebsd.dk>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#include "config.h"

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vcc_compile.h"

const struct type ACL[1] = {{
	.magic =		0xfae932d9,
	.name =			"ACL",
}};

const struct type BACKEND[1] = {{
	.magic =		0xfae932d9,
	.name =			"BACKEND",
	.tostring =		"VRT_BACKEND_string(\v1)",
}};

const struct type BLOB[1] = {{
	.magic =		0xfae932d9,
	.name =			"BLOB",
}};

const struct type BOOL[1] = {{
	.magic =		0xfae932d9,
	.name =			"BOOL",
	.tostring =		"VRT_BOOL_string(\v1)",
}};

const struct type BYTES[1] = {{
	.magic =		0xfae932d9,
	.name =			"BYTES",
	.tostring =		"VRT_REAL_string(ctx, \v1)", // XXX: wrong
	.multype =		REAL,	// XXX: wrong
}};

const struct type DURATION[1] = {{
	.magic =		0xfae932d9,
	.name =			"DURATION",
	.tostring =		"VRT_REAL_string(ctx, \v1)", // XXX 's' suff?
	.multype =		REAL,
}};

const struct type ENUM[1] = {{
	.magic =		0xfae932d9,
	.name =			"ENUM",
	.tostring =		"",
}};

const struct type HEADER[1] = {{
	.magic =		0xfae932d9,
	.name =			"HEADER",
	.tostring =		"VRT_GetHdr(ctx, \v1)",
}};

const struct type HTTP[1] = {{
	.magic =		0xfae932d9,
	.name =			"HTTP",
}};

const struct type INSTANCE[1] = {{
	.magic =		0xfae932d9,
	.name =			"INSTANCE",
}};

const struct type INT[1] = {{
	.magic =		0xfae932d9,
	.name =			"INT",
	.multype =		INT,
	.tostring =		"VRT_INT_string(ctx, \v1)",
}};

const struct type IP[1] = {{
	.magic =		0xfae932d9,
	.name =			"IP",
	.tostring =		"VRT_IP_string(ctx, \v1)",
}};

const struct type PROBE[1] = {{
	.magic =		0xfae932d9,
	.name =			"PROBE",
}};

const struct type REAL[1] = {{
	.magic =		0xfae932d9,
	.name =			"REAL",
	.tostring =		"VRT_REAL_string(ctx, \v1)",
	.multype =		REAL,
}};

const struct type STEVEDORE[1] = {{
	.magic =		0xfae932d9,
	.name =			"STEVEDORE",
}};

const struct type STRING[1] = {{
	.magic =		0xfae932d9,
	.name =			"STRING",
	.tostring =		"",
}};

const struct type STRING_LIST[1] = {{
	.magic =		0xfae932d9,
	.name =			"STRING_LIST",
	.tostring =		"",
}};

const struct type TIME[1] = {{
	.magic =		0xfae932d9,
	.name =			"TIME",
	.tostring =		"VRT_TIME_string(ctx, \v1)",
}};

const struct type VOID[1] = {{
	.magic =		0xfae932d9,
	.name =			"VOID",
}};

vcc_type_t
VCC_Type(const char *p)
{

#define VCC_TYPE(foo)	if (!strcmp(p, #foo)) return (foo);
#include "tbl/vcc_types.h"
#undef VCC_TYPE
	return (NULL);
}
