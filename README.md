# LPA - Trabalho B1

## 1. Título do projeto
Sistema de Simulador de Entregas

## 2. Objetivo
O projeto tem como objetivo desenvolver um programa em linguagem C para simular o cálculo do valor de entregas.

O sistema recebe informações como distância, peso, modalidade de entrega, serviço de proteção e quantidade de tentativas adicionais. A partir desses dados, são calculados os valores da entrega e apresentado um resumo final da sessão.

## 3. Funcionalidades
- Cálculo do valor-base da entrega conforme a faixa de distância.
- Cálculo do adicional de peso sobre o subtotal inicial.
- Cálculo do adicional de modalidade (Econômica, Expressa, Prioritária) sobre o subtotal inicial.
- Cobrança de serviço adicional de proteção, quando contratado.
- Cobrança de tentativas adicionais de entrega.
- Validação de todas as entradas de domínio (distância, peso, modalidade, proteção, tentativas e opção de continuar).
- Processamento de múltiplas entregas em uma mesma sessão.
- Resumo final com total de entregas, valor total, valor médio, quantidade por modalidade, maior e menor valor de entrega.

## 4. Organização da solução
O programa foi dividido em quatro funções além da `main`:
- `calcular_valor_base`: identifica o valor-base da entrega conforme a faixa de distância.
- `calcular_adicional_peso`: calcula o adicional percentual de peso sobre o subtotal inicial.
- `calcular_adicional_modalidade`: calcula o adicional percentual da modalidade escolhida sobre o subtotal inicial.
- `calcular_valor_final`: soma todas as parcelas (subtotal, adicionais, proteção e tentativas) para obter o valor final da entrega.

A função `main` é responsável por coordenar o fluxo: solicitar e validar as entradas, chamar as funções de cálculo, exibir o resultado de cada entrega, atualizar os contadores e acumuladores do resumo, e controlar a repetição do processamento até o usuário optar por encerrar a sessão.

## 5. Compilação
No terminal, dentro da pasta onde está o arquivo `main.c`, execute:

gcc main.c -o simulador

Também é possível compilar utilizando um ambiente como Code::Blocks ou VS Code com extensão de C instalada.

## 6. Como executar
Para executar o programa:
1. Compile o arquivo `main.c` conforme instruções acima.
2. Execute o programa gerado pelo terminal:

./simulador

(No Windows, o executável pode ser `simulador.exe`.)
3. Informe os dados solicitados pelo sistema (distância, peso, modalidade, proteção e tentativas adicionais).
4. Ao final de cada entrega, escolha se deseja processar outra ou encerrar a sessão.

O programa solicita os dados de cada entrega e permite processar várias entregas na mesma execução.

## 7. Uso de Inteligência Artificial
Utilizei a ferramenta Claude (Anthropic) como apoio para tirar dúvidas sobre o processo de versionamento e organização do repositório no GitHub, conteúdo que não foi abordado em aula. Não utilizei IA para gerar a lógica de programação ou os cálculos do trabalho, que foram desenvolvidos por mim.

**Finalidade:** entender como criar um repositório, estruturar pastas, e fazer commits progressivos representando etapas reais de desenvolvimento.

**Exemplos de prompts utilizados:** "como faço para criar um repositório e subir meu código com commits separados por etapa" e "como divido meu código em commits que façam sentido".

**Sugestões aproveitadas:** a estrutura de pastas sugerida, os comandos de Git (clone, add, commit, push) e a divisão dos commits em etapas do desenvolvimento.

Nenhuma alteração de lógica ou cálculo foi feita com base em sugestões de IA, apenas o processo de organização e envio do repositório.

## 8. Fontes consultadas
Não foram utilizadas fontes externas além do material da disciplina e da documentação oficial do Git/GitHub.
