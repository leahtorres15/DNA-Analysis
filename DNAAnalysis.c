char ConverterRNA (char DNACode);
char ConverterDNAComplement (char DNACode);

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
   int i;
   char OriginalDNAStrand[1000];
   char line[255];
   int isint;
   int choice;
   char *menu = "Menu\n"
                "[1] Complementary RNA Strand\n"
                "[2] Complementary DNA Strand\n"
                "[3] Quit\n";
   int NucleotideNumber;
   char c;

   while (1)
   {
      printf("%sChoice: ", menu);
      fgets(line, sizeof(line), stdin);
      isint = sscanf(line, "%d", &choice);      
      if(! isint)
      {
         printf("Invalid Choice.\n");
         continue;
      }

      if(choice == 1)
      {
         printf("Input DNA Strand: ");
         scanf("%s", &OriginalDNAStrand);
         NucleotideNumber = strlen(OriginalDNAStrand);
         char *RNAStrand = (char*) malloc(NucleotideNumber*sizeof(char));
         for(i=0; i<NucleotideNumber; i++)
         {
            RNAStrand[i] = ConverterRNA(OriginalDNAStrand[i]);
            if(RNAStrand[i] == 0)
            {
               printf("Enter proper DNA code.\n");
               return 1;
            }
         } 
         printf("%s\n", RNAStrand);
         printf("Number of Nucleotides Analyzed: %d\n\n", NucleotideNumber);
      }
      else if(choice == 2)
      {
         printf("Input DNA Strand: ");
         scanf("%s", &OriginalDNAStrand);
         NucleotideNumber = strlen(OriginalDNAStrand);
         char *NewDNAStrand = (char*) malloc(NucleotideNumber*sizeof(char));
         for(i=0; i<NucleotideNumber; i++)
         {
            NewDNAStrand[i] = ConverterDNAComplement(OriginalDNAStrand[i]);
            if(NewDNAStrand[i] == 0)
            {
               printf("Enter proper DNA code.\n");
               return 1;
            }
         }
         printf("%s\n", NewDNAStrand);
         printf("Number of Nucleotides Analyzed: %d\n\n", NucleotideNumber);
      }
      else if(choice == 3)
      {
         break;
      }
      else
      {
         printf("Invalid Choice.\n");
      }

      while ((c = getchar()) != '\n' && c != EOF)
      { 
      }
   }
   return 0;
}

char ConverterRNA (char Nucleotide)
{
   switch(Nucleotide)
   {
      case 'A':
         return 'U';
      case 'T':
         return 'A';
      case 'C':
         return 'G';
      case 'G':
         return 'C';
      default:
         return 0;
   }
}

char ConverterDNAComplement (char Nucleotide)
{
   switch(Nucleotide)
   {
      case 'A':
         return 'T';
      case 'T':
         return 'A';
      case 'C':
         return 'G';
      case 'G':
         return 'C';
      default:
         return 0;
   }
}
