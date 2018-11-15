#include<stdio.h>

    int main(){

        int giorni_predizione, azioni;
        int cerca_intervallo, intervallo;
        int primo_giorno, ultimo_giorno, primo_giorno_valore, ultimo_giorno_valore;
        int guadagno, ricavo_vendita;
        
        puts("\n  -------------------------------------------------------------------------------------------------");
        puts(" |AIUTA ROSCO A FARE UNA BUONA AZIONE, SE NON LO FARAI POTRAI RITROVARTI COME LUI, ATTENTO EHEHE :)|");
        puts("  -------------------------------------------------------------------------------------------------");

        printf("\n  Inserisci il numero di giorni della predizione --> "); //chiedi all'utente di inserire il numero di giorni della predizione
            scanf("%d", &giorni_predizione);
        printf("  Quante azioni hai comprato? --> "); //chiedi all'utente quante azioni dispone
            scanf("%d", &azioni);
        puts("  -------------------------------------------------------------------------------------------------");
        
        puts("");
        int array[giorni_predizione];
        for(unsigned int i = 1; i <= giorni_predizione; i++){ //inizializzo a 1 per far partire il conteggio dei giorni da 1
            printf("  Quanto vale l'azione al giorno %d? --> ", i); //chiedi il valore delle azioni per giorno
                scanf("%d", &array[i]); //di conseguenza l'array partirà da 1 anzichè da 0
        }
        puts("");

        for(unsigned int i = 1; i <= giorni_predizione; i++){
            for(unsigned int j = i + 1; j <= giorni_predizione; j++){
                
                cerca_intervallo = array[j] - array[i]; //cerco l'intervallo maggiore sottraendo gli elementi tra di loro

                if(cerca_intervallo > intervallo){ //trovo l'intervallo maggiore e lo salvo in una variabile(l'intervallo maggiore è quello migliore)
                    intervallo = cerca_intervallo;
                        primo_giorno = i + 1; //una volta trovato l'intervallo maggiore memorizzo in due variabili i rispettivi indici dell'array //incremento di 1 perchè 
                        ultimo_giorno = j; //che equivalgono all'inizio e alla fine dell'intervallo
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
