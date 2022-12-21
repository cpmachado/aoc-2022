FOLDERS = ${wildcard day-*}

clean:
	$(foreach folder,${FOLDERS}, make -C ${folder} clean;)
