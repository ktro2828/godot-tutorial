#!/bin/bash

sudo mkdir -p /opt/godot
cd /opt/godot/
sudo wget https://downloads.tuxfamily.org/godotengine/3.4.4/Godot_v3.4.4-stable_x11.64.zip
sudo unzip Godot_v3.4.4-stable_x11.64.zip
sudo rm -rf Godot_v3.4.4-stable_x11.64.zip

if [ !e $HOME/.bash_aliases ]; then
    touch $HOME/.bash_aliases
fi

echo 'alias godot="/opt/godot/Godot_v3.4.4-stable_x11.64"' >> $HOME/.bash_aliases
source $HOME/.bashrc
