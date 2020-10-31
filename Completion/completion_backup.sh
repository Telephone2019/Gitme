_gitme () # By convention, the function name starts with an '_'.
{
  local cur
  # Pointer to current completion word.
  # By convention, it's named "cur" but this isn't strictly necessary.
  local line
  # Pointer to current completion line.
  local subcommands=""
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
PVALUE_HERE
PNAME_HERE
    gitme+([[:space:]])*([a-z_\"\'-]) )
      mapfile -t COMPREPLY < <(compgen -W "$subcommands" -- "$cur");;
  esac

  return 0
}
complete -F _gitme gitme
