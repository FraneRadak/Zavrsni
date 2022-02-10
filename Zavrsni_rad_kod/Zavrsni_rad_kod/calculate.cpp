#include "board.hpp"
#include "PositionStack.hpp"

Long Position::perft(int depth) {
    int move_counter = 0;
    Move* moves = move_generator(move_counter);
    int n_moves, i;
    Long nodes = 0;

    if (depth == 0)
        return 1ULL;

    for (i = 0; i < move_counter; i++) {
        this->make_move(moves[i]);
        nodes += perft(depth - 1);
        //cout << "num: " << nodes << endl;
        this->undo_move();
    }
    return nodes;
}
