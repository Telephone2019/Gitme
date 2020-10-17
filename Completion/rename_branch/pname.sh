gitme+([[:space:]])rename-branch+([[:space:]])*([a-z_\\"\\'-]) )
mapfile -t COMPREPLY < <(compgen -W "-old-branch: -new-name: -force: -help" -- "$cur");;













