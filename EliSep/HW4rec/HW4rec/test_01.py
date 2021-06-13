import testlib
import random
from ddt import file_data, ddt, data, unpack

# TODO TBD

# change this variable to True to disable timeout and enable print
DEBUG=True
DEBUG=False

TIMEOUT=1 * 2

@ddt
class Test(testlib.TestCase):
    def do_test(self, k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f, expected):
        """Test implementation
        - lexicon_gr_en_f:   path of the CSV file with the GR/EN lexicon
        - lexicon_en_it_f:   path of the CSV file with the EN/IT lexicon
        - greek_txt_f:       path to the Ancient Greek text
        - italian_txt_f:     path to the Italian text
        - expected:          expected result
        TIMEOUT: 3 seconds for each test
        """
        if DEBUG:
                import program01 as program
                result = program.ex1(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f)
        else:
            with    self.ignored_function('builtins.print'), \
                    self.ignored_function('pprint.pprint'), \
                    self.forbidden_function('builtins.input'), \
                    self.forbidden_function('builtins.eval'), \
                    self.check_open(allowed_filenames_modes={
                        lexicon_gr_en_f: ['r', 'rt'],
                        lexicon_en_it_f: ['r', 'rt'],
                        greek_txt_f: ['r', 'rt'],
                        italian_txt_f: ['r', 'rt'],
                    }), \
                    self.check_imports(
                        allowed=['program01', '_io', 'encodings.utf_8']), \
                    self.timeout(TIMEOUT), \
                    self.timer(TIMEOUT):
                import program01 as program
                result = program.ex1(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f)
        self.assertEqual(type(result), set,
                         ('The output type should be: set\n'
                          '[Il tipo di dato in output deve essere: set]'))
        for result_pair in result:
            self.assertTrue(isinstance(result_pair, tuple) and
                            len(result_pair) == 2,
                            ('Every element of the '
                             'output list should be: a '
                             'pair (tuple of length 2)\n'
                             '[Ogni elemento della '
                             'lista in output deve essere: '
                             'una coppia (tupla di lunghezza 2)]'))
            for result_pair_element in result_pair:
                self.assertTrue(isinstance(result_pair_element, tuple) and
                                len(result_pair_element) == 2,
                                ('Every element of the '
                                 'output list should be: '
                                 'a pair (tuple of length 2)\n'
                                 '[Ogni elemento della '
                                 'lista in output deve essere: '
                                 'uan coppia (tupla di lunghezza 2)]'))
                self.assertIsInstance(result_pair_element[0], str,
                                 ('The first element of the '
                                  'inner pairs’ pair should be: '
                                  'a string\n'
                                  '[Il primo elemento delle coppie interne '
                                  'deve essere: una stringa'))
                self.assertIsInstance(result_pair_element[1], int,
                                 ('The second element of the '
                                  'inner pairs’ pair should be of type: '
                                  'int\n'
                                  '[Il secondo elemento delle coppie interne '
                                  'deve essere di tipo: '
                                  'int'))
        # Turning everything into sets to avoid issues with sorting
        self.assertEqual(result, expected,
                         ('The return value is incorrect\n'
                          '[Il valore di ritorno è errato]'))
        return 1


    def test_example1(self):
        k = 2
        lexicon_gr_en_f = "lexicon-GR-EN.csv"
        lexicon_en_it_f = "lexicon-EN-IT.csv"
        greek_txt_f = "odyssey.txt"
        italian_txt_f = "proemio.txt"
        expected = {(('ἔννεπε, μοῦσα', 1), ('dissi io, o musa', 1)), (('τῶν ἁμόθεν γε, θεά θύγατερ, διός', 2), ('di ciò, da qualunque principio, ad ogni costo, dea figlia di zeus', 3))}
        return self.do_test(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f, expected)

    def test_example2(self):
        k = 2
        lexicon_gr_en_f = "lexicon-GR-EN.csv"
        lexicon_en_it_f = "lexicon-EN-IT.csv"
        greek_txt_f = "odyssey.txt"
        italian_txt_f = "proemio-glitches.txt"
        expected = {(('ἔννεπε, μοῦσα', 1), ('dissi io, o musa', 1)), (('τῶν ἁμόθεν', 2), ('di ciò, da qualunque principio', 3)), (('τῶν ἁμόθεν γε, θεά θύγατερ, διός', 2), ('di ciò, da qualunque principio, ad ogni costo, dea figlia di zeus', 3))}
        return self.do_test(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f, expected)

    def test_example3(self):
        k = 4
        lexicon_gr_en_f = "lexicon-GR-EN.csv"
        lexicon_en_it_f = "lexicon-EN-IT.csv"
        greek_txt_f = "odyssey.txt"
        italian_txt_f = "proemio-glitches.txt"
        expected = {(('τῶν ἁμόθεν γε, θεά θύγατερ, διός', 2), ('di ciò, da qualunque principio, ad ogni costo, dea figlia di zeus', 3))}
        return self.do_test(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f, expected)

    def test_example4(self):
        k = 6
        lexicon_gr_en_f = "lexicon-GR-EN.csv"
        lexicon_en_it_f = "lexicon-EN-IT.csv"
        greek_txt_f = "odyssey.txt"
        italian_txt_f = "proemio.txt"
        expected = {(('τῶν ἁμόθεν γε, θεά θύγατερ, διός', 2), ('di ciò, da qualunque principio, ad ogni costo, dea figlia di zeus', 3))}
        return self.do_test(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f, expected)

    def test_example5(self):
        k = 8
        lexicon_gr_en_f = "lexicon-GR-EN.csv"
        lexicon_en_it_f = "lexicon-EN-IT.csv"
        greek_txt_f = "odyssey.txt"
        italian_txt_f = "proemio.txt"
        expected = set()
        return self.do_test(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f, expected)

    def test_example6(self):
        k = 1
        lexicon_gr_en_f = "lexicon-GR-EN_.csv"
        lexicon_en_it_f = "lexicon-EN-IT_.csv"
        greek_txt_f = "odyssey.txt"
        italian_txt_f = "proemio.txt"
        expected = {(('μάλα', 1), ('molto', 2)), (('ἄνδρα', 1), ('uomo', 2)), (('ἔννεπε, μοῦσα', 1), ('dissi io, o musa', 1)), (('τῶν ἁμόθεν γε, θεά θύγατερ, διός', 2), ('di ciò, da qualunque principio, ad ogni costo, dea figlia di zeus', 3)), (('μάλα', 1), ('eccessivamente', 2))}
        return self.do_test(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f, expected)

    def test_example7(self):
        k = 3
        lexicon_gr_en_f = "lexicon-GR-EN.csv"
        lexicon_en_it_f = "lexicon-EN-IT.csv"
        greek_txt_f = "odyssey.txt"
        italian_txt_f = "proemio-ext.txt"
        expected = {(('σφετέρῃσιν ἀτασθαλίῃσιν ὄλοντο', 2), ('loro propria malvagità distruggere', 1)), (('τῶν ἁμόθεν γε, θεά θύγατερ, διός', 2), ('di ciò, da qualunque principio, ad ogni costo, dea figlia di zeus', 3))}
        return self.do_test(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f, expected)

    def test8(self):
        k = 2
        lexicon_gr_en_f = "lexicon-GR-EN.csv"
        lexicon_en_it_f = "lexicon-EN-IT.csv"
        greek_txt_f = "text_GR--4_4-4.txt"
        italian_txt_f = "text_IT--4_4-4.txt"
        expected = {(('δημοκρατέομαι πορθμεύω σύνταγμα ἄπιος', 2), ('avere una costituzione democratica: trasportare ciò che è messo insieme, in ordine distante', 2)), (('ἵππαρχος, ἐγγύς ἐχθρός βαρβάρα', 3), ('governare il cavallo, vicino odioso gesso', 3)), (('διαπιστεύω, στρατηγός ἐπίγραμμα', 1), ('affidare a: capo iscrizione', 1)), (('ἀκρόασις δύναμις: κιθαρίζω', 4), ('udito. energia. suonare la cetra', 4))}
        return self.do_test(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f, expected)

    def test9(self):
        k = 3
        lexicon_gr_en_f = "lexicon-GR-EN.csv"
        lexicon_en_it_f = "lexicon-EN-IT.csv"
        greek_txt_f = "text_GR--10-5_7-7_8.txt"
        italian_txt_f = "text_IT--6-5_7-7_8.txt"
        expected = {(('προστροπή ποδαρκής κιθαρίζω. πολύς', 4), ('girando: correre in soccorso suonare la cetra: molti', 3)), (('ἀγνωμοσύνη περικλυτός ἀποικία βασιλεύω', 1), ('mancanza di conoscenza famoso insediamento lontano da casa: regno', 3)), (('ἀποτολμάω, μακρός διανοέομαι ποτάομαι', 3), ("fare un'avventura coraggiosa: lungo essere attento vola qua e là", 6)), (('εἰκῇ ποθή, ἐπεύχομαι χιτωνίσκος', 4), ('senza piano, desiderio pregare, un abito corto', 1))}
        return self.do_test(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f, expected)


    def test10(self):
        k = 3
        lexicon_gr_en_f = "lexicon-GR-EN.csv"
        lexicon_en_it_f = "lexicon-EN-IT.csv"
        greek_txt_f = "text_GR--100-5_7-7_8.txt"
        italian_txt_f = "text_IT--60-5_7-7_8.txt"
        expected = {(('αὐτόθεν ἀνάμνησις, αὐλή', 92), ('dal punto esatto richiamando alla mente corte aperta', 13)), (('μεγαλόψυχος πικράζω τόλμησις: ἐκπλέω οἰκόπεδον. ἀφορμή', 90), ('alta anima: sapore amaro un atto spericolato: salpare: sito di una casa punto di partenza', 47)), (('ξένιος βόσκημα: πρᾶξις αἰτιάομαι ὀξύς', 67), ('ospitale, ciò che viene nutrito. transazione accusare acuto', 53)), (('δικαιολογέομαι. πόλις ἀμείνων ὑπερόριος, στενός', 14), ("difendere la propria causa davanti al giudice. città meglio all'estero stretto", 14)), (('παρών: ἀκτή παιδιή: εὐηγενής ψηφόω', 47), ('nave leggera promontorio gioco infantile bene adornano di gemme', 7)), (('ἀρίς προίστημι συγγνώμη ταφρεύω: ἐπιτήδειος', 78), ('uno strumento da falegname: impostare prima amicizia fare un fossato fatto per una fine', 37))}
        return self.do_test(k, lexicon_gr_en_f, lexicon_en_it_f, greek_txt_f, italian_txt_f, expected)

if __name__ == '__main__':
    Test.main()
