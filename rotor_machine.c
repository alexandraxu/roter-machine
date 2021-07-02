#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Rotor
{
   int mapping[26];
   int offset;
};

struct Enigma
{
   struct Rotor inner;
   struct Rotor outer;
};

struct Enigma initialize()
{
   struct Rotor inner = {
       {9, 21, 0, 19, 18, 6, 3, 23, 10, 16, 12, 22, 13, 14, 7, 8, 24, 20, 1, 25, 2, 17, 5, 11, 4, 15},
       0};
   struct Rotor outer = {
       {24, 6, 18, 7, 20, 1, 22, 15, 21, 0, 25, 17, 14, 4, 9, 12, 10, 5, 16, 11, 2, 3, 13, 23, 19, 8},
       0};
   struct Enigma machine = {inner, outer};
   return machine;
}

int mod(int x, int m)
{
   return (x % m + m) % m;
}

int *encrypt(struct Enigma *machine, char *input, char *cipher)
{
   int length = strlen(input);

   for (int i = 0; i < length; i++)
   {
      int letter = (int)(input[i] - 'a');

      // not an alphabet
      if (letter < 0 || letter > 25)
      {
         cipher[i] = input[i];
         continue;
      }
      else
      {
         // encrypt
         int *inner_mapping = machine->inner.mapping;
         int *outer_mapping = machine->outer.mapping;
         int *inner_offset = &(machine->inner.offset);
         int *outer_offset = &(machine->outer.offset);
         int inner_input_pin = mod((letter - *inner_offset), 26);
         int inner_output_pin = inner_mapping[inner_input_pin];
         int inter_pos = mod((inner_output_pin + *inner_offset), 26);
         int outer_input_pin = mod((inter_pos - *outer_offset), 26);
         int outer_output_pin = outer_mapping[outer_input_pin];
         int pos = mod((outer_output_pin + *outer_offset), 26);
         int cipher_letter = "abcdefghijklmnopqrstuvwxyz"[pos];
         cipher[i] = cipher_letter;

         // rotate
         *inner_offset = (*inner_offset + 1) % 26;

         if (*inner_offset == 0)
         {
            *outer_offset = (*outer_offset + 1) % 26;
         }
      }
   }

   cipher[length] = '\0';
   return 0;
}

int print_state(struct Enigma *machine)
{
   printf("inner:\n");
   int *inner_mapping = machine->inner.mapping;
   int inner_offset = machine->inner.offset;
   for (int i = 0; i < 26; i++)
   {
      int inner_input_pin = mod(i - inner_offset, 26);
      printf("%d -> %d\n", inner_input_pin, inner_mapping[inner_input_pin]);
   }

   printf("\nouter:\n");
   int *outer_mapping = machine->outer.mapping;
   int outer_offset = machine->outer.offset;
   for (int i = 0; i < 26; i++)
   {
      int outer_input_pin = mod(i - outer_offset, 26);
      printf("%d -> %d\n", outer_input_pin, outer_mapping[outer_input_pin]);
   }

   return 0;
}

int reset(struct Enigma *machine)
{
   machine->inner.offset = 0;
   machine->outer.offset = 0;
   return 0;
}

bool is_cmd()
{
   char res[10];
   printf("is it a command? (y/n)\n");
   fgets(res, 10, stdin);
   res[strcspn(res, "\n")] = '\0';
   if (strcmp(res, "y") == 0)
      return true;
   return false;
}

int main()
{
   struct Enigma machine = initialize();
   char input[100];
   char cipher[100];

   while (true)
   {
      printf("text: ");
      fgets(input, 100, stdin);
      input[strcspn(input, "\n")] = '\0';

      // lowercase input
      for (int i = 0; input[i]; i++)
      {
         input[i] = tolower(input[i]);
      }

      if (strcmp(input, "quit") == 0 && is_cmd())
      {
         return 0;
      }
      else if (strcmp(input, "peek") == 0 && is_cmd())
      {
         print_state(&machine);
      }
      else if (strcmp(input, "reset") == 0 && is_cmd())
      {
         reset(&machine);
      }
      else
      {
         encrypt(&machine, input, cipher);
         printf("code: %s\n", cipher);
      }
   }
}