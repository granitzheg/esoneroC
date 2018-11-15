#include<stdio.h>

    int main(){

        int giorni_predizione, azioni;
        int cerca_intervallo, intervallo;
        int primo_giorno, ultimo_giorno, primo_giorno_valore, ultimo_giorno_valore;
        int guadagno, ricavo_vendita;
        
        puts("\n  -------------------------------------------------------------------------------------------------");
        puts(" |AIUTA ROSCO A FARE UNA BUONA AZIONE, SE NON LO FARAI POTRAI RITROVARTI COME LUI, ATTENTO EHEHE :)|");
        puts("  -------------------------------------------------------------------------------------------------");

        printf("\n  Inserisci il numero di giorni della predizione --> "); //chiedo all'utente di inserire il numero di giorni della predizione
            scanf("%d", &giorni_predizione);
        printf("  Quante azioni hai comprato? --> "); //chiedo all'utente quante azioni dispone
            scanf("%d", &azioni);
        puts("  -------------------------------------------------------------------------------------------------");
        
        puts("");
        int array[giorni_predizione]; //inizializzo l'array dove inserirò il valore delle azioni per giorno
        for(unsigned int i = 0; i < giorni_predizione; i++){
            printf("  Quanto vale l'azione al giorno %d? --> ", i + 1); //chiedo il valore delle azioni per giorno e incremento i giorni di 1 per convenienza (partirà da giorno 1 anzichè 0)
                scanf("%d", &array[i]);
        }
        puts("");

        for(unsigned int i = 0; i < giorni_predizione; i++){
            for(unsigned int j = i + 1; j < giorni_predizione; j++){
                
                cerca_intervallo = array[j] - array[i]; //cerco l'intervallo maggiore sottraendo gli elementi tra di loro

                if(cerca_intervallo > intervallo){ //trovo l'intervallo maggiore e lo salvo in una variabile (l'intervallo maggiore è quello migliore)
                    intervallo = cerca_intervallo;
                        primo_giorno = i + 2; //incremento di 2 perchè un posto serve per scalare nell'indice (per convenienza) e l'altro perchè si compra la mattina del giorno dopo
                        ultimo_giorno = j + 1; //una volta trovato l'intervallo maggiore memorizzo in due variabili i rispettivi indici dell'array che equivalgono all'inizio e alla fine dell'intervallo
                            primo_giorno_valore = array[i]; //mentre qui memorizzo i valori dei rispettivi indici
                            ultimo_giorno_valore = array[j];
                }
            }
        }
        
        puts("  -------------------------------------------------------------------------------------------------");
            if(intervallo <= 0){ //se l'intervallo è negativo o uguale a 0 vuol dire che non c'è guadagno
                printf("  Se vuoi bene ai tuoi soldi e vuoi guadagnare qualcosa, non comprare nulla!\n");
            } else{
                ricavo_vendita = azioni * ultimo_giorno_valore; //calcolo l'ammontare della vendita
                guadagno = azioni * intervallo; //calcolo il guadagno
                    printf("  Affrettati! Compra all'inizio del giorno numero %d e vendi tutto alla fine del giorno numero %d.\n", primo_giorno, ultimo_giorno);
                    printf("  Significa comprare quando le azioni valgono ancora %d, per poi venderle quando il loro valore è %d.\n", primo_giorno_valore, ultimo_giorno_valore);
                    printf("  L'ammontare della vendita sarà %d€, mentre il guadagno %d€. Sicuro che valga la pena? ;)\n", ricavo_vendita, guadagno);
                } 
        puts("  -------------------------------------------------------------------------------------------------\n");
    }
