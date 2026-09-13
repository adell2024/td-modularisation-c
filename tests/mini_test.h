#ifndef MINI_TEST_H
#define MINI_TEST_H

#include <stdio.h>
#include <string.h>

static int tests_total    = 0;
static int tests_reussis  = 0;
static int tests_echoues  = 0;

#define TEST(nom)                                                       \
    do {                                                                \
        tests_total++;                                                  \
        printf("  - %-40s", nom);                                       \
    } while (0)

#define OK()                                                            \
    do {                                                                \
        tests_reussis++;                                                \
        printf("[ OK ]\n");                                             \
    } while (0)

#define KO(message)                                                     \
    do {                                                                \
        tests_echoues++;                                                \
        printf("[ KO ] %s\n", message);                                 \
    } while (0)

#define ASSERT_INT(attendu, obtenu)                                     \
    do {                                                                \
        if ((attendu) == (obtenu)) { OK(); }                            \
        else {                                                          \
            char _msg[128];                                             \
            snprintf(_msg, sizeof _msg,                                 \
                     "attendu %d, obtenu %d",                           \
                     (int)(attendu), (int)(obtenu));                    \
            KO(_msg);                                                   \
        }                                                               \
    } while (0)

#define ASSERT_STR(attendu, obtenu)                                     \
    do {                                                                \
        const char *_a = (attendu);                                     \
        const char *_o = (obtenu);                                      \
        if (_o != NULL && strcmp(_a, _o) == 0) { OK(); }                \
        else {                                                          \
            char _msg[256];                                             \
            snprintf(_msg, sizeof _msg,                                 \
                     "attendu \"%s\", obtenu \"%s\"",                   \
                     _a, _o ? _o : "(null)");                           \
            KO(_msg);                                                   \
        }                                                               \
    } while (0)

#define BILAN()                                                         \
    do {                                                                \
        printf("\n%d test(s) — %d OK, %d KO\n",                         \
               tests_total, tests_reussis, tests_echoues);              \
        return tests_echoues == 0 ? 0 : 1;                              \
    } while (0)

#endif
