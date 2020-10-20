gitme+([[:space:]])show-local-branches+([[:space:]])*(?)[^:] | gitme+([[:space:]])show-local-branches+([[:space:]]) )
mapfile -t COMPREPLY < <(compgen -W "-verbose: -help -strict-mode:" -- "$cur");;























