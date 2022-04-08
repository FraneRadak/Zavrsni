
from subprocess import Popen, PIPE, STDOUT

p = Popen(['stockfish'], stdout=PIPE, stdin=PIPE, stderr=PIPE)

file1 = open('test.txt', 'r')
Lines = file1.readlines()
for line in Lines:
    p = Popen(['stockfish'], stdout=PIPE, stdin=PIPE, stderr=PIPE)
    cmd='position fen '+line
    x=p.communicate(input=cmd.encode())
    p = Popen(['stockfish'], stdout=PIPE, stdin=PIPE, stderr=PIPE)
    stdout_data = p.communicate(input='go perft 1'.encode())
    response_string=stdout_data[0].decode('utf-8')
    arr=response_string.split('\n')
    num_of_moves=arr[len(arr)-3].split(' ')[2]
    print(num_of_moves)
