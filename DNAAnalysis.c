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
   int NucleotideNumber;
   char c;
   printf("Input DNA Strand: ");
   scanf("%s", OriginalDNAStrand);

   while (1)
   {
      fgets(line, sizeof(line), stdin);
      NucleotideNumber = strlen(OriginalDNAStrand);
      char *RNAStrand = (char*) malloc(NucleotideNumber*sizeof(char));
      if(OriginalDNAStrand[0] == 'Q' || OriginalDNAStrand[0] == 'q')
          {
             return 1;
          }
      for(i=0; i<NucleotideNumber; i++)
      {
          RNAStrand[i] = ConverterRNA(OriginalDNAStrand[i]);
	  if(RNAStrand[i] == 0)
          {
              printf("Enter proper DNA code.\n");
              return 1;
          }
       } 
       printf("Original DNA Strand: %s\n", OriginalDNAStrand);
       printf("Complementary RNA Strand: %s\n", RNAStrand);
       char *NewDNAStrand = (char*) malloc(NucleotideNumber*sizeof(char));
       for(i=0; i<NucleotideNumber; i++)
       {
          NewDNAStrand[i] = ConverterDNAComplement(OriginalDNAStrand[i]);
       }
       printf("Complementary DNA Strand: %s\n", NewDNAStrand);
       printf("Number of Nucleotides Analyzed: %d\n\n", NucleotideNumber);

      printf("Input DNA Strand: ");
      scanf("%s", OriginalDNAStrand);
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
