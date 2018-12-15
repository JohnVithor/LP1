/**
 * @file Pet_Fera_Cadastro.cpp
 * @brief      Implementação da classe Pet_Fera_Cadastro, seus atributos e métodos
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      03/12/2017
 * @date       09/12/2017
 */

#include "Pet_Fera_Cadastro.hpp"
using namespace PetFera;

Pet_Fera_Cadastro::~Pet_Fera_Cadastro()
{
	for (auto i = m_tabela_anfibio.begin(); i != m_tabela_anfibio.end(); ++i)
	{
		delete (i->second);
	}
	for (auto i = m_tabela_mamifero.begin(); i != m_tabela_mamifero.end(); ++i)
	{
		delete (i->second);
	}
	for (auto i = m_tabela_reptil.begin(); i != m_tabela_reptil.end(); ++i)
	{
		delete (i->second);
	}
	for (auto i = m_tabela_ave.begin(); i != m_tabela_ave.end(); ++i)
	{
		delete (i->second);
	}
	for (auto i = m_tabela_funcionario.begin(); i != m_tabela_funcionario.end(); ++i)
	{
		delete (i->second);
	}
}

void Pet_Fera_Cadastro::cadastrar_anfibio( std::string _classe, std::string _tipo )
{
	std::string aux;
	int 		_id;
	std::string _nome;
	std::string _cientifico;
	char 		_sexo;
	float 		_tamanho;
	std::string _dieta;
	int 		_id_veterinario;
	int			_id_tratador;
	std::string _batismo;
	int			_total_mudas;
	std::string _ultima_muda;
	std::string _ibama;
	std::string _uf_origem;
	std::string _autorizacao;
	std::string _pais_origem;

	std::cin.clear();
	std::cin.ignore(200,'\n');
	std::cout << "Numero de Identificacao do Animal (ID): ";
	std::getline(std::cin, aux);
	_id = std::stoi(aux);

	std::cout << "\nNome: ";
	std::getline(std::cin, _nome);

	std::cout << "\nNome Cientifico: ";
	std::getline(std::cin, _cientifico);

	std::cout << "\nSexo: ";
	std::getline(std::cin, aux);
	_sexo = aux[0];

	std::cout << "\nTamanho: ";
	std::getline(std::cin, aux);
	_tamanho = std::stof(aux);

	std::cout << "\nDieta: ";
	std::getline(std::cin, _dieta);

	std::cout << "\nID do Veterinario responsavel: ";
	std::getline(std::cin, aux);
	_id_veterinario = std::stoi(aux);

	std::cout << "\nID do Tratador responsavel: ";
	std::getline(std::cin, aux);
	_id_tratador = std::stoi(aux);

	std::cout << "\nNome de batismo: ";
	std::getline(std::cin, _batismo);

	std::cout << "\nTotal de mudas: ";
	std::getline(std::cin, aux);
	_total_mudas = std::stoi(aux);

	std::cout << "\nData da ultima muda (DD/MM/AAAA): ";
	std::getline(std::cin, _ultima_muda);

	Funcionario * tratador_resp = nullptr;
	Funcionario * veterinario_resp = nullptr;

	if( m_tabela_funcionario.find( _id_tratador ) != m_tabela_funcionario.end() )
		tratador_resp = m_tabela_funcionario[ _id_tratador ];
	if( m_tabela_funcionario.find( _id_veterinario ) != m_tabela_funcionario.end() )
		veterinario_resp = m_tabela_funcionario[ _id_veterinario ];

	if( _tipo.compare( "Domestico" ) == 0 )
	{

		Anfibio * anfibio_domestico = new Anfibio( _id, _classe, _tipo, _nome, _cientifico
													, _sexo, _tamanho, _dieta, veterinario_resp
													, tratador_resp, _batismo, _total_mudas, _ultima_muda);

		m_tabela_anfibio.insert( std::pair<int, Anfibio*> ( _id, anfibio_domestico ) );
	} else if( _tipo.compare( "Nativo" ) == 0 )
	{
		std::cout << "\nID do Ibama: ";
		std::getline(std::cin, _ibama);
		std::cout << "\nEstado de Origem: ";
		std::getline(std::cin, _uf_origem);
		std::cout << "\nAutorizacao do Ibama: ";
		std::getline(std::cin, _autorizacao);

		Anfibio * anfibio_nativo = new AnfibioNativo( _id, _classe, _tipo, _nome, _cientifico
													, _sexo, _tamanho, _dieta, veterinario_resp
													, tratador_resp, _batismo, _total_mudas, _ultima_muda
													, _ibama, _uf_origem, _autorizacao );

		m_tabela_anfibio.insert( std::pair<int, Anfibio*> ( _id, anfibio_nativo ) );

	} else if( _tipo.compare( "Exotico" ) == 0 )
	{
		std::cout << "\nID do Ibama: ";
		std::getline(std::cin, _ibama);
		std::cout << "\nPais de Origem: ";
		std::getline(std::cin, _pais_origem);

		Anfibio * anfibio_exotico = new AnfibioExotico( _id, _classe, _tipo, _nome, _cientifico
													, _sexo, _tamanho, _dieta, veterinario_resp
													, tratador_resp, _batismo, _total_mudas, _ultima_muda
													, _ibama, _pais_origem );

		m_tabela_anfibio.insert( std::pair<int, Anfibio*> ( _id, anfibio_exotico ) );		
	}
	std::cout << "Animal cadastrado com sucesso!" << std::endl;
}

