'''A party of Dungeons and Dragons players meets up inside an unexplored dungeon.
  Depending on the direction that they will choose, they will find themselves
  walking along corridors and through rooms. Several meetings are awaiting,
  with monsters and treasures. Fighting with monsters causes the loss of hit
  points. Collected treasures bring an increase of hit points.

To simplify the exploration, the party will:
  - always start the exploration starting from an empty position of a
    corridor
  - always try to go to the end of every corridor
  - always collect any treasure found in a corridor position
  - always fight any monster met in a corridor position
  - enter the first door met in a corridor
  - never return to a position they have already explored.

Treasures allow the party to recover hit points, whereas the monsters
  make the party lose hit points during the fight. The party will lose
  as many hit points as the number of the monsters' hit points. If the
  number of hit points of the party goes below 0, the exploration ends
  (GAME OVER!). Otherwise, it continues according to the rules
  explained above.

When multiple options are available (e.g., two doors, a cross with
  different directions), the party will throw a 4-sided dice to decide
  the direction to take. The faces of the dice are associated as
  follows:
    1: North,
    2: East,
    3: South,
    4: West.
  The throw of the dice is repeated until it produces a value corresponding to
  a valid option. For example, if the possible directions are only East and
  West, the dice is to be thrown again and again until 2 or 4 come out.

Doors can give access to rooms that may host monsters and
  treasures. In a room with both treasures and monsters, the party
  will have to face and defeat the monsters first, and only then will
  they be able to collect the treasures (if they survive!). In any
  case, when the party enters a room, it means that all the positions
  of the room are considered explored and the order in which room
  positions are explored is irrelevant.

Once the party has explored a room (i.e., faced all monsters and collected all
  the treasures), the expedition will continue by getting through the first
  door that can be met by following the wall on the left of the door through
  which the party entered that room. If there are no doors left to go through,
  the exploration will be considered finished. Similarly, the exploration will
  stop when the party arrives at a location already explored, or ends up in a
  dead-end.

Having the layout of the entire dungeon map at our disposal, we want to predict
  which direction will be the most advantageous for the party from the entry
  position to the dungeon. The dungeon is represented by means of a PNG image
  in which the boxes are squares surrounded by grey lines. In particular:
  - white boxes represent corridors and rooms;
  - black boxes represent obstacles;
  - red boxes signal the presence of monsters; in particular, the RGB tuple is
    (255, 0, x), where x indicates the number of the monster's hit points:
  - green boxes indicate treasures; in particular, the RGB tuple is (0, 255, x),
    where x is the number of hit points that the treasure provides;
  - brown boxes represent the doors; specifically, the RGB tuple is
    (190, 100, 0).

Design a function ex1(fname_in, fname_out, row, col, hit_points) that
takes as input:
  - the path to a file (fname_in) containing the dungeon image as per the format
    described above
  - the path to a .png file (fname_out) to be created
  - the coordinates of a point in the image of the dungeon, corresponding to the
    starting point of the exploration
  - the number of hit points with which the party starts the exploration
  and does the following:
  - reads the image of the dungeon,
  - calculates which direction from the starting point makes the exploration end
    with the greatest number of hit points and,
  - once that direction is found, colours the dungeon boxes that will
    be explored by the party with a grey tone (128, 128, 128). In any
    case, all the boxes of a room are considered explored in one fell
    swoop.

  Finally, the function returns a list of tuples, one for each possible
  direction from the initial position. For each direction, the tuple will be
  either of the following:
  - a triple with the following elements:
      1) the number of remaining hit points at the end of the exploration;
      2) the number of hit points lost due to monsters;
      3) the number of hit points earned thanks to the treasures found;
  - an empty tuple, if the direction cannot be taken (because, e.g., there is
      an obstacle).

For the order of exploration, use the order north, east, south, west.
For the order of the list, instead, use the order north, south, east,
west.

To roll the dice, use the roll_dice function with the already set seed.

NOTE: it's forbidden to import other libraries or use them indirectly.
NOTE: the timeout for the grader execution is set to 2 seconds per test.

'''
import images
import random

def roll_dice(): # Do not modify this function
     return random.randint(1,4)

def ex1(fname_in,  fname_out, row, col, hit_points):
    random.seed("Dungeons and Dragons") # Do not modify this line!
    ## Start implementing your function below this line ##
