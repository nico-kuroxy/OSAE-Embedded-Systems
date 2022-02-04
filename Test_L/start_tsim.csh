PROJECT=Projet
BIN=$HOME/bin

export PROJECT
export BIN

$BIN/tsim-eval/tsim/linux-x64/tsim-leon3 -c $HOME/eclipse-workspace-cpu/$PROJECT/Test_L/tsim_init &

$BIN/bcc-2.2.0-gcc/bin/sparc-gaisler-elf-gdb $HOME/eclipse-workspace-cpu/$PROJECT/Debug/$PROJECT -d $HOME/eclipse-workspace-cpu/$PROJECT/src -batch -x $HOME/eclipse-workspace-cpu/$PROJECT/Test_L/gdb_batch_001.txt