void Pet_Fera_Cadastro::cadastrar_mamifero( std::string _classe, std::string _tipo )
{
	std::string aux;
	int 		_id;
	std::string _nome;
	std::string _cientifico;
	char 		_sexo;
	float 		_tamanho;
	std::string _dieta;
	int 		_id_veterinario;
	int			_id_tratador;
	std::string _batismo;
	std::string _cor_pelo;
	std::string _ibama;
	std::string _uf_origem;
	std::string _autorizacao;
	std::string _pais_origem;

	std::cin.clear();
	std::cin.ignore(200,'\n');
	std::cout << "Numero de Identificacao do Animal (ID): ";
	std::getline(std::cin, aux);
	_id = std::stoi(aux);

	std::cout << "\nNome: ";
	std::getline(std::cin, _nome);

	std::cout << "\nNome Cientifico: ";
	std::getline(std::cin, _cientifico);

	std::cout << "\nSexo: ";
	std::getline(std::cin, aux);
	_sexo = aux[0];

	std::cout << "\nTamanho: ";
	std::getline(std::cin, aux);
	_tamanho = std::stoi(aux);

	std::cout << "\nDieta: ";
	std::getline(std::cin, _dieta);

	std::cout << "\nID do Veterinario responsavel: ";
	std::getline(std::cin, aux);
	_id_veterinario = std::stoi(aux);

	std::cout << "\nID do Tratador responsavel: ";
	std::getline(std::cin, aux);
	_id_tratador = std::stoi(aux);

	std::cout << "\nNome de batismo: ";
	std::getline(std::cin, _batismo);	

	std::cout << "\nCor do pelo do animal: ";
	std::getline(std::cin, _cor_pelo);

	Funcionario * tratador_resp = nullptr;
	Funcionario * veterinario_resp = nullptr;

	if( m_tabela_funcionario.find( _id_tratador ) != m_tabela_funcionario.end() )
		tratador_resp = m_tabela_funcionario[ _id_tratador ];

	if( m_tabela_funcionario.find( _id_veterinario ) != m_tabela_funcionario.end() )
		veterinario_resp = m_tabela_funcionario[ _id_veterinario ];

	if( _tipo.compare( "Domestico" ) == 0 )
	{

		Mamifero * mamifero_domestico = new Mamifero( _id, _classe, _tipo, _nome, _cientifico
													, _sexo, _tamanho, _dieta, veterinario_resp
													, tratador_resp, _batismo, _cor_pelo);

		m_tabela_mamifero.insert( std::pair<int, Mamifero*> ( _id, mamifero_domestico ) );
	
	} else if( _tipo.compare( "Nativo" ) == 0 )
	{

		std::cout << "\nID do Ibama: ";
		std::getline(std::cin, _ibama);
		std::cout << "\nEstado de Origem: ";
		std::getline(std::cin, _uf_origem);
		std::cout << "\nAutorizacao do Ibama: ";
		std::getline(std::cin, _autorizacao);

		Mamifero * mamifero_nativo = new MamiferoNativo( _id, _classe, _tipo, _nome, _cientifico
													, _sexo, _tamanho, _dieta, veterinario_resp
													, tratador_resp, _batismo, _cor_pelo
													, _ibama, _uf_origem, _autorizacao );

		m_tabela_mamifero.insert( std::pair<int, Mamifero*> ( _id, mamifero_nativo ) );

	} else if( _tipo.compare( "Exotico" ) == 0 )
	{
		std::cout << "\nID do Ibama: ";
		std::getline(std::cin, _ibama);
		std::cout << "\nPais de Origem: ";
		std::getline(std::cin, _pais_origem);

		Mamifero * mamifero_exotico = new MamiferoExotico( _id, _classe, _tipo, _nome, _cientifico
													, _sexo, _tamanho, _dieta, veterinario_resp
													, tratador_resp, _batismo, _cor_pelo
													, _ibama, _pais_origem );

		m_tabela_mamifero.insert( std::pair<int, Mamifero*> ( _id, mamifero_exotico ) );
	}

	std::cout << "\nAnimal cadastrado com sucesso\n" << std::endl;

}

void Pet_Fera_Cadastro::cadastrar_reptil( std::string _classe, std::string _tipo )
{
	std::string aux;
	int 		_id;
	std::string _nome;
	std::string _cientifico;
	char 		_sexo;
	float 		_tamanho;
	std::string _dieta;
	int 		_id_veterinario;
	int			_id_tratador;
	std::string _batismo;
	std::string	_venenoso;
	std::string _tipo_veneno;
	bool possui_veneno = false;
	std::string _ibama;
	std::string _uf_origem;
	std::string _autorizacao;
	std::string _pais_origem;

	std::cin.clear();
	std::cin.ignore(200,'\n');
	std::cout << "Numero de Identificacao do Animal (ID): ";
	std::getline(std::cin, aux);
	_id = std::stoi(aux);

	std::cout << "\nNome: ";
	std::getline(std::cin, _nome);

	std::cout << "\nNome Cientifico: ";
	std::getline(std::cin, _cientifico);

	std::cout << "\nSexo: ";
	std::getline(std::cin, aux);
	_sexo = aux[0];

	std::cout << "\nTamanho: ";
	std::getline(std::cin, aux);
	_tamanho = std::stoi(aux);

	std::cout << "\nDieta: ";
	std::getline(std::cin, _dieta);

	std::cout << "\nID do Veterinario responsavel: ";
	std::getline(std::cin, aux);
	_id_veterinario = std::stoi(aux);

	std::cout << "\nID do Tratador responsavel: ";
	std::getline(std::cin, aux);
	_id_tratador = std::stoi(aux);

	std::cout << "\nNome de batismo: ";
	std::getline(std::cin, _batismo);	

	std::cout << "\nAnimal venenoso ( Sim ou Nao ): ";
	std::getline(std::cin, _venenoso);

	if( _venenoso.compare( "Sim" ) == 0 or _venenoso.compare( "sim" ) == 0 )
	{
		std::cout << "\nTipo do veneno: ";
		std::getline(std::cin, _tipo_veneno);
		possui_veneno = true;

	} else
	{
		_tipo_veneno = "Nenhum";
	}

	Funcionario * tratador_resp = nullptr;
	Funcionario * veterinario_resp = nullptr;

	if( m_tabela_funcionario.find( _id_tratador ) != m_tabela_funcionario.end() )
		tratador_resp = m_tabela_funcionario[ _id_tratador ];

	if( m_tabela_funcionario.find( _id_veterinario ) != m_tabela_funcionario.end() )
		veterinario_resp = m_tabela_funcionario[ _id_veterinario ];

	if( _tipo.compare( "Domestico" ) == 0 )
	{


		Reptil * reptil_domestico = new Reptil( _id, _classe, _tipo, _nome, _cientifico
													, _sexo, _tamanho, _dieta, veterinario_resp
													, tratador_resp, _batismo, possui_veneno, _tipo_veneno);

		m_tabela_reptil.insert( std::pair<int, Reptil*> ( _id, reptil_domestico ) );

	} else if( _tipo.compare( "Nativo" ) == 0 )
	{

		std::cout << "\nID do Ibama: ";
		std::getline(std::cin, _ibama);
		std::cout << "\nEstado de Origem: ";
		std::getline(std::cin, _uf_origem);
		std::cout << "\nAutorizacao do Ibama: ";
		std::getline(std::cin, _autorizacao);

		Reptil * reptil_nativo = new ReptilNativo( _id, _classe, _tipo, _nome, _cientifico
													, _sexo, _tamanho, _dieta, veterinario_resp
													, tratador_resp, _batismo, possui_veneno, _tipo_veneno
													, _ibama, _uf_origem, _autorizacao );

		m_tabela_reptil.insert( std::pair<int, Reptil*> ( _id, reptil_nativo ) );
		
	} else if( _tipo.compare( "Exotico" ) == 0 )
	{

		std::cout << "\nID do Ibama: ";
		std::getline(std::cin, _ibama);
		std::cout << "\nPais de Origem: ";
		std::getline(std::cin, _pais_origem);
		
		Reptil * reptil_exotico = new ReptilExotico( _id, _classe, _tipo, _nome, _cientifico
													, _sexo, _tamanho, _dieta, veterinario_resp
													, tratador_resp, _batismo, possui_veneno, _tipo_veneno
													, _ibama, _pais_origem );

		m_tabela_reptil.insert( std::pair<int, Reptil*> ( _id, reptil_exotico ) );

	}

	std::cout << "\nAnimal cadastrado com sucesso\n" << std::endl;

}

