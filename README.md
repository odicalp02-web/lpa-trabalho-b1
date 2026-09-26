# LPA - Trabalho B1

## 1. Título do projeto

Sistema de Simulador de Entregas

## 2. Objetivo

O projeto tem como objetivo desenvolver um programa em linguagem C para simular o cálculo do valor de entregas.

O sistema recebe informações como distância, peso, modalidade de entrega, serviço de proteção e quantidade de tentativas adicionais. A partir desses dados, são calculados os valores da entrega e apresentado um resumo final da sessão.

## 3. Como executar

Para executar o programa:

1. Abra o arquivo `main.c` em um compilador de C, como o Code::Blocks ou VS Code.
2. Compile o programa.
3. Execute o programa pelo terminal ou pelo ambiente de desenvolvimento.
4. Informe os dados solicitados pelo sistema.

O programa solicita os dados de cada entrega e permite processar várias entregas na mesma execução.

## 4. Exemplos de uso

Durante a execução, o programa solicita:

- Distância da entrega em quilômetros;
- Peso da entrega em quilogramas;
- Modalidade: Econômica, Expressa ou Prioritária;
- Se deseja contratar o serviço de proteção;
- Quantidade de tentativas adicionais.

Após o processamento, o programa apresenta o valor-base, o subtotal inicial e o valor final da entrega.

Ao encerrar a sessão, também são apresentados:

- Quantidade total de entregas;
- Valor total calculado;
- Valor médio das entregas;
- Quantidade de entregas por modalidade;
- Maior valor de entrega;
- Menor valor de entrega.

## 5. Decisões e aprendizados

Durante o desenvolvimento foram utilizadas funções para separar os principais cálculos do programa, facilitando a organização e a compreensão do código.

Também foram utilizados comandos condicionais para definir os valores conforme a distância, o peso e a modalidade escolhida.

As estruturas de repetição `do...while` foram utilizadas para validar os dados informados pelo usuário e evitar valores inválidos.

Outro aprendizado foi o uso de contadores e acumuladores para gerar o resumo final com os dados de todas as entregas processadas.

## 6. Autor

Plácido Santos
