// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2020 Fredrik Noring
 */

#include <errno.h>
#include <tos/error.h>
#include <unistd.h>

#include "toslibc/tos/xbios.h"

static void (*__xbios_supexecarg_func)(void *arg);
static void *__xbios_supexecarg_arg;

static void __xbios_supexecarg(void)
{
	__xbios_supexecarg_func(__xbios_supexecarg_arg);
}

void xbios_supexecarg(void (*func)(void *arg), void *arg)
{
	__xbios_supexecarg_func = func;
	__xbios_supexecarg_arg = arg;

	xbios_supexec(__xbios_supexecarg);
}