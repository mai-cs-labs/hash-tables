#define TEST_IMPLEMENTATION
#include "test.h"

#include "hashmap.h"

// Напишите тест для функции обработки строки с использованием данных из
// реализованной хеш таблицы.
TEST(custom)
{
    TEST_ASSERT(false);
}

//
// Общие юнит-тесты
//

TEST(create_hash_map)
{
    HashMap* map = hash_map_create();

    TEST_ASSERT(hash_map_size(map) == 0);
    TEST_ASSERT(hash_map_capacity(map) > 0);

    hash_map_destroy(&map);
}

TEST(destroy_hash_map)
{
    HashMap* map = NULL;
    hash_map_destroy(NULL);
    hash_map_destroy(&map);

    TEST_IGNORE();
}

int main(void)
{
    return test_run((const test_fn[]){
        create_hash_map,
        destroy_hash_map,
        custom,
        NULL,
    });
}
