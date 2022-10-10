0x0E-structures_typedef.docx

vi dog.h
#ifndef DOG_H

#define DOG_H

/**

 * struct dog - A new type describing a dog.

 * @name: The name of the dog.

 * @age: The age of the dog.

 * @owner: The owner of the dog.

 */

struct dog

{

        char *name;

        float age;

        char *owner;

};


/**

 * dog_t - Typedef for struct dog

 */

typedef struct dog dog_t;


void init_dog(struct dog *d, char *name, float age, char *owner);

void print_dog(struct dog *d);

dog_t *new_dog(char *name, float age, char *owner);

void free_dog(dog_t *d);


#endif



vi 1-init_dog.c
#include "dog.h"

#include <stdlib.h>


/**

 * init_dog - Initializes a variable of type struct dog.

 * @d: The dog to be initialized.

 * @name: The name of the dog.

 * @age: The age of the dog.

 * @owner: The owner of the dog.

 */

void init_dog(struct dog *d, char *name, float age, char *owner)

{

        if (d != NULL)

        {

                d->name = name;

                d->age = age;

                d->owner = owner;

        }

}


vi 2-print_dog.c
#include "dog.h"

#include <stdio.h>

#include <stdlib.h>


/**

 * print_dog - Prints a struct dog.

 * @d: The struct dog to be printed.

 */

void print_dog(struct dog *d)

{

        if (d == NULL)

                return;


        if (d->name == NULL)

                printf("Name: (nil)\n");

        else

                printf("Name: %s\n", d->name);


        if (d->age < 0)

                printf("Age: (nil)\n");

        else

                printf("Age: %f\n", d->age);


        if (d->owner == NULL)

                printf("Owner: (nil)\n");

        else

                printf("Owner: %s\n", d->owner);

}


vi 4-new_dog.c
#include "dog.h"

#include <stdlib.h>


int _strlen(char *str);

char *_strcopy(char *dest, char *src);

dog_t *new_dog(char *name, float age, char *owner);


/**

 * _strlen - Finds the length of a string.

 * @str: The string to be measured.

 *

 * Return: The length of the string.

 */

int _strlen(char *str)

{

        int len = 0;


        while (*str++)

                len++;


        return (len);

}


/**

 * _strcopy - Copies a string pointed to by src, including the

 *            terminating null byte, to a buffer pointed to by dest.

 * @dest: The buffer storing the string copy.

 * @src: The source string.

 *

 * Return: The pointer to dest.

 */

char *_strcopy(char *dest, char *src)

{

        int index = 0;


        for (index = 0; src[index]; index++)

                dest[index] = src[index];


        dest[index] = '\0';


        return (dest);

}


/**

 * new_dog - Creates a new dog.

 * @name: The name of the dog.

 * @age: The age of the dog.

 * @owner: The owner of the dog.

 *

 * Return: The new struct dog.

 */

dog_t *new_dog(char *name, float age, char *owner)

{

        dog_t *doggo;


        if (name == NULL || age < 0 || owner == NULL)

                return (NULL);


        doggo = malloc(sizeof(dog_t));

        if (doggo == NULL)

                return (NULL);


        doggo->name = malloc(sizeof(char) * (_strlen(name) + 1));

        if (doggo->name == NULL)

        {

                free(doggo);

                return (NULL);

        }


        doggo->owner = malloc(sizeof(char) * (_strlen(owner) + 1));

        if (doggo->owner == NULL)

        {

                free(doggo->name);

                free(doggo);

                return (NULL);

        }


        doggo->name = _strcopy(doggo->name, name);

        doggo->age = age;

        doggo->owner = _strcopy(doggo->owner, owner);


        return (doggo);

}