void Pet_Fera_Cadastro::cadastrar_ave( std::string _classe, std::string _tipo )
{
	std::string aux;
	int 		_id;
	std::string _nome;
	std::string _cientifico;
	char 		_sexo;
	float 		_tamanho;
	std::string _dieta;
	int 		_id_veterinario;
	int			_id_tratador;
	std::string _batismo;
	float		_tamanho_bico;
	float 		_envergadura;
	std::string _ibama;
	std::string _uf_origem;
	std::string _autorizacao;
	std::string _pais_origem;

	std::cin.clear();
	std::cin.ignore(200,'\n');
	std::cout << "Numero de Identificacao do Animal (ID): ";
	std::getline(std::cin, aux);
	_id = std::stoi(aux);

	std::cout << "\nNome: ";
	std::getline(std::cin, _nome);

	std::cout << "\nNome Cientifico: ";
	std::getline(std::cin, _cientifico);

	std::cout << "\nSexo: ";
	std::getline(std::cin, aux);
	_sexo = aux[0];

	std::cout << "\nTamanho: ";
	std::getline(std::cin, aux);
	_tamanho = std::stoi(aux);

	std::cout << "\nDieta: ";
	std::getline(std::cin, _dieta);

	std::cout << "\nID do Veterinario responsavel: ";
	std::getline(std::cin, aux);
	_id_veterinario = std::stoi(aux);

	std::cout << "\nID do Tratador responsavel: ";
	std::getline(std::cin, aux);
	_id_tratador = std::stoi(aux);

	std::cout << "\nNome de batismo: ";
	std::getline(std::cin, _batismo);

	std::cout << "\nTamanho do bico do animal: ";
	std::getline(std::cin, aux);
	_tamanho_bico = std::stoi(aux);

	std::cout << "\nEnvergadura do animal: ";
	std::getline(std::cin, aux);
	_envergadura = std::stoi(aux);

	Funcionario * tratador_resp = nullptr;
	Funcionario * veterinario_resp = nullptr;

	if( m_tabela_funcionario.find( _id_tratador ) != m_tabela_funcionario.end() )
		tratador_resp = m_tabela_funcionario[ _id_tratador ];

	if( m_tabela_funcionario.find( _id_veterinario ) != m_tabela_funcionario.end() )
		veterinario_resp = m_tabela_funcionario[ _id_veterinario ];

	if( _tipo.compare( "Domestico" ) == 0 )
	{


		Ave * ave_domestico = new Ave( _id, _classe, _tipo, _nome, _cientifico
													, _sexo, _tamanho, _dieta, veterinario_resp
													, tratador_resp, _batismo, _tamanho_bico, _envergadura);

		m_tabela_ave.insert( std::pair<int, Ave*> ( _id, ave_domestico ) );

	
	} else if( _tipo.compare( "Nativo" ) == 0 )
	{

		std::cout << "\nID do Ibama: ";
		std::getline(std::cin, _ibama);
		std::cout << "\nEstado de Origem: ";
		std::getline(std::cin, _uf_origem);
		std::cout << "\nAutorizacao do Ibama: ";
		std::getline(std::cin, _autorizacao);

		Ave * ave_nativo = new AveNativo( _id, _classe, _tipo, _nome, _cientifico
													, _sexo, _tamanho, _dieta, veterinario_resp
													, tratador_resp, _batismo, _tamanho_bico, _envergadura
													, _ibama, _uf_origem, _autorizacao );

		m_tabela_ave.insert( std::pair<int, Ave*> ( _id, ave_nativo ) );
		

	} else if( _tipo.compare( "Exotico" ) == 0 )
	{

		std::cout << "\nID do Ibama: ";
		std::getline(std::cin, _ibama);
		std::cout << "\nPais de Origem: ";
		std::getline(std::cin, _pais_origem);

		Ave * ave_exotico = new AveExotico( _id, _classe, _tipo, _nome, _cientifico
													, _sexo, _tamanho, _dieta, veterinario_resp
													, tratador_resp, _batismo, _tamanho_bico, _envergadura
													, _ibama, _pais_origem );

		m_tabela_ave.insert( std::pair<int, Ave*> ( _id, ave_exotico ) );


	}

	std::cout << "\nAnimal cadastrado com sucesso\n" << std::endl;

}

void Pet_Fera_Cadastro::cadastrar_funcionario( std::string _funcao )
{
	std::string aux;
	int 		_id;
	std::string _nome;
	std::string _CPF;
	short 		_idade;
	std::string	_tipo_sangue;		// A / B / AB / O
	char 		_fator_RH;			// + / -
	std::string _especialidade;

	std::cin.clear();
	std::cin.ignore(200,'\n');
	std::cout << "Numero de Identificacao do Funcionario (ID): ";
	std::getline(std::cin, aux);
	_id = std::stoi(aux);

	std::cout << "\nNome do Funcionario: ";
	std::getline(std::cin, _nome);

	std::cout << "\nCPF do Funcionario: ";
	std::getline(std::cin, _CPF);

	std::cout << "\nIdade do Funcionario: ";
	std::getline(std::cin, aux);
	_idade = std::stoi(aux);

	std::cout << "\nTipo sanguineo do Funcionario: ";
	std::getline(std::cin, _tipo_sangue);

	std::cout << "\nFator RH do tipo sanguineo: ";
	std::getline(std::cin, aux);
	_fator_RH = aux[0];

	std::cout << "\nEspecialidade: " << std::endl;
	std::getline(std::cin, _especialidade);

	if( _funcao.compare( "Tratador" ) == 0  )
	{

		Funcionario * novo_tratador = new Tratador( _id, _funcao, _nome, _CPF, _idade, _tipo_sangue, _fator_RH, _especialidade );
		m_tabela_funcionario.insert( std::pair<int, Funcionario*> ( _id, novo_tratador ) );

	} else if ( _funcao.compare( "Veterinario" ) == 0  )
	{

		Funcionario * novo_veterinario = new Veterinario( _id, _funcao, _nome, _CPF, _idade, _tipo_sangue, _fator_RH, _especialidade );
		m_tabela_funcionario.insert( std::pair<int, Funcionario*> ( _id, novo_veterinario ) );

	}

	std::cout << "\nFuncionario cadastrado com sucesso\n" << std::endl;

}

