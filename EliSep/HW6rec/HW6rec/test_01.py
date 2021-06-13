import testlib
from ddt import file_data, ddt, data, unpack

# change DEBUG to True to disable timeout and checks
DEBUG=True
DEBUG=False

TIMEOUT=2 * 2

import images   # preload

@ddt
class Test(testlib.TestCase):

    def do_test(self, dungeon_filename_in, dungeon_filename_out, row, col, hp, expected_png, expected):
        '''Test implementation:
            - dungeon_filename_in:  name of the PNG file containing the input dungeon
            - dungeon_filename_out: name of the PNG file to create
            - row, col:             party's starting point
            - expected_png:         name of the PNG file containing the reference result
            - expected:             the expected return value
            TIMEOUT: 2 seconds for each test
        '''
        if DEBUG:
                import program01 as program
                result   = program.ex1(dungeon_filename_in, dungeon_filename_out, row, col, hp)
        else:
            with    self.ignored_function('builtins.print'), \
                    self.ignored_function('pprint.pprint'), \
                    self.forbidden_function('builtins.input'), \
                    self.forbidden_function('builtins.eval'), \
                    self.check_open(allowed_filenames_modes={dungeon_filename_in: ['rb'], dungeon_filename_out: ['wb'] }), \
                    self.check_imports(allowed=['program01', '_io', 'images', 'random']), \
                    self.timeout(TIMEOUT), \
                    self.timer(TIMEOUT):
                import program01 as program
                result   = program.ex1(dungeon_filename_in, dungeon_filename_out, row, col, hp)
        self.assertEqual(type(result),  list,
                f"il risultato prodotto deve essere una lista / the expected result should be a list ({result})")
        self.assertEqual(type(result[0]),  tuple,
                f"il risultato prodotto deve essere una tupla di interi / the expected result should be a tuple of int ({result})")
        self.assertEqual(result,        expected, 
                "il valore restituito non e' corretto / the expected result is incorrect")
        self.check_img_file(dungeon_filename_out, expected_png)
        return 1

    #   test_ID,  N, expected
    @data(
            ('mini-adventure',    280,  61, 200, [(330, 320, 450), (), (48, 152, 0), ()]  ),
            ('mini-adventure',    454, 344, 200, [(98, 102, 0), (), (), (-70, 470, 200)] ),
            ('mini-adventure',    454, 344, 300, [(198, 102, 0), (), (), (280, 470, 450)] ),
            ('dimi-adventure',    114, 460,  90, [(), (), (), (0, 90, 0)] ),
            ('dimi-adventure',    114, 460, 100, [(), (), (), (320, 485, 705)] ),
            ('tiny-adventure',    56,   56, 100, [(), (), (661, 809, 1370), ()] ),
            ('tiny-adventure',    440,  24, 200, [(855, 360, 1015), (575, 560, 935), (), ()] ),
            ('tiny-adventure',    777, 129,  30, [(-40, 145, 75), (), (329, 201, 500), ()]),
            ('tiny-adventure',    91,  379, 100, [(150, 50, 100), (100, 0, 0), (611, 709, 1220), (0, 100, 0)]),
            ('medium-adventure',  273, 577, 200,  [(864, 1899, 2563), (), (), ()]),
            ('medium-adventure',  355, 189, 750,  [(), (1352, 596, 1198), (-192, 2042, 1100), (3658, 1172, 4080)]),
            ('medium-adventure',  355, 189, 1000, [(), (1602, 596, 1198), (4354, 2506, 5860), (3908, 1172, 4080)]
 ),
            ('medium-adventure',  384,  21, 1000, [(-5, 1005, 0), (), (494, 1606, 1100), ()] ),
            ('medium-adventure',  384,  21, 1006, [(4297, 1469, 4760), (), (500, 1606, 1100), ()] )
            #('random-40-2399-1913', (993, 657, 1406, 1256)  ),
            #('random-50-991-1437',  (244, 31, 747, 533)     ),
            #('random-75-747-1595',  (68, 93, 679, 860)      ),
            #('random-100-945-835',  (10, 10, 925, 815)      ),
            #('random-150-1074-863', (10, 10, 1054, 843)     ),
          )
    @unpack
    def test_data(self, dungeon, row, col, hp, expected):
        dungeon_filename_in  = f"{dungeon}.png"
        dungeon_filename_out = f"test_{dungeon}_{row}_{col}_{hp}.png"
        expected_png    = f"expected_{dungeon}_{row}_{col}_{hp}.png"
        return self.do_test(dungeon_filename_in, dungeon_filename_out, row, col, hp, expected_png, expected)

if __name__ == '__main__':
    Test.main()

