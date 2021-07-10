# Algoritmo de Mapeamento

## Introdução:
O código desenvolvido é responsável pela implementação de um algoritmo de geração de rota para navegação em um polígono. Essa rota vai ser guardada na forma de pontos a serem seguido pelo VANT.

## Classe Point
Essa classe é responsável pela abstração computacional de um ponto, sendo seus principais atributos as coordenadas x, y e z do ponto. Os demais atributos não são usados na missão de mapeamento e se referem à implementação da missão de pathfinding do drone. Esses pontos vão servir como elementos de composição das arestas e dos vértices da área a ser mapeadas. As únicas funções utilizadas dessa classe são as de retorno (métodos “get”) das coordenadas x e y.

## Classe Aresta
Utilizando-se do conceito de composição, pode-se criar uma aresta passando dois pontos como parâmetros. A aresta formada por esses dois pontos vai possuir um coeficiente angular e um coeficiente linear, sendo esses responsáveis pela caracterização do segmento de reta que une os dois pontos. A função “void calcularCoeficiente()” utiliza das coordenadas dos pontos para realizar esses cálculos. Os demais métodos são de retorno, atualização e impressão.

## Classe Poligono
Utiliza-se composição de novo, já que um polígono é composto por vértices, sendo esses basicamente pontos. As arestas serão geradas a partir dos vértices passados como parâmetros em um “vector”. Além disso, outros atributos interessantes de um polígono são a sua área e sua convexidade, que serão determinados em métodos específicos.<br>
Além das usuais funções de retorno, alteração e exibição, tem-se as seguintes funções de geometria computacional:<br>
bool ehConvexo()  -> analisa-se três vértices consecutivos da seguinte forma: gera-se uma aresta entre o primeiro e o último e projeta-se o vértice do meio nessa aresta gerada. Avalia-se a coordenada “y” do ponto do meio com obtido pela projeção, o que nos permite deduzir a convexidade ou não desse trecho do polígono. Utilizando-se um laço de repetição, faz-se isso para todos os vértices e, caso todos satisfaçam a condição acima, é retornado “true”.<br>
bool contemPonto(Point ponto) -> se um ponto satisfaz a propriedade de estar projetado acima de uma aresta horizontal em que o segundo vértice está mais à  esquerda que o primeiro, à direita de uma aresta vertical cujo segundo vértice está mais abaixo, etc, consegue-se avaliar se o ponto pertence ou não ao polígono. Esse método só funciona corretamente em todos os casos possíveis se ele for chamado por objetos de Poligono que sejam convexos.<br>
void calcularArea() -> usando determinante de matrizes, consegue-se calcular a área de triângulos dada as coordenadas de seus 3 pontos. Essa função generaliza esse processo por um espécie de sucessivas triangulações, em que se calculado um “pseudo-determinante” para vários pontos. Os resultados apresentados mostraram-se corretos tanto para polígonos côncavos como para convexos.<br>

## Classe MissaoMapemamento
Essa classe recebe um polígono como parâmetro e executa uma das funções de mapeamento implementadas. Essas funções seguem um conjuntos de passos, que podem ser resumidos a seguir:
1.	Atualizar as arestas limitadoras por meio da avaliação de um parâmetro geométrico.
2.	Calcular limites da reta que irá gerar a atual linha de rota.
3.	Gerar pontos variando “x” e/ou “y” de acordo com a atual reta geradora de rota.
4.	Incrementar parâmetro da geração de reta (seja ele um “x”, um ”y” ou um coeficiente linear) e verificar condição de parada, podendo ou não retornar ao passo 1.

## Como usar o código:
Se o modo de mapeamento for 1, passam-se os vértices consecutivos da área a ser mapeada no sentido anti-horário e, além disso, deve-se passar primeiramente o vértice de menor coordenada “y”. Os pontos da rota serão exibidos na tela.<br>
Se o modo de mapeamento for 2, passam-se os vértices consecutivos da área a ser mapeada e escolhe-se um dos vértices para início do mapeamento. A rota é mostrada na tela.

## OpenGL:
Utilizando-se uma instância da classe MissaoMapeamento, é possível exibir a rota do drone pela área a ser mapeada. A explicação de cada uma dessas funções de exibição gráfica podem ser observadas no seguinte tutorial:
https://www.inf.pucrs.br/~manssour/OpenGL/Desenhando.html
