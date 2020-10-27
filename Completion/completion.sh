_gitme () # By convention, the function name starts with an '_'.
{
  local cur
  # Pointer to current completion word.
  # By convention, it's named "cur" but this isn't strictly necessary.
  local line
  # Pointer to current completion line.
  local subcommands="rename-branch  show-local-branches  "

  COMPREPLY=()
  # Array variable storing the possible completions.

  cur=${COMP_WORDS[COMP_CWORD]}
  line=${COMP_LINE}

  case "$line" in
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