void Pet_Fera_Cadastro::consultar_animais( int _id )
{

	std::map< int, Anfibio* >::iterator it_anf = m_tabela_anfibio.find( _id );
	std::map< int, Mamifero* >::iterator it_mam = m_tabela_mamifero.find( _id );
	std::map< int, Reptil* >::iterator it_rep = m_tabela_reptil.find( _id );
	std::map< int, Ave* >::iterator it_ave = m_tabela_ave.find( _id );


	if( it_anf != m_tabela_anfibio.end() )
	{

		std::cout << "Dados do Animal procurado: " << std::endl;
		std::cout << *(it_anf -> second);

	} else if( it_mam != m_tabela_mamifero.end() )
	{

		std::cout << "Dados do Animal procurado: " << std::endl;
		std::cout << *(it_mam -> second);

	} else if( it_rep != m_tabela_reptil.end() )
	{

		std::cout << "Dados do Animal procurado: " << std::endl;
		std::cout << *(it_rep -> second);

	} else if( it_ave != m_tabela_ave.end() )
	{

		std::cout << "Dados do Animal procurado: " << std::endl;
		std::cout << *(it_ave -> second);

	} else
		std::cout << "Animal nao encontrado!" << std::endl;

}

void Pet_Fera_Cadastro::consultar_animais_funcionario( int _id )
{

	std::map< int, Anfibio* >::iterator it_anf = m_tabela_anfibio.begin();
	std::map< int, Mamifero* >::iterator it_mam = m_tabela_mamifero.begin();
	std::map< int, Reptil* >::iterator it_rep = m_tabela_reptil.begin();
	std::map< int, Ave* >::iterator it_ave = m_tabela_ave.begin();

	std::map< int, Funcionario* >::iterator it_func = m_tabela_funcionario.find( _id );

	if( it_func != m_tabela_funcionario.end() )
	{
		std::cout << "\nLista dos Animais relacionados ao respectivo Funcionario: " << std::endl;

		while( it_anf != m_tabela_anfibio.end() )
		{

			if( it_anf -> second -> get_veterinario() -> get_id() == _id
				or it_anf -> second -> get_tratador() -> get_id() == _id )
				std::cout << *(it_anf -> second);

			++it_anf;
		}

		while( it_mam != m_tabela_mamifero.end() )
		{

			if( it_mam -> second -> get_veterinario() -> get_id() == _id
				or it_mam -> second -> get_tratador() -> get_id() == _id )
				std::cout << *(it_mam -> second);

			++it_mam;
		}

		while( it_rep != m_tabela_reptil.end() )
		{

			if( it_rep -> second -> get_veterinario() -> get_id() == _id
				or it_rep -> second -> get_tratador() -> get_id() == _id )
				std::cout << *(it_rep -> second);

			++it_rep;
		}

		while( it_ave != m_tabela_ave.end() )
		{

			if( it_ave -> second -> get_veterinario() -> get_id() == _id
				or it_ave -> second -> get_tratador() -> get_id() == _id )
				std::cout << *(it_ave -> second);

			++it_ave;
		}

	} else 
		std::cout << "Nao existe Funcionario com o ID fornecido" << std::endl;

}

void Pet_Fera_Cadastro::consultar_funcionarios( int _id )
{
	
	std::map< int, Funcionario* >::iterator it_func =  m_tabela_funcionario.find( _id );
	std::cout << std::endl << m_tabela_funcionario.size()  <<std::endl;
	if( it_func != m_tabela_funcionario.end() )
		std::cout << *(it_func -> second);
	else
		std::cout << "Funcionario nao encontrado" << std::endl;

}

void Pet_Fera_Cadastro::remover_funcionario( int _id )
{

	std::map< int, Funcionario* >::iterator it_func =  m_tabela_funcionario.find( _id );

	if( it_func != m_tabela_funcionario.end() )
	{

		m_tabela_funcionario.erase( it_func );
		std::cout << "Funcionario Removido com sucesso!" << std::endl;

	}else
		std::cout << "Funcionario nao encontrado" << std::endl;

}

void Pet_Fera_Cadastro::remover_animal( int _id )
{

	std::map< int, Anfibio* >::iterator it_anf = m_tabela_anfibio.find( _id );
	std::map< int, Mamifero* >::iterator it_mam = m_tabela_mamifero.find( _id );
	std::map< int, Reptil* >::iterator it_rep = m_tabela_reptil.find( _id );
	std::map< int, Ave* >::iterator it_ave = m_tabela_ave.find( _id );

	if( it_anf != m_tabela_anfibio.end() )
		m_tabela_anfibio.erase( it_anf );
	else if( it_mam != m_tabela_mamifero.end() )
		m_tabela_mamifero.erase( it_mam );
	else if( it_rep != m_tabela_reptil.end() )
		m_tabela_reptil.erase( it_rep );
	else if( it_ave != m_tabela_ave.end() )
		m_tabela_ave.erase( it_ave );
	else
		std::cout << "Animal nao encontrado!" << std::endl;

	std::cout << "\nAnimal removido com sucesso\n" << std::endl;

}

