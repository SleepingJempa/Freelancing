'''
With this program, we want to help a Dutch archeologist. She has recently found
  a collection of precious inscriptions in Ancient Greek and valuable texts in
  Italian. She wants to find passages that are in common between pairs of
  texts in different languages. She is fluent in Latin and English but
  not in Ancient Greek and Italian. However, she knows she can rely on our help!

To pursue her objective, the archeologist has retrieved two CSV files. In the
  first one, "lexicon_gr_en", some Ancient Greek words are translated into
  one or more English expressions (let them be single words or short clauses),
  whenever available.

  For instance:
    "ἀραρίσκω;join;fit together"
  is a line in the file indicating that "ἀραρίσκω" translates to "join" or
  "fit together". Another line,
    "ἀπορρήσσω;[unavailable]"
  suggests the absence of a reliable translation.

  In the second CSV file, "lexicon_en_it", every English expression is
  translated into an Italian one: "join" translates to "unirsi" and "fit
  together" translates to "aderire". The correspondence between English and
  Italian expressions is one-to-one. Also, all English expressions in
  "lexicon_gr_en" also occur in "lexicon_en_it", except those marked as
  "[unavailable]".

  In both CSV files, expressions are separated by a semi-colon.

Notice that the Ancient Greek inscriptions are written in a rather particular
  way. The flow of the text is boustrophedon, that is, alternating
  lines of writing are flipped: first left-to-right, then right-to-left,
  then left-to-right again, and so on. The good news is, the glyphs of the
  characters are not mirrored. Furthermore, paragraphs are separated by multiple
  line-feeds (two or more). Single line-feeds are kept only to wrap lines.
  The end of the file also denotes the end of the last paragraph.
  For simplicity, (1) all letters are reported in lower case and (2) the
  punctuation symbols used are only line-feeds and the following:
    '.' (full stop) ',' (comma) ':' (colon) ' ' (white space) "'" (apostrophes)

  For example, a paragraph like:
      ἄνδρα μοι ἔννεπε, μοῦσα, πολύτροπον, ὃς μάλα πολλὰ
    πλάγχθη, ἐπεὶ Τροίης ἱερὸν πτολίεθρον ἔπερσεν:
    πολλῶν δ' ἀνθρώπων ἴδεν ἄστεα καὶ νόον ἔγνω,
    πολλὰ δ' ὅ γ' ἐν πόντῳ πάθεν ἄλγεα ὃν κατὰ θυμόν,

  reads as follows (see the "odyssey.txt" file):

    ἄνδρα μοι ἔννεπε, μοῦσα, πολύτροπον, ὃς μάλα πολλὰ
    :νεσρεπἔ νορθείλοτπ νὸρεἱ ςηίορτ ὶεπἐ ,ηθχγάλπ
    πολλῶν δ' ἀνθρώπων ἴδεν ἄστεα καὶ νόον ἔγνω,
    ,νόμυθ ὰτακ νὃ αεγλἄ νεθάπ ῳτνόπ νἐ 'γ ὅ 'δ ὰλλοπ


The archeologist wants to find out sequences of at least k > 0 words in
  the Ancient Greek text such that (1) the Ancient Greek words are in a
  single paragraph and (2) they correspond to sequences of at least k words
  in a paragraph of the Italian text, based on the given CSV files and
  ignoring punctuation marks. Notice that the Italian text follows the only
  left-to-right flow and, for convenience, all letters are lowercase.
  Paragraphs in the Italian text are also separated by two or more line-feeds.

Design a function

    ex1(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f)

  that, given:
  - k: the minimum number of consecutive Ancient Greek words to be found
      in paragraphs of "greek_txt_f" whose translation in English corresponds
      to sequences of words in paragraphs of "italian_txt_f" (with k > 0)
  - lexicon_gr_en_f: the path to the lexicon text file translating Ancient Greek
      into English, as described above
  - lexicon_en_it_f: the path to the lexicon text file translating English into
      Italian, as described above
  - greek_txt_f: the path to the text file with an inscription in Ancient
      Greek, written according to the rules described above
  - italian_txt_f: the path to the text file with a text in Italian
  returns:
  - a set of pairs of tuples; the first tuple refers to the Ancient Greek text;
    the second tuple refers to the corresponding excerpt in the Italian one;
    each tuple indicates:
    1) the excerpt of the text containing the sequence of words whose
       translation in English match with the translation from the other language
       (having line-feeds replaced by white spaces, written only from left to
       right),
    2) the paragraph number (starting from 1) where the excerpt lies.

For example,
  ex1(2, "lexicon-GR-EN.csv", "lexicon-EN-IT.csv", "odyssey.txt", "proemio.txt")
  should return
  {(("ἔννεπε, μοῦσα", 1),
    ("dissi io, o musa", 1)),
   (("τῶν ἁμόθεν γε, θεά, θύγατερ διός", 2),
    ("di ciò, da qualunque principio, ad ogni costo, dea figlia di zeus", 3))
  }

  Notice that, in "lexicon_GR_EN.csv", the following lines occur (among others):
    ἔννεπε;said i
    μοῦσα;o muse
    τῶν;of these things
    ἁμόθεν;beginning at any stage
    γε;indeed;at least;at any rate
    θεά;goddess
    θύγατερ;daughter
    διός;of zeus
  in "lexicon_EN_IT.csv", we have:
    said i;dissi io
    o muse;o musa
    of these things;di ciò
    beginning at any stage;da qualunque principio
    at any rate;ad ogni costo
    goddess;dea
    daughter;figlia
    of zeus;di zeus
  the first paragraph of "odyssey.txt" is reported above, whereas the second
  one ends as follows:
    ἤσθιον: αὐτὰρ ὁ τοῖσιν ἀφείλετο νόστιμον ἦμαρ.
    ,εγ νεθόμἁ νῶτ
    θεά θύγατερ,
    .νῖμἡ ὶακ ὲπἰε ,ςόιδ
  the first paragraph of "proemio.txt" reads as follows:
    di donarmi il diluvio ti dissi
    io, o musa, scorgendo il destino.
  and the third paragraph of "proemio.txt" reads as follows:
    imperterrita irrefrenabile poiché
    memore di ciò, da qualunque principio,
    ad ogni costo, dea figlia di zeus,
    narrane cagione e spirito.

  Concluding remark: if two or more sequences as described above occur in a
  paragraph, they should all appear in the result. We are, however, not
  interested in inner subsequences. In the example above, for instance,
    (("θεά, θύγατερ διός", 2), ("dea figlia di zeus", 3))
  is not included in the solution.


NOTE: the timeout for this exercise is of 3 seconds for each test.

WARNING: Make sure that the uploaded file is UTF8-encoded
    (to that end, we recommend you edit the file with Spyder).
    No other files can be opened nor libriaries be included.
'''

def ex1(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f):
    # insert here your code
    pass

if __name__ == '__main__':
    # Insert your own tests here
    pass
