#include "board.hpp"
#include "PositionStack.hpp"
#include "const.hpp"

Long Position::perft(int depth,ofstream*file,Move&lastMove) {
    pos_counter++;
    if (DEBUG) {
        openNode(*file);
    }
    int move_counter = 0;
    Move moves[255];
    move_generator(move_counter,moves);
    int i;
    Long nodes = 0;
    if (DEBUG) {
        writeContent(*file, move_counter, moves, lastMove);
    }
    if (depth == 0) {
        if (DEBUG) {
            closeNode(*file);
        }
        return 1;
    }
    for (i = 0; i < move_counter; i++) {
        this->make_move(moves[i]);
        nodes += perft(depth - 1,file,moves[i]);
        //cout << "num: " << nodes << endl;
        this->undo_move();
    }
    if (DEBUG) {
        closeNode(*file);
    }
    return nodes;
}