void Pet_Fera_Cadastro::alterar_dados_animais( int _id )
{
	std::map< int, Anfibio* >::iterator it_anf = m_tabela_anfibio.find( _id );
	std::map< int, Mamifero* >::iterator it_mam = m_tabela_mamifero.find( _id );
	std::map< int, Reptil* >::iterator it_rep = m_tabela_reptil.find( _id );
	std::map< int, Ave* >::iterator it_ave = m_tabela_ave.find( _id );

	if( it_anf != m_tabela_anfibio.end() )
	{
		std::string aux;
		std::string _nome;
		float		_tamanho;
		std::string _dieta;
		int 		_id_veterinario;
		int			_id_tratador;
		int			_total_mudas;
		std::string _ultima_muda;

		Funcionario * veterinario_resp = nullptr;
		Funcionario * tratador_resp = nullptr;

		std::cout << *(it_anf -> second);

		std::cout << "\nLista dos dasdos que podem ser alterados:  ";
		std::cout << "Nome, Tamanho, Dieta, Veterinario, Tratador, Total de Mudas, Data da Ultima Muda" << std::endl;
		std::cout << "\n>>>>>	Digite os novos dados	<<<<<\n" << std::endl;
		std::cout << "\nNome: ";
		std::getline(std::cin, _nome);

		std::cout << "\nTamanho: ";
		std::getline(std::cin, aux);
		_tamanho = std::stoi(aux);

		std::cout << "\nDieta: ";
		std::getline(std::cin, _dieta);

		std::cout << "\nID do Veterinario: ";
		std::getline(std::cin, aux);
		_id_veterinario = std::stoi(aux);

		std::cout << "\nID do Tratador:  ";
		std::getline(std::cin, aux);
		_id_tratador = std::stoi(aux);

		std::cout << "\nTotal de Mudas:  ";
		std::getline(std::cin, aux);
		_total_mudas = std::stof(aux);

		std::cout << "\nUltima Muda (DD/MM/AAAA):  ";
		std::getline(std::cin, _ultima_muda);

		it_anf -> second -> set_nome( _nome );
		it_anf -> second -> set_tamanho( _tamanho );
		it_anf -> second -> set_dieta( _dieta );

		if( m_tabela_funcionario.find( _id_tratador ) != m_tabela_funcionario.end() )
			tratador_resp = m_tabela_funcionario[ _id_tratador ];

		if( m_tabela_funcionario.find( _id_veterinario ) != m_tabela_funcionario.end() )
			veterinario_resp = m_tabela_funcionario[ _id_veterinario ];

		it_anf -> second -> set_veterinario( veterinario_resp );
		it_anf -> second -> set_tratador( tratador_resp );

		it_anf -> second -> set_total_mudas( _total_mudas );
		it_anf -> second -> set_ultima_muda( _ultima_muda );

		std::cout << std::endl;
		std::cout << "\nDados alterados com sucesso\n" << std::endl;

	}
	else if( it_mam != m_tabela_mamifero.end() )
	{
		std::string aux;
		std::string _nome;
		float		_tamanho;
		std::string _dieta;
		int 		_id_veterinario;
		int			_id_tratador;

		Funcionario * veterinario_resp = nullptr;
		Funcionario * tratador_resp = nullptr;

		std::cout << *(it_mam -> second);

		std::cout << "\nLista dos dasdos que podem ser alterados:  ";
		std::cout << "Nome, Tamanho, Dieta, Veterinario, Tratador" << std::endl;
		std::cout << "\n>>>>>	Digite os novos dados	<<<<<\n" << std::endl;
		std::cout << "\nNome: ";
		std::getline(std::cin, _nome);

		std::cout << "\nTamanho: ";
		std::getline(std::cin, aux);
		_tamanho = std::stof(aux);

		std::cout << "\nDieta: ";
		std::getline(std::cin, _dieta);

		std::cout << "\nID do Veterinario: ";
		std::getline(std::cin, aux);
		_id_veterinario = std::stoi(aux);

		std::cout << "\nID do Tratador:  ";
		std::getline(std::cin, aux);
		_id_tratador = std::stoi(aux);

		it_mam -> second -> set_nome( _nome );
		it_mam -> second -> set_tamanho( _tamanho );
		it_mam -> second -> set_dieta( _dieta );

		if( m_tabela_funcionario.find( _id_tratador ) != m_tabela_funcionario.end() )
			tratador_resp = m_tabela_funcionario[ _id_tratador ];

		if( m_tabela_funcionario.find( _id_veterinario ) != m_tabela_funcionario.end() )
			veterinario_resp = m_tabela_funcionario[ _id_veterinario ];

		it_mam -> second -> set_veterinario( veterinario_resp );
		it_mam -> second -> set_tratador( tratador_resp );

		std::cout << std::endl;
		std::cout << "\nDados alterados com sucesso\n" << std::endl;

	}
	else if( it_rep != m_tabela_reptil.end() )
	{
		std::string aux;
		std::string _nome;
		float		_tamanho;
		std::string _dieta;
		int 		_id_veterinario;
		int			_id_tratador;

		Funcionario * veterinario_resp = nullptr;
		Funcionario * tratador_resp = nullptr;

		std::cout << *(it_rep -> second);

		std::cout << "\nLista dos dasdos que podem ser alterados:  ";
		std::cout << "Nome, Tamanho, Dieta, Veterinario, Tratador" << std::endl;
		std::cout << "\n>>>>>	Digite os novos dados	<<<<<\n" << std::endl;
		std::cout << "\nNome: ";
		std::getline(std::cin, _nome);

		std::cout << "\nTamanho: ";
		std::getline(std::cin, aux);
		_tamanho = std::stof(aux);

		std::cout << "\nDieta: ";
		std::getline(std::cin, _dieta);

		std::cout << "\nID do Veterinario: ";
		std::getline(std::cin, aux);
		_id_veterinario = std::stoi(aux);

		std::cout << "\nID do Tratador:  ";
		std::getline(std::cin, aux);
		_id_tratador = std::stoi(aux);

		it_rep -> second -> set_nome( _nome );
		it_rep -> second -> set_tamanho( _tamanho );
		it_rep -> second -> set_dieta( _dieta );

		if( m_tabela_funcionario.find( _id_tratador ) != m_tabela_funcionario.end() )
			tratador_resp = m_tabela_funcionario[ _id_tratador ];

		if( m_tabela_funcionario.find( _id_veterinario ) != m_tabela_funcionario.end() )
			veterinario_resp = m_tabela_funcionario[ _id_veterinario ];

		it_rep -> second -> set_veterinario( veterinario_resp );
		it_rep -> second -> set_tratador( tratador_resp );

		std::cout << std::endl;
		std::cout << "\nDados alterados com sucesso\n" << std::endl;

	}

	else if( it_ave != m_tabela_ave.end() )
	{
		std::string aux;
		std::string _nome;
		float		_tamanho;
		std::string _dieta;
		int 		_id_veterinario;
		int			_id_tratador;
		float		_tamanho_bico;
		float		_envergadura;

		Funcionario * veterinario_resp = nullptr;
		Funcionario * tratador_resp = nullptr;

		std::cout << *(it_ave -> second);

		std::cout << "\nLista dos dasdos que podem ser alterados:  ";
		std::cout << "Nome, Tamanho, Dieta, Veterinario, Tratador, Tamanho do Bico, Envergadura" << std::endl;
		std::cout << "\n>>>>>	Digite os novos dados	<<<<<\n" << std::endl;
		std::cout << "\nNome: ";
		std::getline(std::cin, _nome);

		std::cout << "\nTamanho: ";
		std::getline(std::cin, aux);
		_tamanho = std::stof(aux);

		std::cout << "\nDieta: ";
		std::getline(std::cin, _dieta);

		std::cout << "\nID do Veterinario: ";
		std::getline(std::cin, aux);
		_id_veterinario = std::stoi(aux);

		std::cout << "\nID do Tratador:  ";
		std::getline(std::cin, aux);
		_id_tratador = std::stoi(aux);

		std::cout << "\nTamanho do Bico:  ";
		std::getline(std::cin, aux);
		_tamanho_bico = std::stof(aux);

		std::cout << "\nEnvergadura:  ";
		std::getline(std::cin, aux);
		_envergadura = std::stof(aux);

		it_ave -> second -> set_nome( _nome );
		it_ave -> second -> set_tamanho( _tamanho );
		it_ave -> second -> set_dieta( _dieta );

		if( m_tabela_funcionario.find( _id_tratador ) != m_tabela_funcionario.end() )
			tratador_resp = m_tabela_funcionario[ _id_tratador ];

		if( m_tabela_funcionario.find( _id_veterinario ) != m_tabela_funcionario.end() )
			veterinario_resp = m_tabela_funcionario[ _id_veterinario ];

		it_ave -> second -> set_veterinario( veterinario_resp );
		it_ave -> second -> set_tratador( tratador_resp );

		it_ave -> second -> set_tamanho_bico( _tamanho_bico );
		it_ave -> second -> set_envergadura( _envergadura );

		std::cout << std::endl;
		std::cout << "\nDados alterados com sucesso\n" << std::endl;

	} else
		std::cout << "\nAnimal nao encontrado\n" << std::endl;

}

