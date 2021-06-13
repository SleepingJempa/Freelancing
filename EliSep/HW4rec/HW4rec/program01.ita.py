'''
Con questo programma, vogliamo aiutare un’archeologa olandese, la quale ha
  ritrovato una collezione di preziose iscrizioni in Greco Antico ed altrettanto
  notevoli testi in Italiano. Vorrebbe identificare quali passaggi sono in
  coumne fra le coppie di testi. Conosce benissimo Latino ed Inglese ma non
  altrettanto Greco Antico o Italiano. Tuttavia, sa che può contare sul
  nostro aiuto!

Per perseguire il suo obiettivo, l’archeologa ha scovato due file CSV. Nel
  primo, "lexigon_gr_en", alcune parole in Greco Antico sono tradotte in una o
  più espressioni in Inglese (cioè, parole singole o periodi brevi).

  Per esempio:
    "ἀραρίσκω;join;fit together"
  è una riga del file con cui si indica che "ἀραρίσκω" si traduce come "join" o
  "fit together". Un’altra riga dello stesso file,
    "ἀπορρήσσω;[unavailable]"
  denota invece l’assenza di una traduzione attendibile.

  Nel secondo file CSV, "lexicon_en_it", ogni expressione in Inglese è
  tradotta in una in Italiano: "join" si traduce come "unirsi" e "fit
  together" come "aderire". La corrispondenza tra le espressioni in Inglese e
  quelle in Italiano è sempre una-ad-una. Inoltre, tutte le espressioni in
  Inglese in "lexicon_gr_en" sono anche presenti in "lexicon_en_it",
  ad eccezione di quelle marcate come "[unavailable]".

  In ambedue i file CSV, le espressioni sono separate da un punto e virgola.

Le iscrizioni in Greco Antico seguono una struttura piuttosto particolare. Il
  testo è bustrofedico, cioè fluisce alternado una riga scritta da sinistra a
  destra alla seguente da destra a sinistra, poi da sinistra a destra di
  nuovo e così via. I caratteri non sono a specchio, per fortuna. Inoltre,
  i paragrafi sono separati da invii a capo multipli (due o più). Invii a
  capo singoli sono lasciati solo per limitare la lunghezza delle righe. La
  fine del file denota anche la fine dell’ultimo paragrafo. Per semplicità,
  (1) tutte le lettere sono minuscole e (2) i simboli di punteggiatura sono
  solo i suddetti invii a capo e:
    '.' (punto) ',' (virgola) ':' (due punti) ' ' (spazio) "'" (apostrofo)

  Per esempio, un paragrafo di questo tipo:
        ἄνδρα μοι ἔννεπε, μοῦσα, πολύτροπον, ὃς μάλα πολλὰ
    πλάγχθη, ἐπεὶ Τροίης ἱερὸν πτολίεθρον ἔπερσεν:
    πολλῶν δ' ἀνθρώπων ἴδεν ἄστεα καὶ νόον ἔγνω,
    πολλὰ δ' ὅ γ' ἐν πόντῳ πάθεν ἄλγεα ὃν κατὰ θυμόν,

  risulta salvato come segue (v. il file "odyssey.txt"):

    ἄνδρα μοι ἔννεπε, μοῦσα, πολύτροπον, ὃς μάλα πολλὰ
    :νεσρεπἔ νορθείλοτπ νὸρεἱ ςηίορτ ὶεπἐ ,ηθχγάλπ
    πολλῶν δ' ἀνθρώπων ἴδεν ἄστεα καὶ νόον ἔγνω,
    ,νόμυθ ὰτακ νὃ αεγλἄ νεθάπ ῳτνόπ νἐ 'γ ὅ 'δ ὰλλοπ

L’archeologa vuole trovare le sequenze che constino di almeno k > 0 parole in
  Greco Antico tali che (1) le parole in Greco Antico sono in un singolo
  paragrafo e (2) corrispondono a sequenze di almeno k parole in un paragrafo
  del testo in Italiano, in base ai riferimenti dei file CSV ed ignorando i
  simboli di interpunzione. Notare che il testo in Italiano segue la sola
  direzione da sinistra a destra e, per semplicità, tutte le lettere sono
  minuscole. Anche i paragrafi nel testo in Italiano sono separati da due o
  più invii a capo.

Progettare una funzione:

    ex1(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f)

  che, dati:
  - k: il numero minimo di parole consecutive in Greco Antico da trovarsi in
      un paragrafo di "greek_txt_f" la cui traduzione in Inglese corrisponda a
      quella di sequenze di parole in un paragrafo di "italian_txt_f" (k > 0)
  - lexicon_gr_en_f: il percorso del file di testo che traduce parole dal
      Greco Antico all’Inglese, come descritto in precedenza
  - lexicon_en_it_f: il percorso del file di testo che traduce parole
      dall’Inglese all’Italiano, come descritto in precedenza
  - greek_txt_f: il percorso del file di testo con un’iscrizione in
      Greco Antico, redatta come spiegato sopra
  - italian_txt_f: il percorso del file di testo in Italiano
  restituisca:
  - un insieme (set) di paia di tuple; la prima tupla si riferisce al testo in
    Greco Antico; la seconda si riferisce all’estratto corrispondente nel testo
    in Italiano:
    1) l’estratto del testo contenente la sequenza di parole che, tradotta in
        Inglese, corrisponde alla traduzione dall’altro linguaggio (rimpiazzare
        gli invii a capo con caratteri di spaziatura, scrivendo nella sola
        direzione da sinistra a destra),
    2) il numero del paragrafo (partendo da 1) dove si trova l’estratto del
        testo di cui al punto (1).

Per esempio,
  ex1(2, "lexicon-GR-EN.csv", "lexicon-EN-IT.csv", "odyssey.txt", "proemio.txt")
  deve restituire
  {(("ἔννεπε, μοῦσα", 1),
    ("dissi io, o musa", 1)),
   (("τῶν ἁμόθεν γε, θεά, θύγατερ διός", 2),
    ("di ciò, da qualunque principio, ad ogni costo, dea figlia di zeus", 3))
  }

  Si noti che, in "lexicon_GR_EN.csv", si presentano le seugenti righe (fra
  le altre traduzioni):
    ἔννεπε;said i
    μοῦσα;o muse
    τῶν;of these things
    ἁμόθεν;beginning at any stage
    γε;indeed;at least;at any rate
    θεά;goddess
    θύγατερ;daughter
    διός;of zeus
  in "lexicon_EN_IT.csv", abbiamo:
    said i;dissi io
    o muse;o musa
    of these things;di ciò
    beginning at any stage;da qualunque principio
    at any rate;ad ogni costo
    goddess;dea
    daughter;figlia
    of zeus;di zeus
  il primo paragrafo di "odyssey.txt" é riportato in alto, mentre il secondo
  termina come seuge:
    ἤσθιον: αὐτὰρ ὁ τοῖσιν ἀφείλετο νόστιμον ἦμαρ.
    ,εγ νεθόμἁ νῶτ
    θεά θύγατερ,
    .νῖμἡ ὶακ ὲπἰε ,ςόιδ
  il primo paragrafo di "proemio.txt" inizia come segue:
    di donarmi il diluvio ti dissi
    io, o musa, scorgendo il destino.
  ed il terzo paragrafo di "proemio.txt" recita:
    imperterrita irrefrenabile poiché
    memore di ciò, da qualunque principio,
    ad ogni costo, dea figlia di zeus,
    narrane cagione e spirito.

  Per concludere: se due o più sequenze come quelle descritte prima compaiono in
  un paragrafo, dovrebbero tutte comparire anche nel risultato. Tuttavia, non
  sono di interesse le sottosequenza interne. Nell’esempio in alto, infatti, la
  tupla
    (("θεά, θύγατερ διός", 2), ("dea figlia di zeus", 3))
  non è inclusa nella soluzione.


ATTENZIONE: non si possono usare altre librerie o aprire altri file.

TIMEOUT: Il timeout per questo esercizio è di 3 secondi.
'''

def ex1(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f):
    # insert here your code
    pass

if __name__ == '__main__':
    # Insert your own tests here
    pass
