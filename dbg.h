#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __Line__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif

/**
 * dbg.h:1-2
 * The usual defense against accidentally including the file twice, which you saw in the last exercise.
 * dbg.h:4-6
 * Includes for the functions that these macros need.
 * dbg.h:8
 * The start of a #ifdef which lets you recompile your program so that all the debug log messages are removed.
 * dbg.h:9
 * If you compile with NDEBUG defined, then "no debug" messages will remain. You can see in this case the #define debug() is just replaced with nothing (the right side is empty).
 * dbg.h:10
 * The matching #else for the above #ifdef.
 * dbg.h:11
 * The alternative #define debug that translates any use of debug("format", arg1, arg2) into an fprintf call to stderr. Many C programmers don't know, but you can create macros that actually work like printf and take variable arguments. Some C compilers (actually cpp) don't support this, but the ones that matter do. The magic here is the use of ##__VA_ARGS__ which says "put whatever they had for extra arguments (...) here". Also notice the use of __FILE__ and __LINE__ to get the current file:line for the debug message. Very helpful.
 * dbg.h:12
 * The end of the #ifdef.
 * dbg.h:14
 * The clean_errno macro that's used in the others to get a safe readable version of errno. That strange syntax in the middle is a "ternary operator" and you'll learn what it does later.
 * dbg.h:16-20
 * The log_err, log_warn, and log_info, macros for logging messages meant for the end user. Works like debug but can't be compiled out.
 * dbg.h:22
 * The best macro ever, check will make sure the condition A is true, and if not logs the error M (with variable arguments for log_err), then jumps to the function's error: for cleanup.
 * dbg.h:24
 * The 2nd best macro ever, sentinel is placed in any part of a function that shouldn't run, and if it does prints an error message then jumps to the error: label. You put this in if-statements and switch-statements to catch conditions that shouldn't happen, like the default:.
 * dbg.h:26
 * A short-hand macro check_mem that makes sure a pointer is valid, and if it isn't reports it as an error with "Out of memory."
 * dbg.h:28
 * An alternative macro check_debug that still checks and handles an error, but if the error is common then you don't want to bother reporting it. In this one it will use debug instead of log_err to report the message, so when you define NDEBUG the check still happens, the error jump goes off, but the message isn't printed.
 */

