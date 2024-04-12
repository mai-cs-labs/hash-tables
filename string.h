#ifndef __STRING_H__
#define __STRING_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

// Immutable length-based string

typedef struct string {
    uint8_t* text;
    size_t length;
    bool allocated; // @NOTE: C does not have explicit allocator objects,
                    //        flag malloc'ed strings.
} String;

// Special in-place string initializer for constant string literals.
// Example: String s = String("this only accepts string literals like this one");
#define String(cstrlit) (String){(uint8_t*)(cstrlit), sizeof(cstrlit) - 1, false}

// Initialize string text with cstr C-string, must be NULL-terminated.
String string_init(const char* cstr);

// Initialize string text with data pointer and given size.
String string_init_range(uint8_t* const data, const size_t size);

// Initialize string with allocated text memory and copied text content from other.
String string_create_from(const String* const other);

// Invalidate string (make empty) and **free memory** if allocated.
void string_deinit(String* const string);
#define string_destroy(string) string_deinit(string)

bool string_empty(const String* const string);

bool string_compare(const String* const lhs, const String* const rhs);

// Print string to stdout.
void string_print(const String* const string);

#endif // __STRING_H__
