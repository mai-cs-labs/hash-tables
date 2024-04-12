#include "string.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define _STRING_INVALID (String){NULL, 0, false}

String string_init(const char* cstr)
{
    String result;

    assert(cstr != NULL);

    result.text = (uint8_t*)cstr;
    result.length = strlen(cstr);
    result.allocated = false;

    return result;
}

String string_init_range(uint8_t* const data, const size_t size)
{
    String result;

    assert(data != NULL);
    assert(size > 0);

    result.text = data;
    result.length = size;
    result.allocated = false;

    return result;
}

String string_create_from(const String* const other)
{
    String result;

    assert(other != NULL);

    const size_t length = other->length;

    result.text = malloc(length);
    if (result.text == NULL)
        return _STRING_INVALID;

    memcpy(result.text, other->text, length);

    result.length = length;
    result.allocated = true;

    return result;
}

void string_deinit(String* const string)
{
    assert(string != NULL);

    if (string->allocated)
        free(string->text);

    string->text = NULL;
    string->length = 0;
    string->allocated = false;
}

bool string_empty(const String* const string)
{
    assert(string != NULL);
    return string->text == NULL || string->length == 0;
}

bool string_compare(const String* const lhs, const String* const rhs)
{
    assert(lhs != NULL);
    assert(rhs != NULL);
    return lhs->length == rhs->length &&
           memcmp(lhs->text, rhs->text, lhs->length) == 0;
}

void string_print(const String* const string)
{
    assert(string != NULL);
    fwrite(string->text, sizeof(uint8_t), string->length, stdout);
}
