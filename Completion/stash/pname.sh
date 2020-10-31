gitme+([[:space:]])stash+([[:space:]])*(?)[^:] | gitme+([[:space:]])stash+([[:space:]]) )
mapfile -t COMPREPLY < <(compgen -W "-help -show: -show:<stash@{$num}> -apply: -apply:<stash@{$num}> -pop: -pop:<stash@{$num}> drop: drop:<stash@{$num}> -save-with-message: -save-with-message:<commit-message> -list -list: -list:(true\\ |\\ false) -clear -clear: -clear:(true\\ |\\ false) -strict-mode -strict-mode: -strict-mode:(on\\ |\\ off)" -- "$cur");;