void Pet_Fera_Cadastro::alterar_dados_funcionarios( int _id )
{
	std::map< int, Funcionario* >::iterator it_func =  m_tabela_funcionario.find( _id );

	if( it_func != m_tabela_funcionario.end() )
	{

		int _idade;

		std::cout << "\nLista dos dasdos que podem ser alterados:  Idade" << std::endl;
		std::cout << "\n>>>>>	Digite os novos dados	<<<<<\n" << std::endl;
		std::cout << "\nIdade: ";
		std::cin >> _idade;

		it_func -> second -> set_idade( _idade );

		std::cout << std::endl;
		std::cout << "\nDados alterados com sucesso\n" << std::endl;

	}else
		std::cout << "Funcionario nao encontrado" << std::endl;	

}

void Pet_Fera_Cadastro::importar_dados_animais( std::ifstream& dados_animais )
{
	std::string linha;
	std::vector< std::string > campos;
	std::getline(dados_animais, linha);
	if (linha != "ID;Classe;Tipo;Nome;Nome Cientifico;Sexo;Tamanho;Dieta;Veterinario;Tratador;Batismo;Tamanho do Bico;Envergadura;Total Mudas;Ultima Muda;Cor do Pelo;Venenoso;Tipo Veneno;Ibama;UF / Pais;Autorizacao")
	{
		throw ErroHeaderCSV();
	}
	while( std::getline( dados_animais, linha))
	{
		if(linha == "")
		{
			continue;
		}
		campos = separar( linha,';' );

		Funcionario* veterinario	= nullptr;
		Funcionario* tratador		= nullptr;

		for (std::map<int, Funcionario*>::iterator it = m_tabela_funcionario.begin(); it != m_tabela_funcionario.end(); ++it)
		{
			if( it->second->get_id() == std::stoi(campos[8]) )
			{
				veterinario = it->second;
			}

			if( it->second->get_id() == std::stoi(campos[9]) )
			{
				tratador = it->second;
			}
		}

		if( campos[1] == "Amphibia" and campos[2] == "Domestico" )
		{
			m_tabela_anfibio.insert( std::pair<int, Anfibio*>(std::stoi(campos[0]), new Anfibio( std::stoi(campos[0]),
			campos[1], campos[2], campos[3], campos[4], campos[5][0], std::stof(campos[6]),
			campos[7], veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0,
			campos[10], std::stoi(campos[13]), campos[14] ) ) );
		}
		else if( campos[1] == "Amphibia" and campos[2] == "Exotico" )
		{
			m_tabela_anfibio.insert( std::pair<int, Anfibio*>(std::stoi(campos[0]), new AnfibioExotico( std::stoi(campos[0]),
			campos[1], campos[2], campos[3], campos[4], campos[5][0], std::stof(campos[6]),
			campos[7], veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0,
			campos[10], std::stoi(campos[13]), campos[14], campos[18], campos[19]  ) ) );
		}
		else if( campos[1] == "Amphibia" and campos[2] == "Nativo")
		{
			m_tabela_anfibio.insert( std::pair<int, Anfibio*>(std::stoi(campos[0]), new AnfibioNativo( std::stoi(campos[0]),
			campos[1], campos[2], campos[3], campos[4], campos[5][0], std::stof(campos[6]),
			campos[7], veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0,
			campos[10], std::stoi(campos[13]), campos[14], campos[18], campos[19], campos[20] ) ) );
		}
		else if( campos[1] == "Mammalia" and campos[2] == "Domestico" )
		{
			m_tabela_mamifero.insert( std::pair<int, Mamifero*>(std::stoi(campos[0]), new Mamifero( std::stoi(campos[0]),
			campos[1], campos[2], campos[3], campos[4], campos[5][0], std::stof(campos[6]),
			campos[7], veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0,
			campos[10], campos[15] ) ) );
		}
		else if( campos[1] == "Mammalia" and campos[2] == "Exotico")
		{
			m_tabela_mamifero.insert( std::pair<int, Mamifero*>(std::stoi(campos[0]), new MamiferoExotico( std::stoi(campos[0]),
			campos[1], campos[2], campos[3], campos[4], campos[5][0], std::stof(campos[6]),
			campos[7], veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0,
			campos[10], campos[15], campos[18], campos[19]  ) ) );
		}
		else if( campos[1] == "Mammalia" and campos[2] == "Nativo")
		{
			m_tabela_mamifero.insert( std::pair<int, Mamifero*>(std::stoi(campos[0]), new MamiferoNativo( std::stoi(campos[0]),
			campos[1], campos[2], campos[3], campos[4], campos[5][0], std::stof(campos[6]),
			campos[7], veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0,
			campos[10], campos[15], campos[18], campos[19], campos[20]  ) ) );
		}
		else if( campos[1] == "Reptilia" and campos[2] == "Domestico" )
		{
			m_tabela_reptil.insert(	std::pair<int, Reptil*>(std::stoi(campos[0]), new Reptil( std::stoi(campos[0]),
			campos[1], campos[2], campos[3], campos[4], campos[5][0], std::stof(campos[6]),
			campos[7], veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0,
			campos[10], campos[16]=="Sim", campos[17] ) ) );
		}
		else if( campos[1] == "Reptilia" and campos[2] == "Exotico")
		{
			m_tabela_reptil.insert(	std::pair<int, Reptil*>(std::stoi(campos[0]), new ReptilExotico( std::stoi(campos[0]),
			campos[1], campos[2], campos[3], campos[4], campos[5][0], std::stof(campos[6]),
			campos[7], veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0,
			campos[10], campos[16]=="Sim", campos[17], campos[18], campos[19]  ) ) );
		}
		else if( campos[1] == "Reptilia" and campos[2] == "Nativo")
		{
			m_tabela_reptil.insert( std::pair<int, Reptil*>(std::stoi(campos[0]), new ReptilNativo( std::stoi(campos[0]),
			campos[1], campos[2], campos[3], campos[4], campos[5][0], std::stof(campos[6]),
			campos[7], veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0,
			campos[10], campos[16]=="Sim", campos[17], campos[18], campos[19], campos[20] ) ) );
		}
		else if( campos[1] == "Aves" and campos[2] == "Domestico" )
		{
			m_tabela_ave.insert( std::pair<int, Ave*>(std::stoi(campos[0]), new Ave( std::stoi(campos[0]),
			campos[1], campos[2], campos[3], campos[4], campos[5][0], std::stof(campos[6]),
			campos[7], veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0,
			campos[10], std::stof(campos[11]), std::stof(campos[12]) ) ) );
		}
		else if( campos[1] == "Aves" and campos[2] == "Exotico")
		{
			m_tabela_ave.insert( std::pair<int, Ave*>(std::stoi(campos[0]), new AveExotico( std::stoi(campos[0]),
			campos[1], campos[2], campos[3], campos[4], campos[5][0], std::stof(campos[6]),
			campos[7], veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0,
			campos[10], std::stof(campos[11]), std::stof(campos[12]), campos[18], campos[19] ) ) );
		}				
		else if( campos[1] == "Aves" and campos[2] == "Nativo")
		{
			m_tabela_ave.insert( std::pair<int, Ave*>(std::stoi(campos[0]), new AveNativo( std::stoi(campos[0]),
			campos[1], campos[2], campos[3], campos[4], campos[5][0], std::stof(campos[6]),
			campos[7], veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0,
			campos[10], std::stof(campos[11]), std::stof(campos[12]), campos[18], campos[19], campos[20] ) ) );
		}
		else
		{
			throw ErroLeituraCSVAnimal();
		}
	}
}

