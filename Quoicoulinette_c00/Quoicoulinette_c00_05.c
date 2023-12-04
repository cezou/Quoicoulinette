#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

void ft_print_comb(void);

void test_ft_print_comb(void)
{
    // Rediriger la sortie standard vers un tube (pipe)
    int pipe_fds[2];
    pipe(pipe_fds);

    // Créer un nouveau processus pour éviter la lecture bloquante du tube
    pid_t pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "Erreur lors de la création du processus\n");
        return;
    }
    else if (pid == 0)
    {
        // Fermer l'extrémité de lecture du tube dans le processus fils
        close(pipe_fds[0]);

        // Rediriger la sortie standard vers l'extrémité d'écriture du tube
        dup2(pipe_fds[1], STDOUT_FILENO);

        // Appeler la fonction ft_print_comb
        ft_print_comb();

        // Fermer l'extrémité d'écriture du tube dans le processus fils
        close(pipe_fds[1]);

        // Terminer le processus fils
        exit(0);
    }
    else
    {
        // Fermer l'extrémité d'écriture du tube dans le processus parent
        close(pipe_fds[1]);

        char expected_output[] = "012, 013, 014, 015, 016, 017, 018, 019, 023, 024, 025, 026, 027, 028, 029, 034, 035, 036, 037, 038, 039, 045, 046, 047, 048, 049, 056, 057, 058, 059, 067, 068, 069, 078, 079, 089, 123, 124, 125, 126, 127, 128, 129, 134, 135, 136, 137, 138, 139, 145, 146, 147, 148, 149, 156, 157, 158, 159, 167, 168, 169, 178, 179, 189, 234, 235, 236, 237, 238, 239, 245, 246, 247, 248, 249, 256, 257, 258, 259, 267, 268, 269, 278, 279, 289, 345, 346, 347, 348, 349, 356, 357, 358, 359, 367, 368, 369, 378, 379, 389, 456, 457, 458, 459, 467, 468, 469, 478, 479, 489, 567, 568, 569, 578, 579, 589, 678, 679, 689, 789";
        char received_output[4096]; // Augmenter la taille du tableau pour éviter les erreurs de dépassement de mémoire
        ssize_t total_bytes_read = 0;
        ssize_t bytes_read;

        // Lire la sortie du tube par blocs jusqu'à la fin
        while ((bytes_read = read(pipe_fds[0], received_output + total_bytes_read, sizeof(received_output) - total_bytes_read - 1)) > 0)
        {
            total_bytes_read += bytes_read;
        }

        // Fermer l'extrémité de lecture du tube dans le processus parent
        close(pipe_fds[0]);

        // Attendre la fin du processus fils
        waitpid(pid, NULL, 0);

        // Vérifier si la lecture a réussi
        if (bytes_read >= 0)
        {
            received_output[total_bytes_read] = '\0'; // Ajouter un caractère nul à la fin de la chaîne

            // Comparer la sortie obtenue avec la sortie attendue
            if (strcmp(received_output, expected_output) == 0)
                printf("Test: \033[1;32mApagnan! :)\033[0m\n");
            else
                printf("Test: \033[1;31mQUOICOUBEH :O\033[0m\n");

            // Afficher la sortie attendue et la sortie obtenue
            printf("Sortie attendue: %s\n", expected_output);
            printf("Sortie obtenue  : %s\n", received_output);
        }
        else
        {
            printf("Erreur lors de la lecture du tube\n");
        }
    }
}
