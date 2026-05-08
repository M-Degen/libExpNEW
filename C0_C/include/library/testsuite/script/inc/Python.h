#ifndef Py_PYTHON_H
#define Py_PYTHON_H
/* Since this is a "meta-include" file, no #ifdef __cplusplus / extern "C" { */

/* Include nearly all Python header files */

#include <limits.h>

#include "../inc/patchlevel.h"
#include "../inc/pyconfig.h"
#include "../inc/pymacconfig.h"

#ifndef UCHAR_MAX
#error "Something's broken.  UCHAR_MAX should be defined in limits.h."
#endif

#if UCHAR_MAX != 255
#error "Python's source code assumes C's unsigned char is an 8-bit type."
#endif

#if defined(__sgi) && defined(WITH_THREAD) && !defined(_SGI_MP_SOURCE)
#define _SGI_MP_SOURCE
#endif

#include <stdio.h>
#ifndef NULL
#   error "Python.h requires that stdio.h define NULL."
#endif

#include <string.h>
#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

/* For size_t? */
#ifdef HAVE_STDDEF_H
#include <stddef.h>
#endif

/* CAUTION:  Build setups should ensure that NDEBUG is defined on the
 * compiler command line when building Python in release mode; else
 * assert() calls won't be removed.
 */
#include <assert.h>

#include "../inc/pyport.h"

#include "../inc/pyatomic.h"

/* Debug-mode build with pymalloc implies PYMALLOC_DEBUG.
 *  PYMALLOC_DEBUG is in error if pymalloc is not in use.
 */
#if defined(Py_DEBUG) && defined(WITH_PYMALLOC) && !defined(PYMALLOC_DEBUG)
#define PYMALLOC_DEBUG
#endif
#if defined(PYMALLOC_DEBUG) && !defined(WITH_PYMALLOC)
#error "PYMALLOC_DEBUG requires WITH_PYMALLOC"
#endif
#include "../inc/pymath.h"
#include "../inc/pytime.h"
#include "../inc/pymem.h"

#include "../inc/object.h"
#include "../inc/objimpl.h"
#include "../inc/typeslots.h"

#include "../inc/pydebug.h"

#include "../inc/bytearrayobject.h"
#include "../inc/bytesobject.h"
#include "../inc/unicodeobject.h"
#include "../inc/longobject.h"
#include "../inc/longintrepr.h"
#include "../inc/boolobject.h"
#include "../inc/floatobject.h"
#include "../inc/complexobject.h"
#include "../inc/rangeobject.h"
#include "../inc/memoryobject.h"
#include "../inc/tupleobject.h"
#include "../inc/listobject.h"
#include "../inc/dictobject.h"
#include "../inc/enumobject.h"
#include "../inc/setobject.h"
#include "../inc/methodobject.h"
#include "../inc/moduleobject.h"
#include "../inc/funcobject.h"
#include "../inc/classobject.h"
#include "../inc/fileobject.h"
#include "../inc/pycapsule.h"
#include "../inc/traceback.h"
#include "../inc/sliceobject.h"
#include "../inc/cellobject.h"
#include "../inc/iterobject.h"
#include "../inc/genobject.h"
#include "../inc/descrobject.h"
#include "../inc/warnings.h"
#include "../inc/weakrefobject.h"
#include "../inc/structseq.h"

#include "../inc/codecs.h"
#include "../inc/pyerrors.h"

#include "../inc/pystate.h"

#include "../inc/pyarena.h"
#include "../inc/modsupport.h"
#include "../inc/pythonrun.h"
#include "../inc/ceval.h"
#include "../inc/sysmodule.h"
#include "../inc/intrcheck.h"
#include "../inc/import.h"

#include "../inc/abstract.h"
#include "../inc/bltinmodule.h"

#include "../inc/compile.h"
#include "../inc/eval.h"

#include "../inc/pyctype.h"
#include "../inc/pystrtod.h"
#include "../inc/pystrcmp.h"
#include "../inc/dtoa.h"
#include "../inc/fileutils.h"

#ifdef __cplusplus
extern "C" {
#endif

/* _Py_Mangle is defined in compile.c */
#ifndef Py_LIMITED_API
PyAPI_FUNC(PyObject*) _Py_Mangle(PyObject *p, PyObject *name);
#endif

#ifdef __cplusplus
}
#endif

/* Argument must be a char or an int in [-128, 127] or [0, 255]. */
#define Py_CHARMASK(c)          ((unsigned char)((c) & 0xff))

#include "../inc/pyfpe.h"

/* These definitions must match corresponding definitions in graminit.h.
   There's code in compile.c that checks that they are the same. */
#define Py_single_input 256
#define Py_file_input 257
#define Py_eval_input 258

#ifdef HAVE_PTH
/* GNU pth user-space thread support */
#include <pth.h>
#endif

/* Define macros for inline documentation. */
#define PyDoc_VAR(name) static char name[]
#define PyDoc_STRVAR(name,str) PyDoc_VAR(name) = PyDoc_STR(str)
#ifdef WITH_DOC_STRINGS
#define PyDoc_STR(str) str
#else
#define PyDoc_STR(str) ""
#endif

#endif /* !Py_PYTHON_H */