void Pet_Fera_Cadastro::importar_dados_funcionarios( std::ifstream& dados_funcionarios )
{
	std::string linha;
	std::vector< std::string > campos;
	std::getline(dados_funcionarios, linha);
	if (linha != "ID;Profissao;Nome;CPF;Idade;Tipo Sanguineo;Fator RH;Especialidade")
	{
		throw ErroHeaderCSV();
	}
	while( std::getline( dados_funcionarios, linha))
	{
		if(linha == "")
		{
			continue;
		}
		campos = separar( linha,';' );

		if(campos[1] == "Veterinario")
		{
			m_tabela_funcionario.insert( std::pair<int, Veterinario*>(std::stoi(campos[0]),
			new Veterinario( std::stoi(campos[0]), campos[1], campos[2], campos[3],
			(short)std::stoi(campos[4]), campos[5], campos[6][0], campos[7] ) ) );
		}
		else if(campos[1] == "Tratador")
		{
			m_tabela_funcionario.insert( std::pair<int, Tratador*>(std::stoi(campos[0]),
			new Tratador( std::stoi(campos[0]), campos[1], campos[2], campos[3],
			(short)std::stoi(campos[4]), campos[5], campos[6][0], campos[7] ) ) );
		}
		else
		{
			throw ErroLeituraCSVFunc();
		}
	}
}

template < typename T >
std::string Pet_Fera_Cadastro::to_string( T target )
{
	std::stringstream ss;
	ss << target;
	return ss.str();
}

