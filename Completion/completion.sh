_gitme () # By convention, the function name starts with an '_'.
{
  local cur
  # Pointer to current completion word.
  # By convention, it's named "cur" but this isn't strictly necessary.
  local line
  # Pointer to current completion line.
  local subcommands="rename-branch  show-local-branches  "
  local smode="on off"
  local bool="true false"
  local curp
  local branches

  COMPREPLY=()
  # Array variable storing the possible completions.

  cur=${COMP_WORDS[COMP_CWORD]}
  curp=${cur:1}
  line=${COMP_LINE}

  if [[ $(git rev-parse --is-inside-work-tree 2>&1) == *"true"* ]]; then
    branches=$({ git branch & git branch -r; } | cut -c 3- | tr '\n' ' ')
  else
    branches=""
  fi


  case "$line" in
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


gitme+([[:space:]])rename-branch+([[:space:]])*(?)[^:] | gitme+([[:space:]])rename-branch+([[:space:]]) )
mapfile -t COMPREPLY < <(compgen -W "-help -old-branch: -old-branch:<branch-name> -new-name: -new-name:<branch-name> -force -force: -force:(true\ |\ false) -strict-mode -strict-mode: -strict-mode:(on\ |\ off)" -- "$cur");;

gitme+([[:space:]])show-local-branches+([[:space:]])*(?)[^:] | gitme+([[:space:]])show-local-branches+([[:space:]]) )
mapfile -t COMPREPLY < <(compgen -W "-help -verbose -verbose: -verbose:(true\ |\ false) -strict-mode -strict-mode: -strict-mode:(on\ |\ off)" -- "$cur");;


    gitme+([[:space:]])*([a-z_\"\'-]) )
      mapfile -t COMPREPLY < <(compgen -W "$subcommands" -- "$cur");;
  esac

  return 0
}
complete -F _gitme gitme
