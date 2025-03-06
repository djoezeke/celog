#ifndef DJOEZEKE_CELOG_H
#define DJOEZEKE_CELOG_H

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>

#ifndef CELOG_LOG_LEVEL
#define CELOG_LOG_LEVEL (7)
#endif // CELOG_LOG_LEVEL

#ifndef CELOG_COLOR
#define CELOG_COLOR (1)
#endif // CELOG_COLOR

#ifndef CELOG_STYLE
#define CELOG_STYLE (1)
#endif // CELOG_STYLE

// log levels the same as syslog
#define CELOG_EMERGENCY (0)
#define CELOG_ALERT (1)
#define CELOG_CRITICAL (2)
#define CELOG_ERROR (3)
#define CELOG_WARNING (4)
#define CELOG_NOTICE (5)
#define CELOG_INFO (6)
#define CELOG_DEBUG (7)

// to disable file info logging
#if !defined(CELOG_NO_FILE_INFO)
#if !defined(CELOG_FILE_FORMAT)
#define CELOG_FILE_FORMAT "File (%s:%d) "
#endif // CELOG_FILE_FORMAT
#else
#define CELOG_FILE_FORMAT ""
#endif // CELOG_NO_FILE_INFO

// to disable function info logging
#if !defined(CELOG_NO_FUNC_INFO)
#if !defined(CELOG_FUNC_FORMAT)
#define CELOG_FUNC_FORMAT "In Fuction '%s%s%s' : "
#endif // CELOG_FUNC_FORMAT
#else
#define CELOG_FILE_FORMAT ""
#endif // CELOG_NO_FUNC_INFO

#ifndef CELOG_TIME_FORMAT
#define CELOG_TIME_FORMAT "%H:%M:%S"
#endif // CELOG_TIME_FORMAT

#ifndef CELOG_DATE_FORMAT
#define CELOG_DATE_FORMAT "%Y-%m-%d"
#endif // CELOG_DATE_FORMAT

// colors
#define NONE "\e[0m"
#define BLACK "\e[0;30m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define BROWN "\e[0;33m"
#define YELLOW "\e[1;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYAN "\e[0;36m"
#define GRAY "\e[0;37m"
#define WHITE "\e[1;37m"

#define L_BLACK "\e[1;30m"
#define L_RED "\e[1;31m"
#define L_GREEN "\e[1;32m"
#define L_BLUE "\e[1;34m"
#define L_PURPLE "\e[1;35m"
#define L_CYAN "\e[1;36m"

#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"
#define BLINK "\e[5m"
#define REVERSE "\e[7m"
#define HIDE "\e[8m"
#define CLEAR "\e[2J"
#define CLRLINE "\r\e[K" // or "\e[1K\r"

// #define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define __FILENAME__ __FILE__

