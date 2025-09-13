#include <stdio.h>
#include <windows.h>
#include <conio.h>  // para detectar ESC e encerrar

int main() {
    char tecla;
    float segundos;
    int intervalo;

    printf("=== Auto Key Presser ===\n");
    printf("Digite a tecla que deseja repetir: ");
    scanf(" %c", &tecla);

    printf("Digite o intervalo em segundos (exemplo: 1 = 1 segundo, 0.5 = meio segundo): ");
    scanf("%f", &segundos);

    intervalo = (int)(segundos * 1000); // converte segundos -> milissegundos

    printf("\nO programa vai digitar a tecla '%c' a cada %.2f segundos.\n", tecla, segundos);
    printf("Pressione a tecla ESC para encerrar.\n");

    // Loop infinito até o usuário apertar ESC
    while (1) {
        // Verifica se ESC foi pressionado
        if (_kbhit()) { // se alguma tecla foi pressionada
            int ch = _getch();
            if (ch == 27) { // código ASCII do ESC
                printf("\nPrograma encerrado pelo usuário.\n");
                break;
            }
        }

        // Simula pressionar a tecla
        keybd_event(tecla, 0, 0, 0);
        // Simula soltar a tecla
        keybd_event(tecla, 0, KEYEVENTF_KEYUP, 0);

        Sleep(intervalo); // espera o tempo definido
    }

    return 0;
}
