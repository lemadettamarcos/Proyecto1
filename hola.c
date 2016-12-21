#!/bin/bash

if [ -e "VirtualBox VMs/MiMaquina" ]
then
	VBoxManage unregistervm MiMaquina --delete
fi
#if [ -e "VirtualBox VMs/MiMaquina/midisco.vdi" ]
#then
#	rm midisco.vdi
#fi



VBoxManage createvm --name MiMaquina --ostype Linux26_64 --register
VBoxManage modifyvm MiMaquina --memory 2000
VBoxManage createmedium disk --filename "VirtualBox VMs/MiMaquina/midisco.vdi" --size 4000
VBoxManage storagectl MiMaquina --name busSata --add sata
VBoxManage storagectl MiMaquina --name busIde --add ide
VBoxManage storageattach MiMaquina --storagectl busSata --port 0 --device 0 --type hdd --medium "VirtualBox VMs/MiMaquina/midisco.vdi"
VBoxManage storageattach MiMaquina --storagectl busIde --port 0 --device 0 --type dvddrive --medium Baixades/ubuntu.iso
_____
