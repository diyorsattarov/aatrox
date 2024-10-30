#include <stdio.h>
#include <stdbool.h>

#define GENE_COUNT 32  // For simplicity, using 32 bits to represent "genes"
typedef unsigned int Genome;

// Macros to activate/deactivate genes
#define ACTIVATE_GENE(genome, gene) (genome |= (1 << gene))
#define DEACTIVATE_GENE(genome, gene) (genome &= ~(1 << gene))
#define IS_GENE_ACTIVE(genome, gene) ((genome & (1 << gene)) != 0)

// Activation conditions based on environment
void activate_genes_for_cold(Genome *genome) {
    ACTIVATE_GENE(*genome, 0);  // Activating a hypothetical "cold resistance" gene
    ACTIVATE_GENE(*genome, 3);  // Additional genes can be activated as needed
}

void deactivate_all_genes(Genome *genome) {
    *genome = 0;
}

int main() {
    Genome genome = 0;  // Initial genome with all genes "off"
    
    printf("Genome before cold environment: %u\n", genome);
    activate_genes_for_cold(&genome);
    printf("Genome after activation in cold: %u\n", genome);
    deactivate_all_genes(&genome);
    printf("Genome after deactivation: %u\n", genome);

    return 0;
}
