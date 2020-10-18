_gitme () # By convention, the function name starts with an '_'.
{
  local cur
  # Pointer to current completion word.
  # By convention, it's named "cur" but this isn't strictly necessary.
  local line
  # Pointer to current completion line.
  local subcommands="rename-branch  "

  COMPREPLY=()
  # Array variable storing the possible completions.

  cur=${COMP_WORDS[COMP_CWORD]}
  line=${COMP_LINE}

  case "$line" in
gitme+([[:space:]])rename-branch+([[:space:]])*([a-z_\"\'-]) )
mapfile -t COMPREPLY < <(compgen -W "-old-branch: -new-name: -force: -help -strict-mode:" -- "$cur");;


    gitme+([[:space:]])*([a-z_\"\'-]) )
      mapfile -t COMPREPLY < <(compgen -W "$subcommands" -- "$cur");;
  esac

  return 0
}
complete -F _gitme gitme
