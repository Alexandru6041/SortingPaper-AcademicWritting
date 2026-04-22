#ifndef DATA_GEN_H
#define DATA_GEN_H

typedef enum{
    RANDOM, 
    SORTED,
    REVERSED,
    ALMOST_SORTED,
    MIXED,
    FLAT
} Type;

const char *get_array_type_name(Type array_type);

int* generate_random_int_array(int size, Type Array_type);

int* copy_int_array(int* source, int size);

void print_int_array(int* arr, int size);

#endif