
# Sistema de Gerenciamento de Tarefas

Este programa permite gerenciar tarefas de forma simples. Com ele, é possível cadastrar, listar, editar, excluir e salvar tarefas em um arquivo de texto. O programa oferece um menu interativo para realizar essas ações e armazena os dados das tarefas em um arquivo chamado `tarefas.txt`.

## Funcionalidades

- **Cadastrar tarefas** com título, descrição, prioridade e status.
- **Listar tarefas** cadastradas.
- **Editar tarefas** existentes.
- **Excluir tarefas**.
- **Salvar tarefas em um arquivo** chamado `tarefas.txt`.

## Como compilar e executar o programa

### Passo 1: Compilar o código
Para compilar o programa, você precisa usar o **GDB** com o **GCC**. Use o seguinte comando no terminal:

```bash
gcc -g main.c -o sistema_tarefas
```

- A opção `-g` permite gerar informações de depuração necessárias para o **GDB**.
- O `-o sistema_tarefas` especifica o nome do executável que será gerado.

### Passo 2: Executar o programa com o GDB
Depois de compilar, você pode executar o programa no **GDB** para depurar o código e monitorar o funcionamento do programa:

```bash
gdb ./sistema_tarefas
```

Dentro do **GDB**, você pode rodar o programa com o comando:

```bash
run
```

### Passo 3: Executar o programa diretamente
Caso não queira usar o **GDB** para depuração e apenas queira rodar o programa, use o seguinte comando no terminal:

```bash
./sistema_tarefas
```

Isso vai executar o programa normalmente, sem passar pelo **GDB**.

## Como funciona o programa

1. Ao rodar o programa, você verá um menu interativo com as opções para cadastrar, listar, editar, excluir e salvar tarefas.
2. O programa armazena as tarefas em um arquivo de texto chamado `tarefas.txt`, onde cada tarefa é salva com título, descrição, prioridade e status.

## Exemplo de uso

Após salvar algumas tarefas, o arquivo `tarefas.txt` será gerado e pode ter o seguinte formato:

```txt
Tarefa 1:
Título: Estudar para a prova de C
Descrição: Revisar os conceitos de ponteiros e alocação dinâmica.
Prioridade: Alta
Status: Pendente

Tarefa 2:
Título: Codificar o sistema de tarefas
Descrição: Implementar a funcionalidade de cadastrar e listar tarefas.
Prioridade: Média
Status: Concluído
```

## Licença

Este projeto é de código aberto e pode ser utilizado livremente.
