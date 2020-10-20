gitme+([[:space:]])show-local-branches+([[:space:]])*([a-z_\\"\\'[:space:]:-])[^:] | gitme+([[:space:]])show-local-branches+([[:space:]]) )
mapfile -t COMPREPLY < <(compgen -W "-verbose: -help -strict-mode:" -- "$cur");;


















