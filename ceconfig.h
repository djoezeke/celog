/**
 * @file ceconfig.h
 * @brief Configuration header for the celog logging library.
 *
 * celog - version 1.10
 * -----------------------------
 * This header file allows users to configure various aspects of the celog library, such as log level, colored output, styled output,
 * and inclusion of file and function information in log messages. Users can uncomment and modify the provided macros to customize the behavior of the logging library.
 */

#ifndef CELOG_HEADER_CONFING_H
#define CELOG_HEADER_CONFING_H

/**
 * @brief Set the log level (default: 7).
 *
 * The log level determines the severity of messages that will be logged.
 * Possible values are:
 * - 0: Emergency
 * - 1: Alert
 * - 2: Critical
 * - 3: Error
 * - 4: Warning
 * - 5: Notice
 * - 6: Info
 * - 7: Debug
 */
// #define CELOG_LOG_LEVEL (7)

/**
 * @brief Enable or disable colored output (default: 1).
 *
 * Set to 1 to enable colored output, 0 to disable.
 */
// #define CELOG_COLOR (1)

/**
 * @brief Enable or disable styled output (default: 1).
 *
 * Set to 1 to enable styled output (bold, underline, etc.), 0 to disable.
 */
// #define CELOG_STYLE (1)

/**
 * @brief Uncomment to disable logging file info.
 *
 * When enabled, the log messages will include the file name and line number.
 */
// #define CELOG_NO_FILE_INFO

/**
 * @brief Uncomment to disable logging function info.
 *
 * When enabled, the log messages will include the function name.
 */
// #define CELOG_NO_FUNC_INFO

/**
 * @brief Time Format Style For Logging.
 *
 * Define the format for the time part of the log messages.
 */
// #define CELOG_TIME_FORMAT (0)

/**
 * @brief Date Format Style For Logging.
 *
 * Define the format for the date part of the log messages.
 */
// #define CELOG_DATE_FORMAT (0)

/**
 * @brief Function Format Style For Logging.
 *
 * Define the format for the function part of the log messages.
 */
// #define CELOG_FUNC_FORMAT (0)

// addd color settings here

#endif // CELOG_HEADER_CONFING_H

/**
 * Copyright (c) 2025 Sackey Ezekiel Etrue
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */
