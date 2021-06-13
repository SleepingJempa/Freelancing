'''Un party di giocatori di Dungeons and Dragons si ritrova
all'interno di un dungeon inesplorato. A seconda della direzione che
sceglierà, percorrerà corridoi e attraverserà stanze, in cui avrà
diversi incontri, ovvero mostri e tesori. I mostri vanno affrontati
perdendo punti ferita, i tesori raccolti, guadagnando punti ferita.

Per semplificare l'esplorazione, il party:
- inizierà sempre l'esplorazione in una posizione di un corridoio
  vuota
- cercherà di andare sempre in fondo ad ogni corridoio
- raccoglierà ogni tesoro che incontrerà nei corridoi
- affronterà ogni mostro che incontrerà nei corridoi
- entrerà in ogni porta che incontrerà percorrendo un corridoio
- non tornerà mai in una posizione che ha già esplorato.

I tesori permettono al party di recuperare punti ferita, mentre i
mostri fanno perdere al party punti ferita durante il
combattimento. Nell'affrontare un mostro, il party perderà un numero
di punti ferita pari al numero di punti ferita del mostro. Se il
numero di punti ferita del party scende sotto 0, l'esplorazione
termina (GAME OVER!), altrimenti prosegue secondo le regole.

Quando ci sono più opzioni di scelta (una posizione di un corridoio
adiacente a due o più porte, un incrocio con due o più direzioni), il
party lancerà un dado a 4 facce per decidere la direzione da
prendere. Le facce del dado sono così associate: 1-nord, 2-est, 3-sud,
4-ovest. Il lancio del dado è ripetuto finché non produce un valore
corrispondente ad una opzione valida (es: se le possibili direzioni
sono est ed ovest, il dado va lanciato finché non esce 2 o 4).

Le porte danno accesso a stanze che possono contenere mostri e tesori.
Quando si accede ad una stanza che contiene sia tesori sia mostri, il
party dovrà prima affrontare e sconfiggere tutti i mostri e potrà
raccogliere i tesori solo se sopravviverà. In ogni caso, esplorare una
stanza implica visitare immediatamente l'intera stanza, ovvero
l'ordine con cui si esplorano le posizioni di una stanza è
irrilevante.

Una volta esplorata una stanza (ovvero affrontato tutti mostri e
raccolto tutti i tesori), l'esplorazione continuerà entrando nella
prima porta della stanza che si trova seguendo la parete a sinistra
della porta da cui il party è entrato. Se non ci sono ulteriori porte,
l'esplorazione si considererà terminata. Similmente, l'esplorazione si
arresterà quando si arriverà in una posizione già esplorata dal party
oppure in un vicolo cieco.

Dobbiamo prevedere a partire dalla posizione di ingresso al dungeon,
quale direzione sarà la più vantaggiosa per il party, avendo a
disposizione l'intera mappa del dungeon. Il dungeon è rappresentato
mediante una immagine png in cui le caselle sono quadrate, delimitate
da linee grigie. Inoltre,
- corridoi e stanze sono rappresentati dalle caselle bianche
- gli ostacoli sono rappresentati dalle caselle nere
- i mostri sono rappresentati dalle caselle di colore rosso, in cui la
  tupla RGB è del tipo (255, 0, x), dove x è il numero di punti ferita
  del mostro
- i tesori sono rappresentati da caselle di colore verde, in cui la
  tupla RGB è del tipo (0, 255, x), dove x è il numero di punti ferita
  che il tesoro fornisce al party
- le porte sono rappresentate da caselle di colore marrone, ovvero
  dalla tupla RGB (190, 100, 0)

Progettare la funzione ex1(fname_in, fname_out, row, col, punti) che
presi in input:
- il percorso di un file (fname_in) contenente l'immagine del dungeon
  nel formato sopra descritto
- il percorso di un file di tipo .png (fname_out) da creare
- le coordinate di un punto dell'immagine del dungeon, corrispondente
  al punto di partenza dell'esplorazione
- il numero di punti ferita con cui il party inizia l'esplorazione
legge l'immagine del dungeon, calcola quale direzione a partire dal
punto di partenza fa terminare l'esplorazione con il maggior numero di
punti ferita e, una volta trovata la direzione, colora di grigio
(128,128,128) le caselle del dungeon che saranno esplorate dal party
prima di fermarsi. Se il party termina in una stanza, tutte le caselle
della stanza saranno colorate di grigio.

Inoltre restituisce una lista di tuple, una per ogni direzione
possibile a partire dalla posizione iniziale. Per ogni direzione,
la tupla sarà
- o una tripla con i seguenti elementi:
  1) il numero di punti ferita rimasti al termine dell'esplorazione,
  2) il numero di punti ferita persi a causa dei mostri,
  3) il numero di punti ferita guadagnati grazie ai tesori trovati
- o una tupla vuota, se la direzione non è percorribile (ad es., se c'è un
  ostacolo).

Per l'ordine di esplorazione si usi la sequenza nord, est, sud ovest.
Per l'ordine della lista delle tuple da restituire, invece, si usi
l'ordine nord, sud, est, ovest.

Per il lancio del dado si usi la funzione roll_dice con il seed già
impostato.

NOTA: non è permesso importare altre librerie o usarle indirettamente.
NOTA: il timeout per la esecuzione del grader e' fissato a 2 secondi per test.

'''

import images
import random

def roll_dice(): # Non toccare questa funzione!
    return random.randint(1,4)

def ex1(fname_in,  fname_out, row, col, hit_points):
    random.seed("Dungeons and Dragons") # Non toccare questa riga, serve per inizializzare il dado!
    '''Implementare qui la funzione'''
