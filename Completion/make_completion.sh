make_com_sh_dir="$( dirname "${BASH_SOURCE[0]}" )"
make_com_sh_wd="$( pwd )"
cd $make_com_sh_dir
cp completion_backup.sh completion.sh
echo "" | tee -a */subcommand.txt
echo "" | tee -a */pname.sh
sed -i "s/local subcommands=\".*\"/local subcommands=\"$(cat -s */subcommand.txt | tr '\n' ' ')\"/" completion.sh
sed -i "s/PNAME_HERE/$(cat -s */pname.sh | tr '\n' '\a')/" completion.sh
touch temp
tr '\a' '\n' < completion.sh > temp
mv temp completion.sh
. ./completion.sh
cd $make_com_sh_wd