void Pet_Fera_Cadastro::exportar_dados_animais( std::ofstream& dados_animais )
{
	dados_animais << "ID;Classe;Tipo;Nome;Nome Cientifico;Sexo;Tamanho;Dieta;Veterinario;Tratador;Batismo;Tamanho do Bico;Envergadura;Total Mudas;Ultima Muda;Cor do Pelo;Venenoso;Tipo Veneno;Ibama;UF / Pais;Autorizacao" << std::endl;
	std::string linha;
	std::vector< std::string > campos;

	for ( auto it = m_tabela_anfibio.begin(); it != m_tabela_anfibio.end(); ++it )
	{
		campos.clear();
		campos.push_back(to_string(it->second->get_id()));		// 0
		campos.push_back(it->second->get_classe());				// 1
		campos.push_back(it->second->get_tipo());				// 2
		campos.push_back(it->second->get_nome());				// 3
		campos.push_back(it->second->get_cientifico());			// 4
		campos.push_back(to_string(it->second->get_sexo()));	// 5
		campos.push_back(to_string(it->second->get_tamanho()));	// 6
		campos.push_back(it->second->get_dieta());				// 7
		if (it->second->get_veterinario() == nullptr)			// 8
			campos.push_back("0");
		else
			campos.push_back(to_string(it->second->get_veterinario()->get_id()));
		if (it->second->get_tratador() == nullptr)				// 9
			campos.push_back("0");
		else
			campos.push_back(to_string(it->second->get_tratador()->get_id()));
		campos.push_back(it->second->get_batismo());				// 10

		if (campos[1] == "Amphibia")
		{
			campos.push_back("-");										// 11
			campos.push_back("-");										// 12
			campos.push_back(to_string(it->second->get_total_mudas()));	// 13
			campos.push_back(to_string(it->second->get_ultima_muda()));	// 14
			campos.push_back("-");										// 15
			campos.push_back("-");										// 16
			campos.push_back("-");										// 17

			if (campos[2] == "Exotico")
			{
				AnfibioExotico* temp = ((AnfibioExotico*)(it->second));

				campos.push_back(temp->get_ibama());		// 18
				campos.push_back(temp->get_pais_origem());	// 19
				campos.push_back("-");						// 20
			}
			else if (campos[2] == "Nativo")
			{
				AnfibioNativo* temp = ((AnfibioNativo*)(it->second));

				campos.push_back(temp->get_ibama());		// 18
				campos.push_back(temp->get_uf_origem());	// 19
				campos.push_back(temp->get_autorizacao());	// 20
			}
			else if (campos[2] == "Domestico" )
			{
				campos.push_back("-");							// 18
				campos.push_back("-");							// 19
				campos.push_back("-");							// 20
			}
		}

		linha.clear();
		for (auto i = campos.begin(); i != campos.end(); ++i)
		{
			linha += *i + ";";
		}
		dados_animais << linha << std::endl;
	}
	campos.clear();
	for ( auto it = m_tabela_mamifero.begin(); it != m_tabela_mamifero.end(); ++it )
	{
		campos.clear();
		campos.push_back(to_string(it->second->get_id()));		// 0
		campos.push_back(it->second->get_classe());				// 1
		campos.push_back(it->second->get_tipo());				// 2
		campos.push_back(it->second->get_nome());				// 3
		campos.push_back(it->second->get_cientifico());			// 4
		campos.push_back(to_string(it->second->get_sexo()));		// 5
		campos.push_back(to_string(it->second->get_tamanho()));	// 6
		campos.push_back(it->second->get_dieta());				// 7
		if (it->second->get_veterinario() == nullptr)			// 8
			campos.push_back("0");
		else
			campos.push_back(to_string(it->second->get_veterinario()->get_id()));
		if (it->second->get_tratador() == nullptr)				// 9
			campos.push_back("0");
		else
			campos.push_back(to_string(it->second->get_tratador()->get_id()));
		campos.push_back(it->second->get_batismo());				// 10

		if ( campos[1] == "Mammalia")
		{
			campos.push_back("-");							// 11
			campos.push_back("-");							// 12
			campos.push_back("-");							// 13
			campos.push_back("-");							// 14
			campos.push_back(it->second->get_cor_pelo());	// 15
			campos.push_back("-");							// 16
			campos.push_back("-");							// 17
			if (campos[2] == "Exotico")
			{
				MamiferoExotico* temp = ((MamiferoExotico*)(it->second));
				campos.push_back(temp->get_ibama());		// 18
				campos.push_back(temp->get_pais_origem());	// 19
				campos.push_back("-");							// 20
			}
			else if (campos[2] == "Nativo")
			{
				MamiferoNativo* temp = ((MamiferoNativo*)(it->second));
				campos.push_back(temp->get_ibama());		// 18
				campos.push_back(temp->get_uf_origem());	// 19
				campos.push_back(temp->get_autorizacao());	// 20
			}
			else if (campos[2] == "Domestico" )
			{
				campos.push_back("-");							// 18
				campos.push_back("-");							// 19
				campos.push_back("-");							// 20
			}
		}

		linha.clear();
		for (auto i = campos.begin(); i != campos.end(); ++i)
		{
			linha += *i + ";";
		}
		dados_animais << linha << std::endl;
	}
	campos.clear();
	for ( auto it = m_tabela_reptil.begin(); it != m_tabela_reptil.end(); ++it )
	{
		campos.clear();
		campos.push_back(to_string(it->second->get_id()));		// 0
		campos.push_back(it->second->get_classe());				// 1
		campos.push_back(it->second->get_tipo());				// 2
		campos.push_back(it->second->get_nome());				// 3
		campos.push_back(it->second->get_cientifico());			// 4
		campos.push_back(to_string(it->second->get_sexo()));		// 5
		campos.push_back(to_string(it->second->get_tamanho()));	// 6
		campos.push_back(it->second->get_dieta());				// 7
		if (it->second->get_veterinario() == nullptr)			// 8
			campos.push_back("0");
		else
			campos.push_back(to_string(it->second->get_veterinario()->get_id()));
		if (it->second->get_tratador() == nullptr)				// 9
			campos.push_back("0");
		else
			campos.push_back(to_string(it->second->get_tratador()->get_id()));
		campos.push_back(it->second->get_batismo());				// 10

		if ( campos[1] == "Reptilia")
		{
			campos.push_back("-");										// 11
			campos.push_back("-");										// 12
			campos.push_back("-");										// 13
			campos.push_back("-");										// 14
			campos.push_back("-");										// 15
			campos.push_back((it->second->is_venenoso() ? "Sim":"Nao")); // 16
			campos.push_back(it->second->get_tipo_veneno());				// 17
			if (campos[2] == "Exotico")
			{
				ReptilExotico* temp = ((ReptilExotico*)(it->second));
				campos.push_back(temp->get_ibama());		// 18
				campos.push_back(temp->get_pais_origem());	// 19
				campos.push_back("-");							// 20
			}
			else if (campos[2] == "Nativo")
			{
				ReptilNativo* temp = ((ReptilNativo*)(it->second));
				campos.push_back(temp->get_ibama());		// 18
				campos.push_back(temp->get_uf_origem());	// 19
				campos.push_back(temp->get_autorizacao());	// 20
			}
			else if (campos[2] == "Domestico" )
			{
				campos.push_back("-");							// 18
				campos.push_back("-");							// 19
				campos.push_back("-");							// 20
			}
		}

		linha.clear();
		for (auto i = campos.begin(); i != campos.end(); ++i)
		{
			linha += *i + ";";
		}
		dados_animais << linha << std::endl;
	}
	campos.clear();
	for ( auto it = m_tabela_ave.begin(); it != m_tabela_ave.end(); ++it )
	{
		campos.clear();
		campos.push_back(to_string(it->second->get_id()));		// 0
		campos.push_back(it->second->get_classe());				// 1
		campos.push_back(it->second->get_tipo());				// 2
		campos.push_back(it->second->get_nome());				// 3
		campos.push_back(it->second->get_cientifico());			// 4
		campos.push_back(to_string(it->second->get_sexo()));		// 5
		campos.push_back(to_string(it->second->get_tamanho()));	// 6
		campos.push_back(it->second->get_dieta());				// 7
		if (it->second->get_veterinario() == nullptr)			// 8
			campos.push_back("0");
		else
			campos.push_back(to_string(it->second->get_veterinario()->get_id()));
		if (it->second->get_tratador() == nullptr)				// 9
			campos.push_back("0");
		else
			campos.push_back(to_string(it->second->get_tratador()->get_id()));
		campos.push_back(it->second->get_batismo());				// 10

		if ( campos[1] == "Aves")
		{
			campos.push_back(to_string(it->second->get_tamanho_bico()));// 11
			campos.push_back(to_string(it->second->get_envergadura()));	// 12
			campos.push_back("-");										// 13
			campos.push_back("-");										// 14
			campos.push_back("-");										// 15
			campos.push_back("-");										// 16
			campos.push_back("-");										// 17

			if (campos[2] == "Exotico")
			{
				AveExotico* temp = ((AveExotico*)(it->second));
				campos.push_back(temp->get_ibama());			// 18
				campos.push_back(temp->get_pais_origem());	// 19
				campos.push_back("-");								// 20
			}
			else if (campos[2] == "Nativo")
			{
				AveNativo* temp = ((AveNativo*)(it->second));
				campos.push_back(temp->get_ibama());			// 18
				campos.push_back(temp->get_uf_origem());		// 19
				campos.push_back(temp->get_autorizacao());	// 20
			}
			else if (campos[2] == "Domestico" )
			{
				campos.push_back("-");							// 18
				campos.push_back("-");							// 19
				campos.push_back("-");							// 20
			}
		}

		linha.clear();
		for (auto i = campos.begin(); i != campos.end(); ++i)
		{
			linha += *i + ";";
		}
		dados_animais << linha << std::endl;
	}
	campos.clear();
}

void Pet_Fera_Cadastro::exportar_dados_funcionarios( std::ofstream& dados_funcionarios )
{
	dados_funcionarios << "ID;Profissao;Nome;CPF;Idade;Tipo Sanguineo;Fator RH;Especialidade" << std::endl;
	std::string linha;
	std::vector< std::string > campos;

	for ( auto it = m_tabela_funcionario.begin(); it != m_tabela_funcionario.end(); ++it )
	{
		campos.clear();
		campos.push_back(to_string(it->second->get_id()));		// 0
		campos.push_back(it->second->get_funcao());				// 1
		campos.push_back(it->second->get_nome());				// 2
		campos.push_back(it->second->get_CPF());				// 3
		campos.push_back(to_string(it->second->get_idade()));	// 4
		campos.push_back(it->second->get_t_sangue());			// 5
		campos.push_back(to_string(it->second->get_RH()));		// 6
		campos.push_back(it->second->get_espec());				// 7

		linha.clear();
		for (auto i = campos.begin(); i != campos.end(); ++i)
		{
			linha += *i + ";";
		}
		dados_funcionarios << linha << std::endl;
	}
}


unsigned int Pet_Fera_Cadastro::quantidade_animais_cadastrados( void )
{

	return ( m_tabela_anfibio.size() + m_tabela_mamifero.size() + m_tabela_reptil.size() + m_tabela_ave.size() );

}

unsigned int Pet_Fera_Cadastro::quantidade_funcionarios_cadastrados( void )
{
	return m_tabela_funcionario.size();
}

