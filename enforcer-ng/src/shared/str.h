/*
 * Copyright (c) 2011 NLNet Labs. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * String utilities.
 *
 */

#ifndef SHARED_STR_H
#define SHARED_STR_H

#include "config.h"
#include "shared/allocator.h"
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Tokenize string
 * 
 * A return value > argc indicates there where 1 or 
 * more tokens available that did not fit in argv; Function is
 * destructive wrt buf.
 * 
 * \param[in/out] buf, string to tokenize
 * \param[in] argc, length of argv array
 * \param[out] argv, where the tokens are stored.
 * \return number of tokens processed.
 */
int ods_str_explode(char *buf, int argc, const char *argv[]);

/**
 * Join arguments together with a join character into a single string 
 * (terminated by 2 zero characters.)
 *
 * Note that the rationale for having 2 terminating zero characters is that
 * it allows joining a list of strings with a zero cjoin character resulting
 * in a zero terminated list of zero terminated strings.
 *
 * \param[in] argc argument count
 * \param[in] argv argument array
 * \param[in] cjoin join character to use
 * \return	Newly allocated string terminated by 2 zero character that should 
 *          be freed using allocator_deallocate or NULL when no arguments
 *          were passed.
 */
char *ods_str_join(allocator_type* allocator, int argc, char *argv[], 
                   char cjoin);



/**
 * Version of ctime_r that does not feature a trailing '\n' character
 *
 * \param[in] buf buffer to write the formatted date/time to
 * \param[in] nbuf size of buf, including any terminating zero characters.
 * \param[in] t time_t value to print to buf
 * \return	buf to indicate success or NULL to indicate failure.
 */
char *ods_ctime_r(char *buf, size_t nbuf, time_t t);



const char *ods_check_command(const char *cmd, int cmdsize, 
                              const char *scmd);

int ods_find_arg(int *pargc, const char *argv[],
                 const char *longname, const char *shortname);

int ods_find_arg_and_param(int *pargc, const char *argv[],
                           const char *longname, const char *shortname,
                           const char **pvalue);

#ifdef __cplusplus
}
#endif

#endif /* SHARED_STR_H */
