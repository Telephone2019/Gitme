gitme+([[:space:]])show-local-branches+([[:space:]])*([a-z_\\"\\'[:space:]:-])[^:] )
mapfile -t COMPREPLY < <(compgen -W "-verbose: -help -strict-mode:" -- "$cur");;









