# bird-charmer
An instructions translator for galetron.
These are the possible instructions, what they do and how they're written.

Where
operation source_a source_b target immediate,

add
  target = source_a + source_b
addi
  target = source_a + immediate
sub
  target = source_a - source_b
subi
  target = source_a - immediate
times
  target = source_a * source_b
over
  target = source_a / source_b
andg
  target = source_a AND source_b
org
  target = source_a OR source_b
notg
  target = !source_a
pbranch
  if source_a == 0, FZ = 1
  if source_a < 0, FN = 1
branchz
  if FZ == 1, PC = PC + 1 + immediate
branchn
  if FN == 1, PC = PC + 1 + immediate
jump
  PC = immediate
jumpr
  PC = source_a
noo
  nothing
start_system
  instruction now will come from instructions memory
setlt
  if a < b, target = 1
  else target = 0
load
  source_a = memory[immediate]
store
  memory[immediate] = source_a
loadi
  source_a = immediate
loadi_hd
  source_a = hd[register_b][immediate]
input
  source_a = swithes
halt
  halt
output
  displays = source_a
loadr
  target = memory[source_a]
storer
  memory[source_a] = target
 store_hd
  memory[source_a] = target
load_hd
  target = memory[source_a]
store_i_ram
  memory[source_a] = target

For maps
[] line
() variable









noo 0 0 0 0
loadi 0 0 0 0
loadi_hd 22 0 0 1
loadi_hd 23 0 0 2
loadi_hd 24 0 0 3
load_hd 22 0 8 0
load_hd 23 0 9 0
load_hd 24 0 12 0
loadi 2 0 0 15
loadi 3 0 0 68
loadi 5 0 0 21
loadi 10 0 0 0
loadi 11 0 0 1
loadi 13 0 0 3
store_i_ram 10 0 8 0
store_i_ram 11 0 9 0
store_i_ram 13 0 12 0
start_system 0 0 0 0
