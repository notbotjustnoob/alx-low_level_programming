#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>

/**
 * struct hash_table_s - Hash table structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 */
typedef struct hash_table_s
{
    unsigned long int size;
    void **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);

#endif /* HASH_TABLES_H */