/* safe readable version of errno */
#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define celog_emerg(message, ...)                                                  \
    do                                                                             \
    {                                                                              \
        fprintf(stderr, RED "[EMERGENCY]   "                                       \
                            "%s (%s:%d) " NONE message YELLOW " errno: %s\n" NONE, \
                __func__, __FILE__, __LINE__, ##__VA_ARGS__, clean_errno());       \
    } while (0)
#define celog_alert(message, ...)                                                     \
    do                                                                                \
    {                                                                                 \
        fprintf(stderr, PURPLE "[ALERT]   "                                           \
                               "%s (%s:%d) " NONE message YELLOW " errno: %s\n" NONE, \
                __func__, __FILE__, __LINE__, ##__VA_ARGS__, clean_errno());          \
    } while (0)
#define celog_crit(message, ...)                                                      \
    do                                                                                \
    {                                                                                 \
        fprintf(stderr, YELLOW "[CRITICAL]    "                                       \
                               "%s (%s:%d) " NONE message YELLOW " errno: %s\n" NONE, \
                __func__, __FILE__, __LINE__, ##__VA_ARGS__, clean_errno());          \
    } while (0)
#define celog_err(message, ...)                                                      \
    do                                                                               \
    {                                                                                \
        fprintf(stderr, BROWN "[ERROR]     "                                         \
                              "%s (%s:%d) " NONE message YELLOW " errno: %s\n" NONE, \
                __func__, __FILE__, __LINE__, ##__VA_ARGS__, clean_errno());         \
    } while (0)
#define celog_warning(message, ...)                                                 \
    do                                                                              \
    {                                                                               \
        fprintf(stderr, BLUE "[WARNING] "                                           \
                             "%s (%s:%d) " NONE message YELLOW " errno: %s\n" NONE, \
                __func__, __FILE__, __LINE__, ##__VA_ARGS__, clean_errno());        \
    } while (0)
#define celog_notice(message, ...)                                                  \
    do                                                                              \
    {                                                                               \
        fprintf(stderr, CYAN "[NOTICE]  "                                           \
                             "%s (%s:%d) " NONE message YELLOW " errno: %s\n" NONE, \
                __func__, __FILE__, __LINE__, ##__VA_ARGS__, clean_errno());        \
    } while (0)
#define celog_info(message, ...)                               \
    do                                                         \
    {                                                          \
        fprintf(stderr, GREEN "[INFO]    "                     \
                              "%s (%s:%d) " NONE message "\n", \
                __func__, __FILE__, __LINE__, ##__VA_ARGS__);  \
    } while (0)
#define celog_debug(message, ...)                                                                         \
    do                                                                                                    \
    {                                                                                                     \
        struct tm *tim;                                                                                   \
        time_t t = time(NULL);                                                                            \
        tim = localtime(&t);                                                                              \
        char buf[64];                                                                                     \
        buf[strftime(buf, sizeof(buf), L_BLUE CELOG_DATE_FORMAT " " CELOG_TIME_FORMAT NONE, tim)] = '\0'; \
        /*   fprintf(stderr, "%i - %i\n", t, t2);       */                                                \
        fprintf(stderr, "%s", buf);                                                                       \
        fprintf(stderr, " [" BLUE "DEBUG" NONE "] ");                                                     \
        fprintf(stderr, CELOG_FUNC_FORMAT BLUE, __func__, NONE);                                          \
        fprintf(stderr, CELOG_FILE_FORMAT, __FILE__, __LINE__);                                           \
        fprintf(stderr, message "\n", ##__VA_ARGS__);                                                     \
    } while (0)

/* CELOG_LOG_LEVEL controls */
#if CELOG_LOG_LEVEL < CELOG_DEBUG
#undef celog_debug
#define celog_debug(message, ...) \
    do                            \
    {                             \
    } while (0)
#endif

#if CELOG_LOG_LEVEL < CELOG_INFO
#undef celog_info
#define celog_info(message, ...) \
    do                           \
    {                            \
    } while (0)
#endif

#if CELOG_LOG_LEVEL < CELOG_NOTICE
#undef celog_notice
#define celog_notice(message, ...) \
    do                             \
    {                              \
    } while (0)
#endif

#if CELOG_LOG_LEVEL < CELOG_WARNING
#undef celog_warning
#define celog_warning(message, ...) \
    do                              \
    {                               \
    } while (0)
#endif

#if CELOG_LOG_LEVEL < CELOG_ERROR
#undef celog_err
#define celog_err(message, ...) \
    do                          \
    {                           \
    } while (0)
#endif

#if CELOG_LOG_LEVEL < CELOG_CRITICAL
#undef celog_crit
#define celog_crit(message, ...) \
    do                           \
    {                            \
    } while (0)
#endif

#if CELOG_LOG_LEVEL < CELOG_ALERT
#undef celog_alert
#define celog_alert(message, ...) \
    do                            \
    {                             \
    } while (0)
#endif

#if CELOG_LOG_LEVEL < CELOG_EMERGENCY
#undef celog_emerg
#define celog_emerg(message, ...) \
    do                            \
    {                             \
    } while (0)
#endif

/* CELOG_COLOR controls */
#if CELOG_COLOR < 1

#undef NONE
#define NONE

#undef RED
#define RED

#undef PURPLE
#define PURPLE

#undef YELLOW
#define YELLOW

#undef BROWN
#define BROWN

#undef GREEN
#define GREEN

#undef CYAN
#define CYAN

#undef BLUE
#define BLUE

#undef GRAY
#define GRAY

#endif // CELOG_COLOR

#if CELOG_STYLE < 1

#undef BOLD
#define BOLD

#undef UNDERLINE
#define UNDERLINE

#undef BLINK
#define BLINK

#undef REVERSE
#define REVERSE

#undef HIDE
#define HIDE

#undef CLEAR
#define CLEAR

#undef CLRLINE
#define CLRLINE

#endif // CELOG_STYLE

#endif // DJOEZEKE_CELOG_H
