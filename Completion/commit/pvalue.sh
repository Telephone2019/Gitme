gitme+([[:space:]])commit+([[:space:]])*(?)+([[:space:]])[-]strict-mode[:] | gitme+([[:space:]])commit+([[:space:]])[-]strict-mode[:] )
mapfile -t COMPREPLY < <(compgen -W "$smode" -- "$curp");;
gitme+([[:space:]])commit+([[:space:]])*(?)+([[:space:]])[-]strict-mode[:]*([^[:space:]]) | gitme+([[:space:]])commit+([[:space:]])[-]strict-mode[:]*([^[:space:]]) )
mapfile -t COMPREPLY < <(compgen -W "$smode" -- "$cur");;

gitme+([[:space:]])commit+([[:space:]])*(?)+([[:space:]])[-]add-before-commit[:] | gitme+([[:space:]])commit+([[:space:]])[-]add-before-commit[:] )
mapfile -t COMPREPLY < <(compgen -W "$bool" -- "$curp");;
gitme+([[:space:]])commit+([[:space:]])*(?)+([[:space:]])[-]add-before-commit[:]*([^[:space:]]) | gitme+([[:space:]])commit+([[:space:]])[-]add-before-commit[:]*([^[:space:]]) )
mapfile -t COMPREPLY < <(compgen -W "$bool" -- "$cur");;





