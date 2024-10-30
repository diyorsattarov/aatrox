#include <stdio.h>
#include <stdbool.h>

#define MAX_HISTORY 10  // Maximum number of modifications to keep in history
#define ACTIVATE_GENE(genome, gene) (genome |= (1 << gene))
#define DEACTIVATE_GENE(genome, gene) (genome &= ~(1 << gene))

typedef unsigned int Genome;

// History for reversible changes
Genome history[MAX_HISTORY];
int history_index = -1;  // Index to keep track of the current state in history

// Push current genome state to history
void save_genome_state(Genome genome) {
    if (history_index < MAX_HISTORY - 1) {
        history[++history_index] = genome;
    }
}

// Revert to previous genome state
void revert_genome_state(Genome *genome) {
    if (history_index >= 0) {
        *genome = history[history_index--];
    }
}

int main() {
    Genome genome = 0;

    save_genome_state(genome);  // Initial state
    
    ACTIVATE_GENE(genome, 2);  // Apply a change
    save_genome_state(genome);  // Save state after modification
    printf("Genome after gene activation: %u\n", genome);

    ACTIVATE_GENE(genome, 4);  // Another change
    save_genome_state(genome);
    printf("Genome after second gene activation: %u\n", genome);

    // Revert changes
    revert_genome_state(&genome);
    printf("Genome after first reversion: %u\n", genome);

    revert_genome_state(&genome);
    printf("Genome after second reversion: %u\n", genome);

    return 0;
}
