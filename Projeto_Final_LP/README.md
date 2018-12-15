# Projeto Final de LP
### Pet Fera

**Componetes:**

- Gleydvan Macedo
- João Vítor Venceslau Coelho

**Professor:**
	
- Silvio Costa Sampaio

## Objetivo
O objetivo deste trabalho é implementar um programa de cadastro de animais para a loja de animais silvestres Pet Fera.

## Tarefa
A tarefa central deste Projeto de Programação é desenvolver um programa em C++ para controlaro cadastro de animais silvestres da Pet Fera, segundo as características descritas anteriormente. Para resolver o problema, você deverá implementar um modelo de classes que reflita a situação descrita.

Durante a implementação do seu programa, faça uso os conceitos e boas práticas de Programação Orientação a Objetos aprendidas na disciplina. Você também deverá utilizar o Tipo Abstrato de Dados map disponível na STL para manter a lista de animais cadastrados, bem como possivelmente as listas de veterinários e tratadores.

A fim de permitir a reutilização de código em projetos futuros, organize o seu modelo de classes em uma biblioteca dinâmica de nome petfera.so (Linux) ou petfera.dll (Windows). Esta biblioteca deverá ser utilizada na construção dos programas que irão compor o sistema Pet Fera.

Considere ainda que o programa deverá manter em arquivo os dados processados, ou seja, sempre que o programa iniciar o mesmo deverá carregar os dados (se existirem) presentes nos arquivos correspondentes. O programa deverá utilizar como entrada dois arquivos no formato CSV (Comma-Separated Values), um com os dados básicos dos animais a serem cadastrados e outro com os dados dos funcionários (veterinários e tratadores) da Pet Fera.

Realize o devido tratamento de exceções para as operações de manipulação de arquivos e para a entrada (leitura) de dados por meio da criação das classes de exceção necessárias e lançamento dos respectivos objetos quando for o caso.

Uma vez realizadas as tarefas de implementação, você deverá elaborar um relatório simples contendo minimamente uma introdução, a fim de explicar o propósito do relatório e detalhes de implementação, descrevendo como foi feita a sua implementação em termos de arquivos, classes, métodos, etc. e como o programa funciona de maneira geral.

## Operações suportadas

	1 - Cadastrar animal a ser comercializado
	2 - Cadastrar Funcionario
	3 - Remover animal do banco de dados
	4 - Alterar dados cadastrais de um animal
	5 - Consultar dados de animais
	6 - Consultar dados de animais sob responsabilidade de um Veterinario ou Tratador
	7 - Remover Funcionario do banco de dados
	8 - Alterar dados cadastrais de um Funcionario
	9 - Consultar dados de um Funcionario
	10 - Quantidade de Funcionarios cadastrados
	11 - Quantidade de Animais cadastrados

## Programa auxiliar
Permite filtrar os animais de acordo com a classe, veterinario e tratador

	-c <classe>: este argumento opcional indica a classe de animais a serem exportados. Por	razões de simplicidade, deverá ser indicada apenas uma classe;
	-v <veterinario>: este argumento opcional indica que apenas animais sob a	responsabilidade do veterinário informado devem ser exportados. Por razões de	simplicidade, deverá ser indicado apenas um nome de veterinário.
	-t <tratador>: este argumento opcional indica que apenas animais tratados pelo tratador	informado devem ser exportados. Por razões de simplicidade, deverá ser indicado apenas	um tratador.
	<arquivo_saida>: este argumento obrigatório indica o nome do arquivo de saída, ou seja,	do arquivo onde serão guardados os dados a serem exportados.

Exemplo:

	./exportar -c <classe> -v <veterinario> -t <tratador> <arquivo_saida>
	
## Compilação
Certifique-se que os diretorios necessarios foram criados, utilize o 'make dir'
Para a compilação das questões utilize o comando 'make' no terminal do Linux.
Para gerar a documentação digite 'make doxy'.

## Executar os programas
Antes de executar digite
	
	make install
para copiar as bibliotecas no seu sistema e após o termino do programa, caso queira digite
	
	make uninstall
para deletar as bibliotecas que foram copiadas

Digite

	./bin/cadastrar
No terminal do Linux para executar a versão de cadastro
ou Digite

	./bin/exportar
No terminal do Linux para executar a versão de filtrar
