#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>  // for sleep

// Macros as above
#define ACTIVATE_GENE(genome, gene) (genome |= (1 << gene))
#define DEACTIVATE_GENE(genome, gene) (genome &= ~(1 << gene))

typedef void (*Adaptation)(Genome *);

// Function to activate and then revert a gene after some time
void temporary_adaptation(Genome *genome, int gene, int duration) {
    printf("Activating gene %d temporarily.\n", gene);
    ACTIVATE_GENE(*genome, gene);
    printf("Genome during adaptation: %u\n", *genome);
    
    sleep(duration);  // Simulate temporary adaptation duration

    DEACTIVATE_GENE(*genome, gene);
    printf("Genome after adaptation reversion: %u\n", *genome);
}

int main() {
    Genome genome = 0;

    // Temporarily activate gene 5 for 3 seconds
    temporary_adaptation(&genome, 5, 3);

    return 0;
}
