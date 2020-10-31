gitme+([[:space:]])commit+([[:space:]])*(?)[^:] | gitme+([[:space:]])commit+([[:space:]]) )
mapfile -t COMPREPLY < <(compgen -W "-help -temporary-config: -temporary-config:<config-command> -with-message: -with-message:<commit-message> -add-before-commit -add-before-commit: -add-before-commit:(true\\ |\\ false) -strict-mode -strict-mode: -strict-mode:(on\\ |\\ off)" -- "$cur");;










