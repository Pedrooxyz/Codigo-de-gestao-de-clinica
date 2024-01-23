all: exec

exec: main.o GereDietas.o GerePacientes.o
	gcc main.o GereDietas.o GerePacientes.o -o exec

main.o: main.c Dados.h Funcoes.h
	gcc -c main.c -o main.o

GereDietas.o: GereDietas.c Funcoes.h Dados.h
	gcc -c GereDietas.c -o GereDietas.o

GerePacientes.o: GerePacientes.c Funcoes.h Dados.h
	gcc -c GerePacientes.c -o GerePacientes.o
	
run2f: exec
	./exec Pacientes.csv Dietas.csv

run3f: exec
	./exec Pacientes.csv Dietas.csv PlanosNutri.csv

ajuda: exec
	./exec -ajuda 

tab2f: exec
	./exec -tab tPacientes.csv tDietas.csv

tab3f: exec 
	./exec -tab tPacientes.csv tDietas.csv tPlanosNutri.csv

clean: 
	rm *.o exec planosstdin.csv tplanosstdin.csv ExpPacientes.csv ExpDietas.csv ExpPlanoNutricional.csv 