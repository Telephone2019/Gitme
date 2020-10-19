gitme+([[:space:]])rename-branch+([[:space:]])*([a-z_\\"\\'[:space:]:-])[^:] )
mapfile -t COMPREPLY < <(compgen -W "-old-branch: -new-name: -force: -help -strict-mode:" -- "$cur");;























