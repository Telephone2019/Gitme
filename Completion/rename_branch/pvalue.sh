gitme+([[:space:]])rename-branch+([[:space:]])*(?)+([[:space:]])[-]force[:] | gitme+([[:space:]])rename-branch+([[:space:]])[-]force[:] )
mapfile -t COMPREPLY < <(compgen -W "$bool" -- "$curp");;
gitme+([[:space:]])rename-branch+([[:space:]])*(?)+([[:space:]])[-]force[:]*([^[:space:]]) | gitme+([[:space:]])rename-branch+([[:space:]])[-]force[:]*([^[:space:]]) )
mapfile -t COMPREPLY < <(compgen -W "$bool" -- "$cur");;

gitme+([[:space:]])rename-branch+([[:space:]])*(?)+([[:space:]])[-]strict-mode[:] | gitme+([[:space:]])rename-branch+([[:space:]])[-]strict-mode[:] )
mapfile -t COMPREPLY < <(compgen -W "$smode" -- "$curp");;
gitme+([[:space:]])rename-branch+([[:space:]])*(?)+([[:space:]])[-]strict-mode[:]*([^[:space:]]) | gitme+([[:space:]])rename-branch+([[:space:]])[-]strict-mode[:]*([^[:space:]]) )
mapfile -t COMPREPLY < <(compgen -W "$smode" -- "$cur");;

gitme+([[:space:]])rename-branch+([[:space:]])*(?)+([[:space:]])[-]old-branch[:] | gitme+([[:space:]])rename-branch+([[:space:]])[-]old-branch[:] )
mapfile -t COMPREPLY < <(compgen -W "$branches" -- "$curp");;
gitme+([[:space:]])rename-branch+([[:space:]])*(?)+([[:space:]])[-]old-branch[:]*([^[:space:]]) | gitme+([[:space:]])rename-branch+([[:space:]])[-]old-branch[:]*([^[:space:]]) )
mapfile -t COMPREPLY < <(compgen -W "$branches" -- "$cur");;























