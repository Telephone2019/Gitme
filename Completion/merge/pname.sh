gitme+([[:space:]])commit+([[:space:]])*(?)[^:] | gitme+([[:space:]])commit+([[:space:]]) )
mapfile -t COMPREPLY < <(compgen -W "-help -current-branch: -current-branch:<branch-name> -current-branch-no-commit: -current-branch-no-commit:<branch-name> -ohther-branch: -ohther-branch:<two-branches-names> -strict-mode -strict-mode: -strict-mode:(on\\ |\\ off)" -- "$cur");;










